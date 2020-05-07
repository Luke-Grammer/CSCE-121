#include "Date.h"

ostream& Date::operator<<(ostream& os)
{
	return os << '(' << this->year()
		<< ',' << (int)this->month()
		<< ',' << this->day() << ')';
}

istream& Date::operator>>(istream& is) {
	double dd, m, y;

	is >> dd >> m >> y;

	if (!is) {
		if (is.eof()) return is;
		is.clear();
		is.ignore(numeric_limits<streamsize>::max(), '\n');
		throw Invalid{};
	}
	*this = Date(y, (Month)m, dd);
	return is;
}

bool Date::operator==( const Date& d2) {
	return (this->day() == d2.day() && this->month() == d2.month() && this->year() == d2.year());
}

bool Date::operator<(const Date& d2) {
	if (this->year() < d2.year()) {
		return true;
	}
	else if (this->year() > d2.year()) {
		return false;
	}
	else {
		if (this->month() < d2.month()) {
			return true;
		}
		else if (this->month() > d2.month()) {
			return false;
		}
		else {
			if (this->day() < d2.day()) {
				return true;
			}
			else return false;
		}
	}
}

bool Date::operator>(const Date& d2) {
	if (this->year() > d2.year()) {
		return true;
	}
	else if (this->year() < d2.year()) {
		return false;
	}
	else {
		if (this->month() > d2.month()) {
			return true;
		}
		else if (this->month() < d2.month()) {
			return false;
		}
		else {
			if (this->day() > d2.day()) {
				return true;
			}
			else return false;
		}
	}
}

const Date& Date::default_date() {
	static Date dd{ 2001, Month::Jan, 1 };
	return dd;
}

bool Date::is_LeapYear() {
	if (y % 100 != 0 && y % 4 == 0) {
		return true;
	}
	else return false;
}

bool Date::is_valid() {
	vector<int> monthLengths = { 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31 };
	if (is_LeapYear()) {
		monthLengths[1]++;
	}

	if (y < 1 || m < Month::Jan || m > Month::Dec) {
		return false;
	}
	else if (d > monthLengths[(int)(m)-1]) {
		return false;
	}
	else
		return true;
}

Date::Date()
	:y{ default_date().year() },
	m{ default_date().month() },
	d{ default_date().day() }
{
}

Date::Date(int yy, Month mm, int dd)
	:y{ yy }, m{ mm }, d{ dd }
{
	if (!is_valid())
		error("Invalid Date");
}

void Date::add_day(int n) {
	while (n > 0) {
		d++;
		if (is_valid())
			n--;
		else {
			d = 1;
			m = Month(int(m) + 1);
			if (is_valid())
				n--;
			else {
				m = Month::Jan;
				y++;
				if (is_valid())
					n--;
				else {
					error("Could not add days");
				}
			}
		}
	}
}

void Date::add_month(int n) {
	if (n > 28)
		error("Can't currently perform that operation while days is larger than 28");
	while (n > 0) {
		m = Month(int(m) + 1);
		if (is_valid()) {
			n--;
		}
		else {
			m = Month::Jan;
			y++;
			if (is_valid()) {
				n--;
			}
			else {
				error("Could not add months");
			}
		}
	}
}

void Date::add_year(int n) {
	while (n > 0) {
		y++;
		if (is_valid()) {
			n--;
		}
		else {
			error("Could not add years");
		}
	}
}