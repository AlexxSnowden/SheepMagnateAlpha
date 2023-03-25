#pragma once
#ifndef SHEEP_H
#define SHEEP_H
#include "datetime.h"
#include "names.h"
#include "funcs.h"

using namespace std;

struct Sheep
{
    // Имя овцы
    SheepName name;

    // Пол овцы
    bool isMale = name.isMale;

    // Дата рождения овцы
    DateTime birthday;

    // Возраст овцы в годах
    short ageInYears = 2023 - birthday.year;

    // Вес овцы (в кг) расчитывается случайно исходя из возраста и пола
    // Если баран:
    //     если возраст == 1:
    //         случайное число от 45 до 55 + случайное число от 0.001 до 1
    //     иначе:
    //         случайное число от 70 до 100 + случайное число от 0.001 до 1
    // Иначе:
    //     если возраст == 1:
    //         случайное число от 30 до 45 + случайное число от 0.001 до 1
    //     иначе:
    //         случайное число от 60 до 85 + случайное число от 0.001 до 1
    //
    double sheepWeight = (isMale) ? ((ageInYears) ? (__random__(45, 55) + __random__(1, 1000) / 1000.0) : (__random__(70, 100) + __random__(1, 1000) / 1000.0)) : ((ageInYears) ? (__random__(30, 45) + __random__(1, 1000) / 1000.0) : (__random__(60, 85) + __random__(1, 1000) / 1000.0));
    
    // Вес шерсти (в г) расчитывается из веса овцы и шерстности (сколько шерсти на килограмм масы)
    double woolWeight = sheepWeight * getWooliness();

    // Вывести информацию об овце
    void print()
    {
        cout << name.name << " (" << ((isMale) ? "Баран" : "Овца") << ")\tВозраст в годах: " << ageInYears << " (";
        birthday.print();
        cout << ")\tВес: " << sheepWeight << " кг" << "\t" << "Вес шерсти: " << woolWeight << " г" << endl;
    }

    // Получить шерстность в г/кг исходя из возраста овцы
    double getWooliness()
    {
        double woolinessByYears[] = { 76.0, 76.0, 76.3, 73.5, 68.8, 65.3, 64.8, 66.3 };

        return woolinessByYears[ageInYears - 1];
    }
};

#endif