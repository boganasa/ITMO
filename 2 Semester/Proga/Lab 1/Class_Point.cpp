#include "Class_Point.h"
#include <iostream>

Point::Point(double xx, double yy)
{
	setx(xx);
	sety(yy);
}

Point::Point(const Point& p)
{
	setx(p.x);
	sety(p.y);
}

Point& Point::operator = (const Point& p)
{
	if (&p == this)
	{
		return *this;
	}
	setx(p.x);
	sety(p.y);
	return *this;
}

double Point::getx()
{
	return x;
}
double Point::gety()
{
	return y;
}

void Point::setx(double xx)
{
	x = xx;
}
void Point::sety(double yy)
{
	y = yy;
}

void Point::print()
{
	std::cout << "(" << x << ", " << y << ")" << '\n';
}