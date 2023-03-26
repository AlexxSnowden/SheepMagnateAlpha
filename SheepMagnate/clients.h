#pragma once
#ifndef CLIENTS_H
#define CLIENTS_H
#include "orders.h"
#include "names.h"

using namespace std;

struct Client
{
	// ����� �������
	Order order;

	// ��� �������
	ClientName name;

	// ��� �������� �������
	CompanyName companyName{ order.orderType };

	// ������� ���������� � �������
	void print()
	{
		cout << name.name << " �� �������� \"" << companyName.name << "\" ������ " << order.order << " ��"
			<< ((order.orderType) ? " ���� " : " ������ ") << "�� " << order.money << " ���. ����: ";
		order.dueDate.print();
		cout << endl;
	}
};

#endif