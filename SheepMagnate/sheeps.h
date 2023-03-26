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
    DateTime age = datetimeMinus(ToDay, birthday);

    // Вес овцы (в кг) расчитывается случайно исходя из возраста и пола
    // Если баран:
    //     если др.год == 2022:
    //         случайное число от 45 до 55 + случайное число от 0.001 до 1
    //     иначе:
    //         случайное число от 70 до 100 + случайное число от 0.001 до 1
    // Иначе:
    //     если др.год == 2022:
    //         случайное число от 30 до 45 + случайное число от 0.001 до 1
    //     иначе:
    //         случайное число от 60 до 80 + случайное число от 0.001 до 1
    //
    double sheepWeight = (isMale) ? ((age.year == 1) ? (__random__(45, 55) + __random__(1, 1000) / 1000.0) : (__random__(70, 100) + __random__(1, 1000) / 1000.0)) : ((age.year == 1) ? (__random__(30, 45) + __random__(1, 1000) / 1000.0) : (__random__(60, 80) + __random__(1, 1000) / 1000.0));
    
    // Вес шерсти (в г) расчитывается из веса овцы и шерстности (сколько шерсти на килограмм масы)
    double woolWeight = sheepWeight * getWooliness();

    // Вывести информацию об овце
    void print()
    {
        cout << name.name << " (" << ((isMale) ? "Баран" : "Овца") << ")\tВозраст: ";
        age.printDiff();
        cout << " (";
        birthday.print();
        cout << ")\tВес: " << sheepWeight << " кг" << "\t" << "Вес шерсти: " << woolWeight << " г" << endl;
    }

    // Получить шерстность в г/кг исходя из возраста овцы
    double getWooliness()
    {
        double woolinessByYears[] = { 76.2, 76.0, 76.3, 73.5, 68.8, 65.3, 64.8, 66.3 };

        return woolinessByYears[age.year - 1];
    }

    // Обновить все параметры, которые должны ежедневно изменяться (возраст, вес, вес шерсти)
    void update()
    {
        age = datetimeMinus(ToDay, birthday);
        sheepWeight += __random__(150, 200) / 1000.0;
        woolWeight += sheepWeight * getWooliness() / 10.0;
    }
};

#endif