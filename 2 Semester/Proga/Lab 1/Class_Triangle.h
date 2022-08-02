#include "Class_Polygon.h"
#ifndef CLASS_TRIANGLE_H 
#define CLASS_TRIANGLE_H 
class Triangle : public Polygon
{
public:
	Triangle(Point* = 0);
	Triangle(const Triangle&);


	void set(Point*);

	Triangle& operator = (const Triangle&);

	virtual void print();
};
#endif
