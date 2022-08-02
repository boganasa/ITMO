#include <cmath>
#include <iostream>
#include "Class_Polygon.h"
Polygon::Polygon(int nn, Point* arr0) : ClosedBroken(nn, arr0) {}
Polygon::Polygon(const Polygon& cb) : ClosedBroken(cb) {}

Polygon& Polygon::operator = (const Polygon& cb)
{
	if (&cb == this)
	{
		return *this;
	}

	ClosedBroken:: operator = (cb);
	return *this;
}

void Polygon::print()
{
	std::cout << "Тип фигуры - многоугольник" << '\n';
	for (int i = 0; i < n; i++)
	{
		arr[i].print();
	}
	std::cout << "Периметр P = " << perimeter() << '\n';
	std::cout << "Площадь S = " << size() << '\n';

}

double Polygon::perimeter()
{
	double per = 0, beg = 0, end = 0;
	for (int i = 1; i < n; i++)
	{
		beg = abs(arr[i].getx() - arr[i - 1].getx());
		end = abs(arr[i].gety() - arr[i - 1].gety());
		per += sqrt(pow(beg, 2) + pow(end, 2));
	}
	beg = abs(arr[0].getx() - arr[n - 1].getx());
	end = abs(arr[0].gety() - arr[n - 1].gety());
	per += sqrt(pow(beg, 2) + pow(end, 2));
	return per;
}
double Polygon::size()
{
	double s = 0, s1 = 0, s2 = 0;
	for (int i = 0; i < n - 1; i++) //по формуле площади Гауса
	{
		s1 += arr[i].getx() * arr[i + 1].gety();
		s2 += arr[i + 1].getx() * arr[i].gety();
	}
	s1 += arr[n - 1].getx() * arr[0].gety();
	s2 += arr[0].getx() * arr[n - 1].gety();
	s = 0.5 * abs(s1 - s2);
	return s;
}