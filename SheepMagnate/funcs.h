#pragma once
#ifndef FUNCS_H
#define FUNCS_H

// Случайное число в диапазоне от __from__ до __to__
inline int __random__(int __from__, int __to__)
{
	return std::rand() % (__to__ - __from__) + __from__;
}

#endif