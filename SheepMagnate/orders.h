#pragma once
#ifndef ORDERS_H
#define ORDERS_H
#include "datetime.h"
#include "funcs.h"

using namespace std;

struct Order
{
	// Срок выполнения ДД.01.2023
	DateTime dueDate{2023, 1};

	// Тип заказа
	// 0 - заказ шерсти (в кг)
	// 1 - заказ мяса   (в кг)
	short orderType = rand() % 2;

	// Сам заказ (кол-во шерсти или мяса в кг которое нужно для выполнения заказа)
	int order = (orderType) ? (__random__(50, 400)) : (10, 100);

	// Кол-во денег за выполнение
	int money = (orderType) ? (__random__(300, 600) * order) : (__random__(20, 60) * order);

	// Вывести информацию о заказе
	void print()
	{
		cout << "Заказ " << ((orderType) ? "мяса" : "шерсти") << " до ";
		dueDate.print();
		cout << ". " << order << " кг за " << money << " руб." << endl;
	}
};

#endif