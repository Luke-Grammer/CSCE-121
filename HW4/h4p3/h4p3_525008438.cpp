// Luke Grammer
// CSCE 121-513
// Due: October 5, 2017
// h4p3_525008438.cpp

#include "Chrono_525008438.h"

int main() {
	try {
		while (true) {
			Chrono::Date date = Chrono::Date();
			cout << "Please enter a date (yyyy,mm,dd) or enter\nCtrl-Z (Windows) or Ctrl-D (Unix) to Exit: ";
			if (cin >> date >> left >> right) { // Collecting user input
				cout << "Tomorrow is " << ++date << endl << endl; // Displaying the next day
			}
			else break;
		}
		return 0;
	}
	catch (Chrono::Date::Invalid) { // Catching Invalid Input
		cerr << "Error: Invalid Input." << endl;
		keep_window_open();
		return 1;
	}
	catch (exception& e) { // Catching natively defined errors in stdexcept.h
		cerr << "Error: " << e.what() << endl;
		keep_window_open();
		return 2;
	}
	catch (...) { // Catching all misc. errors
		cerr << "Oops!: The program has encountered an error and needs to close." << endl;
		keep_window_open();
		return 3;
	}
}
