// Luke Grammer
// CSCE 121-513
// Due: September 26, 2017
// h3p1_525008438.cpp

#include "std_lib_facilities_5.h"

int main() {
	try {
		const double AMOUNT_TO_GIVE = 0.1,
					 AMOUNT_TO_SAVE = 0.1,
					 AMOUNT_TO_LIVE = 0.8;
		string incomeAsString;
		double income = 0.0;

		while (true) {
			cout << "What is your income in dollars? (Q to quit)" << endl;
			getline(cin, incomeAsString); // Collect user input

			if (tolower(incomeAsString[0]) == 'q')
				break; // Checking if exit character is entered 
			else if (incomeAsString[0] == '-')
				error("Negative Number"); // Making sure input is non-negative

			for (char c : incomeAsString) {
				if (!isdigit(c) && c != '.') {// Check input for illegal float values
					error("Invalid Input");
				}
			}

			income = atof(incomeAsString.c_str()); // Convert income to float

			cout << fixed << showpoint << setprecision(2) // Format output to always display mantissa and two following digits
				 << "You should give away about $" << income * AMOUNT_TO_GIVE // Output information
				 << ", save about $" << income * AMOUNT_TO_SAVE << ", and live on\n"
				 << "about $" << income * AMOUNT_TO_LIVE << "." << endl << endl;
		}
		return 0;
	}
	catch (exception& e) { // Catching 'Negative Number', 'Invalid Input', and natively defined errors in stdexcept.h
		cerr << "Error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) { // Catching all misc. errors
		cerr << "Oops!: The program has encountered an error and needs to close." << endl;
		keep_window_open();
		return 2;
	}
}
