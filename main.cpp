#include <iostream>
#include "ArrayTemplate.h"



int main() {

    int size_arr = 5;

    workman* infoMan = nullptr;

    addItemBack(infoMan, size_arr, {"Колесник",{ 3, 12, 1992}, "Плиточник", 35000, "Професійно-технічна"});
    addItemBack(infoMan, size_arr, {"Пінчук",{ 2, 2, 1989}, "Механік", 55000, "Базова освіта"});
    addItemBack(infoMan, size_arr, {"Світловий",{ 13, 7, 1997}, "Менеджмент", 35000, "Вища"});



    return 0;
}