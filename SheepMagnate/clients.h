#pragma once
#ifndef CLIENTS_H
#define CLIENTS_H
#include "orders.h"
#include "names.h"

using namespace std;

struct Client
{
	// Заказ клиента
	Order order;

	// Имя клиента
	ClientName name;

	// Имя компании клиента
	CompanyName companyName{ order.orderType };

	// Вывести информацию о клиенте
	void print()
	{
		cout << name.name << " из компании \"" << companyName.name << "\" просит " << order.order << " кг"
			<< ((order.orderType) ? " мяса " : " шерсти ") << "за " << order.money << " руб. Срок: ";
		order.dueDate.print();
		cout << endl;
	}
};

#endif