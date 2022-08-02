#include "Class_Triangle.h"
#include <iostream>
Triangle::Triangle(Point* arr0)
{
	if (arr0 == 0)
	{
		n = 0;
		arr = 0;
	}
	
	else
	{
		n = 3;
		arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr0[i];
		}
	}
}
Triangle::Triangle(const Triangle& cb) : Polygon(cb) {}

Triangle& Triangle::operator = (const Triangle& cb)
{
	if (&cb == this)
	{
		return *this;
	}

	set(cb.arr);
	return *this;
}

void Triangle::set(Point* arr0)
{
	if (arr != 0)
	{
		delete[] arr;
	}
	n = 3;
	arr = new Point[n];
	for (int i = 0; i < n; i++)
	{
		arr[i] = arr0[i];
	}
}

void Triangle::print()
{
	std::cout << "Тип фигуры - треугольник" << '\n';
	for (int i = 0; i < n; i++)
	{
		arr[i].print();
	}
	std::cout << "Периметр P = " << perimeter() << '\n';
	std::cout << "Площадь S = " << size() << '\n';
}