#include "Class_Broken.h"
#ifndef CLASS_CLOSED_BROKEN_H 
#define CLASS_CLOSED_BROKEN_H 
class ClosedBroken: public Broken
{
	public:
		ClosedBroken(int = 0, Point* = 0);
		ClosedBroken(const ClosedBroken&);

		ClosedBroken& operator = (const ClosedBroken&);

		virtual void print();
};
#endif