#include "Class_Trapeze.h"
#include <iostream>

Trapeze::Trapeze(Point* arr0)
{
	if (arr0 == 0)
	{
		n = 0;
		arr = 0;
	}

	else
	{
		n = 4;
		arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr0[i];
		}
	}
}
Trapeze::Trapeze(const Trapeze& cb) : Polygon(cb) {}

Trapeze& Trapeze::operator = (const Trapeze& cb)
{
	if (&cb == this)
	{
		return *this;
	}

	Polygon:: operator = (cb);
	return *this;
}

void Trapeze::set(Point* arr0)
{
	if (arr != 0)
	{
		delete[] arr;
	}
	n = 4;
	arr = new Point[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr0[i];
	}
}

void Trapeze::print()
{
	std::cout << "Тип фигуры - трапеция" << '\n';
	for (int i = 0; i < n; i++)
	{
		arr[i].print();
	}
	std::cout << "Периметр P = " << perimeter() << '\n';
	std::cout << "Площадь S = " << size() << '\n';
}