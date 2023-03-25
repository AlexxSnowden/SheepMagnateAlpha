#pragma once
#ifndef DATETIME_H
#define DATETIME_H
#include "funcs.h"

using namespace std;

struct DateTime
{
	// Год
	short year = __random__(2015, 2022);

	// Месяц
	short month = __random__(1, 12);

	// День
	short day = __random__(1, __daysInMonth__());

	// Вывести дату в формате ДД.ММ.ГГГГ
	void print()
	{
		if (day < 10)
			cout << "0";

		cout << day << '.';

		if (month < 10)
			cout << "0";

		cout << month << '.' << year;
	}

	// Изменить дату на один день вперёд
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

	// Високосный ли год
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

	// Кол-во дней в месяце
	inline int __daysInMonth__()
	{
		return (__isTheYearLeap__() && month == 2) ? (29 + (month + month / 8) % 2 + 2 % month + 2 * (1 / month)) : (28 + (month + month / 8) % 2 + 2 % month + 2 * (1 / month));
	}
};

#endif