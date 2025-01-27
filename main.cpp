#include <algorithm>
#include <iostream>
#include <limits>
#include <vector>
#include <thread>
#include <atomic>


#include "CRC32.hpp"
#include "IO.hpp"
std::vector<char> badData;
/// @brief Переписывает последние 4 байта значением value
void replaceLastFourBytes(std::vector<char> &data, uint32_t value) {
  std::copy_n(reinterpret_cast<const char *>(&value), 4, data.end() - 4);
}

/**
 * @brief Формирует новый вектор с тем же CRC32, добавляя в конец оригинального
 * строку injection и дополнительные 4 байта
 * @details При формировании нового вектора последние 4 байта не несут полезной
 * нагрузки и подбираются таким образом, чтобы CRC32 нового и оригинального
 * вектора совпадали
 * @param original оригинальный вектор
 * @param injection произвольная строка, которая будет добавлена после данных
 * оригинального вектора
 * @return новый вектор
 */
 void hack(const std::vector<char> &original,
                       const std::string &injection, const size_t begin, const size_t end, const char* path) {
  const uint32_t originalCrc32 = crc32(original.data(), original.size(), 0xFFFFFFFF);
  std::vector<char> result(original.size() + injection.size() + 4);
  auto it = std::copy(original.begin(), original.end(), result.begin());
  std::copy(injection.begin(), injection.end(), it);

  /*
   * Внимание: код ниже крайне не оптимален.
   * В качестве доп. задания устраните избыточные вычисления
   */
  for (size_t i = begin; i < end; ++i) {
    // Заменяем последние четыре байта на значение i
    replaceLastFourBytes(result, uint32_t(i));
    // Вычисляем CRC32 текущего вектора result
    auto currentCrc32 = crc32(result.data() + original.size(), injection.size() + 4, originalCrc32);
    if (currentCrc32 == originalCrc32) {
      std::cout << "Success\n";
      badData = result;
      writeToFile(path, badData);
      exit(0);
    }
    // Отображаем прогресс
    if (i % 1000 == 0) {
      std::cout << "progress: "
                << static_cast<double>(i)/ static_cast<double>(end)
                << std::endl;
    }
  }
  // throw std::logic_error("Can't hack");
}

int main(int argc, char **argv) {
  if (argc != 3) {
    std::cerr << "Call with two args: " << argv[0]
              << " <input file> <output file>\n";
    return 1;
  }


  size_t n_threads = std::thread::hardware_concurrency()/2;
  const size_t maxVal = std::numeric_limits<uint32_t>::max();
  size_t part = maxVal / n_threads;

  try {

    const std::vector<char> data = readFromFile(argv[1]);
    std::vector<std::thread> ths;
    for (std::size_t j = 0; j < n_threads; ++j){
      ths.push_back(std::thread(hack, data, "He-he-he", j * part, (j+1) * part, argv[2]));
    }
    for (auto & th : ths)
      th.join();


  } catch (std::exception &ex) {
    std::cerr << ex.what() << '\n';
    return 2;
  }
  return 0;
}
