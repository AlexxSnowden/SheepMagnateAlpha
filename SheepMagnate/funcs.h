#pragma once
#ifndef FUNCS_H
#define FUNCS_H

using namespace std;

// ��������� ����� � ��������� �� __from__ �� __to__
inline int __random__(int __from__, int __to__)
{
	return rand() % (__to__ - __from__) + __from__;
}

#endif