#include <iostream>
#ifndef CLASS_POLYNOM_H 
#define CLASS_POLYNOM_H 

using namespace std;
class Polynom
{
	private:
		int n;
		double* arr;
	public:
		Polynom(int = 0, double* = 0);
		Polynom(const Polynom&);
		~Polynom();

		int getn();
		double* getarr();
		
		void set(int, double*);

		Polynom& operator = (const Polynom&);
		bool operator == (const Polynom&);
		bool operator != (const Polynom&);


		Polynom operator + (const Polynom&);
		Polynom operator - (const Polynom&);
		Polynom operator += (const Polynom&);
		Polynom operator -= (const Polynom&);

		Polynom& operator + ();
		Polynom& operator - ();

		Polynom operator * (double);
		Polynom operator / (double);

		Polynom operator *= (double);
		Polynom operator /= (double);

		double operator [] (int);

		friend ostream& operator << (ostream&, const Polynom&);
		friend istream& operator >> (istream&, Polynom&);


};
#endif