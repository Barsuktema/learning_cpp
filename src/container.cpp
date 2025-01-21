#include "container.hpp"
#include <string> 
#include <vector>

int main()
{
    std::cout << "Array Container" << "\n";
    Array<int> test;
    test.push_back(0);
    test.push_back(1);
    test.push_back(2);
    test.push_back(3);
    test.push_back(4);
    test.push_back(5);
    test.push_back(6);
    test.push_back(7);
    test.push_back(8);
    test.push_back(9);
    test.print();
    test.size();
    test.erase(2);
    test.erase(3);
    test.erase(4);
    test.print();
    int b = 1;
    int a = test[b];
    std::cout << "element number " << b+1 << ": " << a << "\n";
    test.insert(10,0);  
    test.print();
    int size = test.size();
    std::cout << "size: "<< size << "\n";
    test.insert(20,size/2);  
    test.print();
    test.insert(30,9); 
    test.print();

    std::cout << "List Container" << "\n";
    List<int> test2;
    test2.push_back(0);
    test2.push_back(1);
    test2.push_back(2);
    test2.push_back(3);
    test2.push_back(4);
    test2.push_back(5);
    test2.push_back(6);
    test2.push_back(7);
    test2.push_back(8);
    test2.push_back(9);
    test2.print();
    size = test2.size();
    std::cout << "size: "<< size << "\n";
    int c = 3;
    int d = test2[c];
    std::cout << "element number " << c+1 << ": " << d << "\n";
    test2.erase(2);
    test2.erase(3);
    test2.erase(4);
    test2.print();
    test2.insert(10,0); 
    test2.print();
    size = test2.size();
    std::cout << "size: "<< size << "\n";
    test2.insert(30,size);
    test2.print();
    test2.insert(20,size/2);
    test2.print();

}
