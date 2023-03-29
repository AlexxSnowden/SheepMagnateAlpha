#pragma once
#ifndef FUNCS_H
#define FUNCS_H
#include "windows.h"

using std::cout;
using std::string;

// Есть ли элемент в массиве
template <class T>
bool isElInArray(T a[], int size, T el)
{
    bool isElInArray = 0;

    for (int i = 0; i < size; i++)
    {
        if (el == a[i])
        {
            isElInArray = 1;

            break;
        }
    }

    return isElInArray;
}

// Случайное число в диапазоне от __from__ до __to__
inline int __random__(int __from__, int __to__)
{
	return rand() % (__to__ - __from__) + __from__;
}

// Функция удаления элемента по указанному индексу.
template <class T>
void arrayDeleteElByIndex(T*& a, int& size, int index_el)
{
    T* temp = new T[size - 1];

    for (int i = 0; i < index_el; i++)
        temp[i] = a[i];

    for (int i = index_el + 1; i < size; i++)
        temp[i - 1] = a[i];

    delete[] a;
    a = temp;

    size--;
}

// Удалить элементы по индексам
template <class T>
void arrayDeleteElsByIndexes(T*& a, int& size, int indexes[], int indexesSize)
{
    int tempSize = 0;
    T* temp = new T[tempSize];

    for (int j = 0; j < size; j++)
    {
        bool flag = 0;

        for (int k = 0; k < indexesSize; k++)
        {
            if (j == indexes[k])
            {
                flag = 1;

                break;
            }
        }

        if (!flag)
            arrayAddEl(temp, tempSize, a[j]);
    }

    delete[] a;
    a = temp;

    size = tempSize;
}

// Добавить элемент в массив
template <class T>
void arrayAddEl(T*& a, int& size, T el)
{
    T* temp = new T[size + 1];

    for (int i = 0; i < size; i++)
        temp[i] = a[i];

    temp[size] = el;

    delete[] a;
    a = temp;

    size++;
}

// Вывести текст с задержкой в мс
void printWithDelay(string str, int delay)
{
    for (int i = 0; i < str.length(); i++)
    {
        cout << str[i];

        Sleep(delay);
    }
}

#endif