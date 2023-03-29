#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include "datetime.h"
#include "funcs.h"

struct Order
{
	// Срок выполнения
	DateTime dueDate{ ToDay.year, ToDay.month, __random__(ToDay.day, ToDay.__daysInMonth__() + 1) };

	// Тип заказа
	// 0 - заказ шерсти (в кг)
	// 1 - заказ мяса   (в кг)
	short orderType = rand() % 2;

	// Сам заказ (кол-во шерсти или мяса в кг которое нужно для выполнения заказа)
	int order = (orderType) ? (__random__(50, 90)) : (__random__(2, 20));

	// Кол-во денег за выполнение
	int money = (orderType) ? (__random__(300, 600) * order) : (__random__(200, 600) * order);
};

#endif