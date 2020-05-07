#include "Date.h"

int main() {
	try {
		vector<Date> dates;
		dates.push_back(Date(2017, Month::Jan, 1));
		dates.push_back(Date(2018, Month::Jan, 1));
		dates.push_back(Date(2017, Month::Jan, 31));
		dates.push_back(Date(2017, Month::Feb, 1));
		dates.push_back(Date(2017, Month::Jan, 1));

		sort(dates.begin(), dates.end());

		for (int i = 0; i < dates.size(); ++i) {
			cout << dates[i] << endl;
		}
	
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "Oops!: The program has encountered an error and needs to close." << endl;
		keep_window_open();
		return 2;
	}
}