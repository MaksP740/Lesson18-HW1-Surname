#pragma once
#include "DateMac.h"

void seniorEmployees(workman* arr, int size_arr) {

    cout << "\nПрацівники старші за 60 років\n";

    int res = 0;

    Date now;
    now.getNowDate();

    for (int i = 0; i < size_arr; i++) {
        int Age = now.year - arr[i].yearOfbirth.year;

        if (Age > 60) {
            res++;

            cout << "=========================\n";
            arr[i].infoWork();
            cout << "Вік: " << Age << " рік" << endl;
            cout << ">> ПОРА НА ПЕНСІЮ <<" << endl;
        }
    }
    cout << "==========================\n";
    cout << "Кількість працівників: " << res << endl;





}