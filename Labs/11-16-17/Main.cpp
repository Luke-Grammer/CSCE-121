#include "Date.h"

int main() {
	try {
		bool repeat = true;
		Date d1, d2;
		string ans;
		while (repeat) {
			cout << "Please enter a date d1 (yyyy mm dd): ";
			cin >> d1;
			cout << "Please enter another date d2 (yyyy mm dd): ";
			cin >> d2;

			cout << endl;
			cout << "d1 < d2: " << ((d1 < d2) ? "True" : "False") << endl;
			cout << "d1 == d2: " << ((!(d2 < d1 || d1 < d2)) ? "True" : "False") << endl;
			cout << "d1 > d2: " << ((d2 < d1) ? "True" : "False") << endl;

			cout << endl << "Would you like to enter another pair of dates? (y/n)" << endl;
			cin >> ans;
			if (ans == "N" || ans == "n" || ans == "No" || ans == "no") repeat = false;
			cout << endl;
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