// Luke Grammer
// CSCE 121-513
// Due: October 5, 2017
// h4p2_525008438.cpp

#include "randint_525008438.h"

int main() {
	try {
		const int SAMPLE_SIZE = 1000000, // Number of digits to produce and record (can be adjusted with changes to HIST_SENSITIVITY)
				  NUM_DIGITS = 10, // Number of digits (0-9 inclusive)
				  AVG_NUM_ASTERISKS = 40; // Number of asterisks to display for expected value of frequency
		const char HIST_CHAR = '*'; // Character to represent histogram
		const double HIST_SENSITIVITY = .90, // should be in the interval [0,1). Allows the user to see small variances in the frequency.
					 EXPECTED_VALUE = SAMPLE_SIZE / NUM_DIGITS; // Expected value of frequency

		// Using an array here executes the program over 10 times faster than an equivalent vector (0.06s avg.)
		int frequency[NUM_DIGITS] = {0}; // Array to store occurrences of each digit

		for (unsigned i = 0; i < SAMPLE_SIZE; i++) {
			// Create a pseudo-random number, find its last digit, and increment its corresponding element in frequency
			frequency[randint() % NUM_DIGITS]++;  
		}
		// Loop through all digits
		cout << setw(9) << left << "Digit" << "Frequency" << endl;
		for (unsigned i = 0; i < NUM_DIGITS; i++) {
			cout << setw(10) << left << i << setw(6) << right << frequency[i]; // Display frequencies
			cout << "\t" << string((frequency[i] - HIST_SENSITIVITY * EXPECTED_VALUE) / (((1 - HIST_SENSITIVITY) * EXPECTED_VALUE) / AVG_NUM_ASTERISKS), HIST_CHAR) << endl; // Display histogram
		}

		keep_window_open();
		return 0;
	}
	catch (exception& e) { // Catching natively defined errors in stdexcept.h
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
