// Luke Grammer
// CSCE 121-513
// Due: October 5, 2017
// h4p1_525008438.cpp

#include "randint_525008438.h"

int main() {
	try {
		const int SAMPLE_SIZE = 1000000, // Number of digits to produce and record
				  NUM_DIGITS = 10; // Number of digits (0-9 inclusive)

		// Using an array here executes the program over 10 times faster than an equivalent vector (0.06s avg.)
		int frequency[NUM_DIGITS] = {0}; // Array to store occurrences of each digit

		for (unsigned i = 0; i < SAMPLE_SIZE; i++) {
			// Create a pseudo-random number, find its last digit, and increment its corresponding element in frequency
			frequency[randint() % NUM_DIGITS]++;  
		}
		// Loop through all digits
		for (unsigned i = 0; i < NUM_DIGITS; i++) {
			cout << "There were " << setw(6) << frequency[i] << " " << i << "'s." << endl; // Display frequencies
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
