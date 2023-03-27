#pragma once
#ifndef DATETIME_H
#define DATETIME_H
#include "funcs.h"
#include <string>

using namespace std;

struct DateTime
{
	// Год
	int year = __random__(2015, 2022);

	// Месяц
	int month = __random__(1, 12);

	// День
	int day = __random__(1, __daysInMonth__());

	// Вернуть дату в формате ДД.ММ.ГГГГ
	string print()
	{
		string result = "";

		if (day < 10)
			result += "0";

		result += to_string(day) + '.';

		if (month < 10)
			result += "0";

		result += to_string(month) + '.' + to_string(year);

		return result;
	}

	// Вывести дату в формате разницы
	// ДД дней ММ месяцев ГГ лет
	void printDiff()
	{
		// Если год != 0
		if (year)
		{
			cout << year;

			if (year == 1)
				cout << " год";
			else if (year >= 2 && year < 5)
				cout << " года";
			else
				cout << " лет";
		}

		// Если месяц != 0
		if (month)
		{
			cout << ' ' << month;

			if (month == 1)
				cout << " месяц";
			else if (month >= 2 && month < 5)
				cout << " месяца";
			else
				cout << " месяцев";
		}

		// Если день != 0
		if (day)
		{
			cout << ' ' << day;

			if (day == 1 || day == 21 || day == 31)
				cout << " день";
			else if ((day >= 2 && day < 5) || (day >= 22 && day < 25))
				cout << " дня";
			else
				cout << " дней";
		}
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

// Глобальная переменная времени
DateTime ToDay{2023, 1, 1};

// Посчитать разницу во времени (a - b)
DateTime datetimeMinus(DateTime a, DateTime b)
{
	int year_minus  = ((b.month > a.month || b.day > a.day) && a.year != b.year) ? (a.year - b.year - 1) : (a.year - b.year);
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

	if (month_minus == 12)
		month_minus = 0;

	DateTime result{year_minus, month_minus, day_minus};

	return result;
}

// Больше ли дата a, чем дата b
bool datetimeIsAMoreThanB(DateTime a, DateTime b)
{
	if (a.year > b.year)
		return 1;

	else if (a.year < b.year)
		return 0;

	else if (a.month == b.month)
		return a.day > b.day;

	else
	{
		// Сколько всего дней в дате a (прошло с 01.01)
		int aDays = 0;

		while (a.month > 1)
		{
			aDays += a.__daysInMonth__();

			a.month--;
		}

		// Сколько всего дней в дате b (прошло с 01.01)
		int bDays = 0;

		while (b.month > 1)
		{
			bDays += b.__daysInMonth__();

			b.month--;
		}

		return aDays > bDays;
	}
}

#endif