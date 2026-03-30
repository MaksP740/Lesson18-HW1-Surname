#pragma once

struct workman {
    char nickname[100];
    Date yearOfbirth;
    char position[100];
    double money;
    char education[100];


    void infoWork() {
        cout << "Прізвище: " << nickname << endl;
        cout << "Рік народження: " << yearOfbirth.toString("%d.%m.%Y") << endl;
        cout << "Посада: " << position << endl;
        cout << "Заробітня платня: " << money << " грн" << endl;
        cout << "Освіта: " << education << endl;
    }
};


