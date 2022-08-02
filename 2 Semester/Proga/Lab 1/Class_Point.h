#ifndef CLASS_POINT_H 
#define CLASS_POINT_H 
class Point
{
	private:
		double x;
		double y;
	public:
		Point(double = 0, double = 0);
		Point(const Point&);
		Point& operator = (const Point&);

		double getx();
		double gety();

		void setx(double);
		void sety(double);

		void print();

};
#endif
