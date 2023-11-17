#include <iostream>
#include "functions.h"
  

int main(){
    setlocale(LC_ALL, "Russian");
    char status;
    do{
        manager();
        std::cout << "\nContinue? (y/n)" << std::endl;
        std::cin >> status;
    } while (status == 'y');
    return 0;
}
