#include <iostream>
#include <string>
#include "additional.h"


int main(int argc, char *argv[]) {
    bool l = false;
    bool t = false;
    int level = 1;
    if (argc==1) {
        std::cerr << "Usage:\n -l integer (1-level(0-9),2-level(0-49),3-level(0-99)\n -t parameter for output records table\n";
        return 1;
    }
    for (int i = 1; i < argc; i++) {
        std::string cmd{ argv[i] };
        if (cmd == "-l") {
            level = std::stoi(argv[i+1]);
            if (level < 1 || level >3)  {
                std::cerr << "Usage:\n -l integer (1-level(0-9),2-level(0-49),3-level(0-99)\n -t parameter for output records table\n";
                return 1;
            } else {
                std::cout << "ok";
                l = true;
            }
        }
        if ((cmd == "-t")) {
                t = true;
            }
    }
    if (t == true) {
        RecordsOut();
        if (l == false) {
            return 0;
        }
    }
    if (l == true) {
                int check = 1;
                int count = 0;
                std::string name;
                int rvalue, qvalue;
                std::cout << "Input your name: ";
                std::cin >> name;
                rvalue = RandomCalc(level);

                while (check ==1) {
                    std::cout << "Dear " + name + ", please input your digit: ";
                    std::cin >> qvalue;
                    check = TestDigit(rvalue,qvalue);
                    count = Counter(count);
                    if (check==0) {
                    std::cout << "Try counter:";
                    std::cout << count;
                    Records(name, count);
                    }
                }
                return 0;
            }
    } 


