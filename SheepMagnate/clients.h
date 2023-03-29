#pragma once
#ifndef CLIENTS_H
#define CLIENTS_H
#include "orders.h"
#include "names.h"

using std::cout;
using std::endl;

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
			<< ((order.orderType) ? " ���� " : " ������ ") << "�� " << order.money << " ���. ����: "
			<< order.dueDate.print() << endl;
	}
};

// ���-�� ��������, ������ ������� ����� ���������
int isAnyClientCompletable(Client clients[], int clientsSize, double countOfMeat, double countOfWool)
{
	int countOfCompletableOrders = 0;

	for (int i = 0; i < clientsSize; i++)
	{
		if (clients[i].order.order < ((clients[i].order.orderType) ? countOfMeat : countOfWool))
			countOfCompletableOrders++;
	}

	return countOfCompletableOrders;
}

// ������� ������� ������
void updateClients(Client*& clients, int& size)
{
	int tempSize = 0;
	Client* temp = new Client[tempSize];

	for (int i = 0; i < size; i++)
	{
		if (!datetimeIsAMoreThanB(ToDay, clients[i].order.dueDate))
			arrayAddEl(temp, tempSize, clients[i]);
	}

	delete[] clients;
	clients = temp;

	size = tempSize;
}

// ������� ������ ��������
void printClients(Client clients[], int size, bool withI)
{
	if (withI)
	{
		for (int i = 0; i < size; i++)
		{
			cout << i + 1 << " ) ";
			clients[i].print();
		}	
	}
	else
	{
		for (int i = 0; i < size; i++)
		{
			clients[i].print();
		}
	}
}

#endif