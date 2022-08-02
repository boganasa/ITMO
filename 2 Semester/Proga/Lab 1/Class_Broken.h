#include "Class_Point.h"

#ifndef CLASS_BROKEN_H 
#define CLASS_BROKEN_H 
class Broken
{
	protected:
		int n;
		Point* arr;
	public:
		Broken(int = 0, Point* = 0);
		Broken(const Broken&);
		virtual ~Broken();
		Broken& operator = (const Broken&);

		int getn();
		Point* getarr();

		void set(int, Point*);

		virtual void print();

};
#endif
