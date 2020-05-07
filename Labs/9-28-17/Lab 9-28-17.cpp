#include "Date.h"
#include "Date.cpp"

int main() {
	try {
		Date d1, d2;
		cout << "Please enter a date: ";
		//cin >> d1;
		cout << "Please enter another date: ";
		//cin >> d2;

		cout << endl;
		cout << "d1 < d2: " << endl;
		cout << "d1 == d2: " << endl;
		cout << "d1 > d2: " << endl;

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