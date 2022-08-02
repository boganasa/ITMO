#include "Class_Polygon.h"
#ifndef CLASS_TRAPEZE_H 
#define CLASS_TRAPEZE_H 
class Trapeze : public Polygon
{
public:
	Trapeze(Point* = 0);
	Trapeze(const Trapeze&);

	Trapeze& operator = (const Trapeze&);

	void set(Point*);

	virtual void print();
};
#endif
