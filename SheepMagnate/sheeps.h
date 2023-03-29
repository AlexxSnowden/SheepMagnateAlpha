#pragma once
#ifndef SHEEP_H
#define SHEEP_H
#include "datetime.h"
#include "names.h"
#include "funcs.h"

using std::cout;
using std::endl;

struct Sheep
{
    // Имя овцы
    SheepName name;

    // Пол овцы
    int isMale = name.isMale;

    // Дата рождения овцы
    DateTime birthday;

    // Возраст овцы в годах
    DateTime age = datetimeMinus(ToDay, birthday);

    // Вес шерсти (в г)
    double woolWeight = __random__(50, 70) * getWooliness() + __random__(1, 1000) / 1000.0;

    // Вес овцы (в кг) расчитывается из суммы веса шерсти и случайных чисел исходя из возраста и пола
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
    double sheepWeight = woolWeight / 1000.0 + (isMale) ? ((age.year == 1) ? (__random__(45, 55) + __random__(1, 1000) / 1000.0) : (__random__(70, 100) + __random__(1, 1000) / 1000.0)) : ((age.year == 1) ? (__random__(30, 45) + __random__(1, 1000) / 1000.0) : (__random__(60, 80) + __random__(1, 1000) / 1000.0));

    // Вывести информацию об овце
    void print()
    {
        cout << name.name << " (" << ((isMale) ? "Баран" : "Овца") << ")\tВозраст: ";
        age.printDiff();
        cout << " (" << birthday.print() << ")\tВес: " << sheepWeight << " кг"
            << "\t" << "Вес шерсти: " << woolWeight << " г" << endl;
    }

    // Получить шерстность овцы (просто коэффиценты для расчёта веса шерсти и прироста, по сути случайные числа)
    double getWooliness()
    {
        double woolinessByYears[] = { 76.2, 76.0, 76.3, 73.5, 68.8, 65.3, 64.8, 66.3 };

        return woolinessByYears[age.year - 1];
    }

    // Обновить все параметры, которые должны ежедневно изменяться (возраст, вес, вес шерсти)
    void update()
    {
        age = datetimeMinus(ToDay, birthday);
        double woolWeightPlus = sheepWeight * getWooliness() / 10.0;
        woolWeight += woolWeightPlus;
        sheepWeight += __random__(150, 200) / 1000.0 + woolWeightPlus / 1000;
    }

    // Состричь шерсть у овцы
    double sheer()
    {
        double woolWeightMinus = woolWeight * __random__(985, 999) / 1000;
        woolWeight -= woolWeightMinus;
        sheepWeight -= woolWeightMinus / 1000;

        return woolWeightMinus;
    }
};

// Обновляем поля овец
void updateSheeps(Sheep*& sheeps, int &sheepsSize)
{
    int tempSize = 0;
    Sheep* temp = new Sheep[tempSize];

    for (int i = 0; i < sheepsSize; i++)
    {
        sheeps[i].update();

        if (sheeps[i].woolWeight < __random__(8000, 9000))
            arrayAddEl(temp, tempSize, sheeps[i]);
    }

    delete[] sheeps;
    sheeps = temp;

    sheepsSize = tempSize;
}

void printSheeps(Sheep sheeps[], int sheepsSize)
{
    // Выводим данные овец
    for (int i = 0; i < sheepsSize; i++)
    {
        cout << i + 1 << " ) ";
        sheeps[i].print();
    }
}

#endif