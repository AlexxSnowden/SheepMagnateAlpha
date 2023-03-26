#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include "datetime.h"
#include "funcs.h"

using namespace std;

struct Order
{
	// Срок выполнения ДД.01.2023
	DateTime dueDate{ToDay.year, ToDay.month, __random__(ToDay.day + 1, ToDay.__daysInMonth__())};

	// Тип заказа
	// 0 - заказ шерсти (в кг)
	// 1 - заказ мяса   (в кг)
	short orderType = rand() % 2;

	// Сам заказ (кол-во шерсти или мяса в кг которое нужно для выполнения заказа)
	int order = (orderType) ? (__random__(50, 150)) : (2, 20);

	// Кол-во денег за выполнение
	int money = (orderType) ? (__random__(300, 600) * order) : (__random__(200, 600) * order);

	// Вышло ли время заказа
	bool isOrderEnd()
	{
		DateTime temp = datetimeMinus(dueDate, ToDay);

		temp.print();
		cout << endl;

		return (temp.year < 0) ? 1 : 0;
	}
};

#endif