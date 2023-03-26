#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include "datetime.h"
#include "funcs.h"

using namespace std;

struct Order
{
	// ���� ���������� ��.01.2023
	DateTime dueDate{ToDay.year, ToDay.month, __random__(ToDay.day + 1, ToDay.__daysInMonth__())};

	// ��� ������
	// 0 - ����� ������ (� ��)
	// 1 - ����� ����   (� ��)
	short orderType = rand() % 2;

	// ��� ����� (���-�� ������ ��� ���� � �� ������� ����� ��� ���������� ������)
	int order = (orderType) ? (__random__(50, 150)) : (2, 20);

	// ���-�� ����� �� ����������
	int money = (orderType) ? (__random__(300, 600) * order) : (__random__(200, 600) * order);

	// ����� �� ����� ������
	bool isOrderEnd()
	{
		DateTime temp = datetimeMinus(dueDate, ToDay);

		temp.print();
		cout << endl;

		return (temp.year < 0) ? 1 : 0;
	}
};

#endif