#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include "datetime.h"
#include "funcs.h"

struct Order
{
	// ���� ����������
	DateTime dueDate{ ToDay.year, ToDay.month, __random__(ToDay.day, ToDay.__daysInMonth__() + 1) };

	// ��� ������
	// 0 - ����� ������ (� ��)
	// 1 - ����� ����   (� ��)
	short orderType = rand() % 2;

	// ��� ����� (���-�� ������ ��� ���� � �� ������� ����� ��� ���������� ������)
	int order = (orderType) ? (__random__(50, 90)) : (__random__(2, 20));

	// ���-�� ����� �� ����������
	int money = (orderType) ? (__random__(300, 600) * order) : (__random__(200, 600) * order);
};

#endif