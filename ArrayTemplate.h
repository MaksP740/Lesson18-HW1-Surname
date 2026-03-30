#pragma once

#include <iostream>
#include <cstdlib>
#include <ctime>
#include "DateMac.h"
#include <cstdio>
#include "Structura.h"
#include "Function.h"

using namespace std;


//Заповнення масиву випадковими числами від А до В
template <typename Type>
void randArray(Type arr[], int size, int A=0, int B=10) {
    for (int i = 0; i < size; i++) {
        arr[i] = rand()%(B-A+1) + A;
    }
}

//Виведення масиву на екран
template <typename Type>
void printArray(Type arr[], int size, int Wcout = 4) {
    for (int i = 0; i < size; i++) {
        cout.width(Wcout);
        cout << "| " << arr[i];
    }
    cout << endl;
}

//Функція пошуку максимального індексу
template <typename Type>
int indexMaxElement(Type arr[], int size) {

    Type max = arr[0];
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] > max) {
            max = arr[i];
            index = i;
        }
    }
    return index;
}

//Функція пошуку мінімального індексу
template <typename Type>
int indexMinElement(Type arr[], int size) {

    Type min = arr[0];
    int index = 0;

    for (int i = 0; i < size; i++) {
        if (arr[i] < min) {
            min = arr[i];
            index = i;
        }
    }
    return index;
}
//4.Функція для знаходження суми всіх елементів масиву
template <typename Type>
int sumArray(Type arr[], int size) {
    int sum = 0;
    for (int i = 0; i < size; i++) {
        sum += arr[i];
    }
    return sum;
}

//Функція для знаходження елемента масиву із заданим значенням value
template <typename Type>
int search(Type arr[], int size, Type value) {
int index = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] == value) {
            return i;
        }
        return -1;
    }
}

//Функція яка додає новий елемент в кінець масиву.
template <typename Type>
void addItemBack(Type* &arr, int &size, Type value) {
    //Створюємо масим +1 клітинку більше
    Type *tmp = new Type[size + 1];
    for (int i = 0; i < size; i++) {
        tmp[i] = arr[i];
    }
    //Видаляємо старий масим
    if (arr != nullptr) {
        delete [] arr;
    }
    //Додаємо новий елемент в кінець
    tmp[size] = value;

    //Перепривязуємо показщик на нову адресу
    arr = tmp;
    //Оновлюємо Size масиву
    size ++;
}

//Функція яка додає новий елемент на початок масиву.
template <typename Type>
void addItemStart(Type* &arr, int &size, Type value) {
    //Створюємо масим +1 клітинку більше
    Type *tmp = new Type[size + 1];

    tmp[0] = value;

    for (int i = 0; i < size; i++) {
        tmp[i + 1] = arr[i];
    }
    if (arr != nullptr) {
        delete [] arr;
    }
    arr = tmp;
    size ++;
}
//Функція яка видаляє елемент з масиву масиву.
template <typename Type>
void deleteItem (Type* &arr, int &size, Type index) {

    Type *tmp = new Type[size - 1];

    int j = 0;

    for (int i = 0; i < size - 1; i++) {
        if (i == index) {
            tmp[j++] = arr[i];
        }
        if (arr != nullptr) {
            delete [] arr;
        }
    }
    arr = tmp;
    size --;
}

//Задано масив А(N).
// тримати з нього масив В, що складається з елементів масиву А, які кратні двом.

template <typename Type>
int amountEven(Type* arr, int size) {
    int amount = 0;
    for (int i = 0; i < size; i++) {
        if (arr[i] % 2 == 0) {
            amount ++;
        }
    }
    return amount;
}
template <typename Type>
void createEvenArray(Type*arr, int size, Type*&even, int& sizeEven) {
    sizeEven = amountEven<Type>(arr, size);
    if (sizeEven == 0) {
        return;
    }
    else {
        even = new Type [sizeEven];
        int j = 0;
        for (int i = 0; i < size; i++) {
            if (arr[i] % 2 == 0) {
                even[j++] = arr[i];

            }
        }
    }
}
//1.функцію, яка визначає кількість елементів масиву за критерієм:
template <typename T>
int myCountIf(T* arr, int size, bool (*fP)(T)) {

    int amount = 0;

    for (int i = 0; i < size; i++) {
        if (fP(arr[i]) == true) {
            amount ++;
        }
    }
    return amount;
}

//2. функцію, яка визначає суму елементів масиву за критерієм

template <typename T>
T mySumIf(T* arr, int size, bool (*fP)(T)) {

    T sum = 0;
    for (int i = 0; i < size; i++) {
        if (fP(arr[i]) == true) {
            sum += arr[i];
        }
    }
    return sum;
}

//3. функцію, яка знаходить Індекс першого елемента масиву за критерієм:
template <typename T>
int myFindIf(T* arr, int size, bool (*fP)(T)) {

    int index = 0;
    for (int i = 0; i < size; i++) {
        if (fP(arr[i]) == true) {
            return i;
        }
    }
    return -1;
}

//4.функцію, яка в масиві замінює елементи за критерієм на значення value:
template <typename T>
void myReplaceIf(T* arr, int size, bool (*fP)(T), T value) {

    for (int i = 0; i < size; i++) {
        if (fP(arr[i]) == value) {
            arr[i] = value;
        }
    }
}
//5. функцію, яка в масиві видаляє елементи за критерієм:

template <typename T>
void myRemoveIf(T*& arr, int& size, bool (*fP)(T)) {
    for (int i = 0; i < size; i++) {
        if (fP(arr[i])) {
            deleteItem(arr, size, i);
            i--;
        }
    }
}

//Описати процедуру IncTime(H, M, S, T), що збільшує на T секунд час, заданий
//у годинах H, хвилинах M і секундах S (H, M і S - вхідні та вихідні параметри,
//T - вхідний параметр; усі параметри - цілі додатні).
//Дано час (у годинах H, хвилинах M, секундах S) і ціле число T.
//Використовуючи процедуру IncTime, збільшити цей час на T секунд і вивести нові значення H, M, S.

template <typename Type>
void incTime(Type& H, Type& M, Type& S, int T) {

    S = S + T;

    if (S >= 60) {
        M = M + S / 60;
        S = S % 60;
    }
    if (M >= 60) {
        H = H + M / 60;
        M = M % 60;
    }

}

//3.Описати процедуру InvertDigits(K), що змінює порядок слідування цифр цілого
//додатного числа K на зворотний (K - параметр цілого типу, який є одночасно
//вхідним і вихідним). За допомогою цієї процедури поміняти порядок слідування
//цифр на зворотний для кожного з п'яти даних цілих чисел.
void InvertDigits(int& K) {

    int newNum = 0;
    int endNum = 0;

    while (K > 0) {
        endNum = K % 10;
        K /= 10;
        newNum = newNum * 10 + endNum;
    }
    K = newNum;
}

//4.Створіть функцію, що повертає масив (sub_arr) у діапазоні індексів (з якого по який).
template <typename Type>
void fromNum(Type &start, Type &end) {
    cout << "Введіть початок діапазону: ";
    cin >> start;
    cout << "Введіть кінець діапазону: ";
    cin >> end;
}
template <typename Type>
void createArrayBetween (Type*arr, int size, int from, int to, Type*&sub_arr, int& sub_size) {

    while (from < 0 || to >= size || from > to) {
        cout << "Діапазон не вірний введіть ще раз" << endl;
        fromNum(from, to);
    }

    sub_size = to - from + 1;
    sub_arr = new Type [sub_size];

    int inx = 0;

    for (int i = from - 1; i <= to; i++) {
        sub_arr[inx] = arr[i];
        inx++;
    }
}

//функцію сортування масиву.
//Для порівняння елементів масиву передаємо функції критерій як параметр через покажчик.





//=========================== [ Структури ] ==========================












