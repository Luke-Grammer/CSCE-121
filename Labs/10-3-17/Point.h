
#include "std_lib_facilities_5.h"

class Invalid {};

class Point {
public: 
	Point(double x, double y);
	Point();
	double getX() { return x; };
	double getY() { return y; };
	void setX(double n) { x = n; };
	void setY(double n) { y = n; };

private:
	double x, y;
};

Point::Point(double xx, double yy) 
	: y{ yy }, x{ xx }
{
}

Point::Point()
	: y{ 0.0 }, x{ 0.0 }
{
}

istream& operator >> (istream& is, Point& point) {
	double x, y;
	char ch1, ch2, ch3;
	is >> ch1 >> x >> ch2 >> y >> ch3;
	if (!is || ch1 != '(' || ch2 != ',' || ch3 != ')') {
		if (is.eof()) return is;
		is.clear();
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		throw Invalid{};
	}
	point = Point(x, y);
	return is;
}

ostream& operator << (ostream& os, Point& point) {
	return os << "(" << point.getX() << "," << point.getY() << ")";
}