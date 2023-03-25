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
    short ageInYears = 2023 - birthday.year;

    // ��� ���� (� ��) ������������� �������� ������ �� �������� � ����
    // ���� �����:
    //     ���� ������� == 1:
    //         ��������� ����� �� 45 �� 55 + ��������� ����� �� 0.001 �� 1
    //     �����:
    //         ��������� ����� �� 70 �� 100 + ��������� ����� �� 0.001 �� 1
    // �����:
    //     ���� ������� == 1:
    //         ��������� ����� �� 30 �� 45 + ��������� ����� �� 0.001 �� 1
    //     �����:
    //         ��������� ����� �� 60 �� 85 + ��������� ����� �� 0.001 �� 1
    //
    double sheepWeight = (isMale) ? ((ageInYears) ? (__random__(45, 55) + __random__(1, 1000) / 1000.0) : (__random__(70, 100) + __random__(1, 1000) / 1000.0)) : ((ageInYears) ? (__random__(30, 45) + __random__(1, 1000) / 1000.0) : (__random__(60, 85) + __random__(1, 1000) / 1000.0));
    
    // ��� ������ (� �) ������������� �� ���� ���� � ���������� (������� ������ �� ��������� ����)
    double woolWeight = sheepWeight * getWooliness();

    // ������� ���������� �� ����
    void print()
    {
        cout << name.name << " (" << ((isMale) ? "�����" : "����") << ")\t������� � �����: " << ageInYears << " (";
        birthday.print();
        cout << ")\t���: " << sheepWeight << " ��" << "\t" << "��� ������: " << woolWeight << " �" << endl;
    }

    // �������� ���������� � �/�� ������ �� �������� ����
    double getWooliness()
    {
        double woolinessByYears[] = { 76.0, 76.0, 76.3, 73.5, 68.8, 65.3, 64.8, 66.3 };

        return woolinessByYears[ageInYears - 1];
    }
};

#endif