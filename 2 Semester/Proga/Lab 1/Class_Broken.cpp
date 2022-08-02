#include "Class_broken.h"
#include <iostream>

Broken::Broken(int nn, Point* arr0)
{
	n = nn;
	if (n == 0)
	{
		arr = 0;
	}
	else
	{
		arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr0[i];
		}
	}
}

Broken::Broken(const Broken& b)
{
	n = b.n;
	if (n == 0)
	{
		arr = 0;
	}
	else
	{
		arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = b.arr[i];
		}
	}
}

Broken::~Broken()
{
	if (arr != 0)
	{
		delete[] arr;
	}
}

Broken& Broken::operator = (const Broken& b)
{
	if (&b == this)
	{
		return *this;
	}
	set(b.n, b.arr);
	return *this;
}

int Broken::getn()
{
	return n;
}
Point* Broken::getarr()
{
	Point* arr0 = new Point[n];
	for (int i = 0; i < n; i++)
	{
		arr0[i] = arr[i];
	}
	return arr0;
}


void Broken::set(int nn, Point* arr0)
{
	if (arr != 0)
	{
		delete[] arr;
	}
	n = nn;
	if (n == 0)
	{
		arr = 0;
	}
	else
	{
		arr = new Point[n];
		for (int i = 0; i < n; i++)
		{
			arr[i] = arr0[i];
		}
	}
}


void Broken::print()
{ 
	std::cout << "Тип фигуры - ломанная" << '\n';
	for (int i = 0; i < n; i++)
	{
		arr[i].print();
	}
}
