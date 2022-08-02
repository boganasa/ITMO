#include "Class_RegularPolygon.h"
#include <cmath>
#include <iostream>

RegularPolygon::RegularPolygon(int nn, Point* arr0) : Polygon(nn, arr0) {}
RegularPolygon::RegularPolygon(const RegularPolygon& cb) : Polygon(cb) {}

RegularPolygon& RegularPolygon::operator = (const RegularPolygon& cb)
{
	if (&cb == this)
	{
		return *this;
	}

	Polygon:: operator = (cb);
	return *this;
}

double RegularPolygon::perimeter()
{
	double per = 0, beg = 0, end = 0;
	beg = abs(arr[0].getx() - arr[n - 1].getx());
	end = abs(arr[0].gety() - arr[n - 1].gety());
	per += sqrt(pow(beg, 2) + pow(end, 2));
	per *= n;
	return per;
}

void RegularPolygon::print()
{
	std::cout << "Тип фигуры - правильный многоугольник" << '\n';
	for (int i = 0; i < n; i++)
	{
		arr[i].print();
	}
	std::cout << "Периметр P = " << perimeter() << '\n';
	std::cout << "Площадь S = " << size() << '\n';
}