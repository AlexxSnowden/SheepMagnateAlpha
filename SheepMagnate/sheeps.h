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
    // ��� ����
    SheepName name;

    // ��� ����
    int isMale = name.isMale;

    // ���� �������� ����
    DateTime birthday;

    // ������� ���� � �����
    DateTime age = datetimeMinus(ToDay, birthday);

    // ��� ������ (� �)
    double woolWeight = __random__(50, 70) * getWooliness() + __random__(1, 1000) / 1000.0;

    // ��� ���� (� ��) ������������� �� ����� ���� ������ � ��������� ����� ������ �� �������� � ����
    // ���� �����:
    //     ���� ��.��� == 2022:
    //         ��������� ����� �� 45 �� 55 + ��������� ����� �� 0.001 �� 1
    //     �����:
    //         ��������� ����� �� 70 �� 100 + ��������� ����� �� 0.001 �� 1
    // �����:
    //     ���� ��.��� == 2022:
    //         ��������� ����� �� 30 �� 45 + ��������� ����� �� 0.001 �� 1
    //     �����:
    //         ��������� ����� �� 60 �� 80 + ��������� ����� �� 0.001 �� 1
    //
    double sheepWeight = woolWeight / 1000.0 + (isMale) ? ((age.year == 1) ? (__random__(45, 55) + __random__(1, 1000) / 1000.0) : (__random__(70, 100) + __random__(1, 1000) / 1000.0)) : ((age.year == 1) ? (__random__(30, 45) + __random__(1, 1000) / 1000.0) : (__random__(60, 80) + __random__(1, 1000) / 1000.0));

    // ������� ���������� �� ����
    void print()
    {
        cout << name.name << " (" << ((isMale) ? "�����" : "����") << ")\t�������: ";
        age.printDiff();
        cout << " (" << birthday.print() << ")\t���: " << sheepWeight << " ��"
            << "\t" << "��� ������: " << woolWeight << " �" << endl;
    }

    // �������� ���������� ���� (������ ����������� ��� ������� ���� ������ � ��������, �� ���� ��������� �����)
    double getWooliness()
    {
        double woolinessByYears[] = { 76.2, 76.0, 76.3, 73.5, 68.8, 65.3, 64.8, 66.3 };

        return woolinessByYears[age.year - 1];
    }

    // �������� ��� ���������, ������� ������ ��������� ���������� (�������, ���, ��� ������)
    void update()
    {
        age = datetimeMinus(ToDay, birthday);
        double woolWeightPlus = sheepWeight * getWooliness() / 10.0;
        woolWeight += woolWeightPlus;
        sheepWeight += __random__(150, 200) / 1000.0 + woolWeightPlus / 1000;
    }

    // �������� ������ � ����
    double sheer()
    {
        double woolWeightMinus = woolWeight * __random__(985, 999) / 1000;
        woolWeight -= woolWeightMinus;
        sheepWeight -= woolWeightMinus / 1000;

        return woolWeightMinus;
    }
};

// ��������� ���� ����
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
    // ������� ������ ����
    for (int i = 0; i < sheepsSize; i++)
    {
        cout << i + 1 << " ) ";
        sheeps[i].print();
    }
}

#endif