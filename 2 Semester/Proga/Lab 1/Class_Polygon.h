#include "Class_Closed_Broken.h"
#ifndef CLASS_POLYGON_H 
#define CLASS_POLYGON_H 
class Polygon : public ClosedBroken
{
public:
	Polygon(int = 0, Point* = 0);
	Polygon(const Polygon&);

	Polygon& operator = (const Polygon&);

	virtual void print();

	virtual double perimeter();
	double size();
};
#endif
