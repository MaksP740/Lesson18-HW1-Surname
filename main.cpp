#include <iostream>
#include "ArrayTemplate.h"



int main() {

    int size_arr = 0;

    workman* infoMan = nullptr;

    addItemBack(infoMan, size_arr, {"Колесник",{ 3, 12, 1992}, "Плиточник", 21000, "Професійно-технічна"});
    addItemBack(infoMan, size_arr, {"Пінчук",{ 2, 2, 1989}, "Механік", 13000, "Базова"});
    addItemBack(infoMan, size_arr, {"Світловий",{ 13, 7, 1997}, "Менеджмент", 39000, "Вища"});
    addItemBack(infoMan, size_arr, {"Харченко",{ 10, 11, 1959}, "Вантажник", 20000, "Базова"});
    addItemBack(infoMan, size_arr, {"Артеменко",{ 8, 3, 1960}, "Охоронник", 11000, "Середня"});

    seniorEmployees(infoMan, size_arr);


    delete[] infoMan;
    return 0;
}