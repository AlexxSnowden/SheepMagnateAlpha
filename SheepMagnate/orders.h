#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include "datetime.h"
#include "funcs.h"

using namespace std;

struct Order
{
	// ���� ���������� ��.01.2023
	DateTime dueDate{2023, 1};

	// ��� ������
	// 0 - ����� ������ (� ��)
	// 1 - ����� ����   (� ��)
	short orderType = rand() % 2;

	// ��� ����� (���-�� ������ ��� ���� � �� ������� ����� ��� ���������� ������)
	int order = (orderType) ? (__random__(50, 400)) : (10, 100);

	// ���-�� ����� �� ����������
	int money = (orderType) ? (__random__(300, 600) * order) : (__random__(20, 60) * order);

	// ������� ���������� � ������
	void print()
	{
		cout << "����� " << ((orderType) ? "����" : "������") << " �� ";
		dueDate.print();
		cout << ". " << order << " �� �� " << money << " ���." << endl;
	}
};

#endif