#include "Class_Polygon.h"
#ifndef CLASS_REGULARPOLYGON_H 
#define CLASS_REGULARPOLYGON_H 
class RegularPolygon : public Polygon
{
public:
	RegularPolygon(int = 0, Point* = 0);
	RegularPolygon(const RegularPolygon&);

	double perimeter();

	RegularPolygon& operator = (const RegularPolygon&);

	virtual void print();
};
#endif
