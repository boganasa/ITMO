#include "Class_Closed_Broken.h"
#include <iostream>

ClosedBroken::ClosedBroken(int nn, Point* arr0) : Broken(nn, arr0){}
ClosedBroken::ClosedBroken(const ClosedBroken& cb) : Broken(cb) {}

ClosedBroken& ClosedBroken::operator = (const ClosedBroken& cb)
{
	if (&cb == this)
	{
		return *this;
	}

	Broken:: operator = (cb);
	return *this;
}

void ClosedBroken::print()
{
	std::cout << "Тип фигуры - замкнутая ломанная" << '\n';
	for (int i = 0; i < n; i++)
	{
		arr[i].print();
	}
}