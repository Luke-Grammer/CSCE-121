#ifndef DATE
#define DATE

#include "std_lib_facilities_5.h"

class Invalid{};

enum class Month {
	Jan = 1, Feb, Mar, Apr, May, Jun, Jul, Aug, Sep, Oct, Nov, Dec, Test
};

class Date {
public:
	Date();
	Date(int y, Month m, int d);
	void add_day(int n);
	void add_month(int n);
	void add_year(int n);
	const Date& default_date();

	int day() const { return d; };
	Month month() const { return m; };
	int year() const { return y; };

	friend ostream& operator<<(ostream& os, const Date& dd);
	friend istream& operator>>(istream& is, Date& dd);
	bool operator==(const Date& d2);
	bool operator<(const Date& d2);
	bool operator>(const Date& d2);

private:

	bool is_LeapYear();
	bool is_valid();
	int y;
	Month m;
	int d;
};



#endif