#pragma once
#ifndef DATETIME_H
#define DATETIME_H
#include "funcs.h"

using namespace std;

struct DateTime
{
	// ���
	short year = __random__(2015, 2022);

	// �����
	short month = __random__(1, 12);

	// ����
	short day = __random__(1, __daysInMonth__());

	// ������� ���� � ������� ��.��.����
	void print()
	{
		if (day < 10)
			cout << "0";

		cout << day << '.';

		if (month < 10)
			cout << "0";

		cout << month << '.' << year;
	}

	// �������� ���� �� ���� ���� �����
	void switchDay()
	{
		day++;

		if (day > __daysInMonth__())
		{
			day = 1;
			month++;
		}

		if (month > 12)
		{
			month = 1;
			year++;
		}
	}

	// ���������� �� ���
	bool __isTheYearLeap__()
	{
		if (year % 4 == 0)
		{
			if (year % 100 == 0)
			{
				if (year % 400 == 0)
					return 1;

				else return 0;
			}
			else
				return 1;
		}
		else
			return 0;
	}

	// ���-�� ���� � ������
	inline int __daysInMonth__()
	{
		return (__isTheYearLeap__() && month == 2) ? (29 + (month + month / 8) % 2 + 2 % month + 2 * (1 / month)) : (28 + (month + month / 8) % 2 + 2 % month + 2 * (1 / month));
	}
};

#endif