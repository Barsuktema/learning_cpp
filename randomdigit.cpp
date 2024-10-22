#include "additional.h"
#include <iostream>
#include <cstdlib>
#include <ctime>
#include <fstream>
#include <string>


int RandomCalc(int level) {
	int max_value = 10;
	switch(level) {
		case 1:
			max_value = 10;
		case 2:
			max_value = 50;
		case 3:
			max_value = 100;
	};
	std::srand(std::time(nullptr));
	int value = std::rand() % max_value;
	return value;
}

int TestDigit(int rvalue,int qvalue) {
	if (rvalue == qvalue) {
		std::cout << "Right Bro" << std::endl;
		return 0;
	} else if (rvalue < qvalue) {
		std::cout << "Please input less digit" << std::endl;
		return 1;
	} else if (rvalue > qvalue) {
		std::cout << "Please input more digit" << std::endl;
		return 1;
	}
	return 1;
} 

int Counter(int count) {
	count += 1;
	return count;
}

void Records(std::string name, int count) {
		std::ofstream fs("Records.txt", std::ios::app);
		std::string count_str = std::to_string(count);
		if (fs)	{
			fs << "Name:" + name + " | Count:" + count_str + "\n";
			fs.close();
		} 
}

void RecordsOut() {
	std::fstream fsi;
	fsi.open("Records.txt", std::fstream::in);
	std::string line;
	while (std::getline(fsi, line))
		std::cout << line << std::endl;
	fsi.close();
}
