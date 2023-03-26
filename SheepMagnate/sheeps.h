#pragma once
#ifndef SHEEP_H
#define SHEEP_H
#include "datetime.h"
#include "names.h"
#include "funcs.h"

using namespace std;

struct Sheep
{
    // ��� ����
    SheepName name;

    // ��� ����
    bool isMale = name.isMale;

    // ���� �������� ����
    DateTime birthday;

    // ������� ���� � �����
    DateTime age = datetimeMinus(ToDay, birthday);

    // ��� ���� (� ��) ������������� �������� ������ �� �������� � ����
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
    double sheepWeight = (isMale) ? ((age.year == 1) ? (__random__(45, 55) + __random__(1, 1000) / 1000.0) : (__random__(70, 100) + __random__(1, 1000) / 1000.0)) : ((age.year == 1) ? (__random__(30, 45) + __random__(1, 1000) / 1000.0) : (__random__(60, 80) + __random__(1, 1000) / 1000.0));
    
    // ��� ������ (� �) ������������� �� ���� ���� � ���������� (������� ������ �� ��������� ����)
    double woolWeight = sheepWeight * getWooliness();

    // ������� ���������� �� ����
    void print()
    {
        cout << name.name << " (" << ((isMale) ? "�����" : "����") << ")\t�������: ";
        age.printDiff();
        cout << " (";
        birthday.print();
        cout << ")\t���: " << sheepWeight << " ��" << "\t" << "��� ������: " << woolWeight << " �" << endl;
    }

    // �������� ���������� � �/�� ������ �� �������� ����
    double getWooliness()
    {
        double woolinessByYears[] = { 76.2, 76.0, 76.3, 73.5, 68.8, 65.3, 64.8, 66.3 };

        return woolinessByYears[age.year - 1];
    }

    // �������� ��� ���������, ������� ������ ��������� ���������� (�������, ���, ��� ������)
    void update()
    {
        age = datetimeMinus(ToDay, birthday);
        sheepWeight += __random__(150, 200) / 1000.0;
        woolWeight += sheepWeight * getWooliness() / 10.0;
    }
};

#endif