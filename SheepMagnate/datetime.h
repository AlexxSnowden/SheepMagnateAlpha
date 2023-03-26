#pragma once
#ifndef DATETIME_H
#define DATETIME_H
#include "funcs.h"

using namespace std;

struct DateTime
{
	// ���
	int year = __random__(2015, 2022);

	// �����
	int month = __random__(1, 12);

	// ����
	int day = __random__(1, __daysInMonth__());

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

	// ������� ���� � ������� �������
	// �� ���� �� ������� �� ���
	void printDiff()
	{
		// ���� ��� != 0
		if (year)
		{
			cout << year;

			if (year == 1)
				cout << " ���";
			else if (year >= 2 && year < 5)
				cout << " ����";
			else
				cout << " ���";
		}

		// ���� ����� != 0
		if (month)
		{
			cout << ' ' << month;

			if (month == 1)
				cout << " �����";
			else if (month >= 2 && month < 5)
				cout << " ������";
			else
				cout << " �������";
		}

		// ���� ���� != 0
		if (day)
		{
			cout << ' ' << day;

			if (day == 1 || day == 21 || day == 31)
				cout << " ����";
			else if ((day >= 2 && day < 5) || (day >= 22 && day < 25))
				cout << " ���";
			else
				cout << " ����";
		}
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

DateTime ToDay{2023, 1, 1};

// ��������� ������� �� ������� (a - b)
DateTime datetimeMinus(DateTime a, DateTime b)
{
	int year_minus  = (b.month > a.month || b.day > a.day) ? (a.year - b.year - 1) : (a.year - b.year);
	int month_minus = 12 + a.month - b.month;
	int day_minus;

	if (b.day > a.day)
	{
		day_minus = b.__daysInMonth__() + a.day - b.day;

		month_minus--;
	}
	else
	{
		day_minus = a.day - b.day;
	}

	DateTime result{year_minus, month_minus, day_minus};

	return result;
}

#endif