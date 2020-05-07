// Luke Grammer
// CSCE 121-513
// Due: September 19, 2017
// h2p2_525008438.cpp

#include "std_lib_facilities_5.h"

class Invalid_Letter{};

int valueOfLetter(char c) { 
// Checks that a valid Roman numeral character was entered
// And returns its Roman numeral value
	if (c == 'i') {
		return 1;
	}
	else if (c == 'v') {
		return 5;
	}
	else if (c == 'x') {
		return 10;
	}
	else if (c == 'l') {
		return 50;
	}
	else if (c == 'c') {
		return 100;
	}
	else if (c == 'd') {
		return 500;
	}
	else if (c == 'm') {
		return 1000;
	}
	else
		throw Invalid_Letter{};
}

int romanNumeralToInt(string romanNumeral, int stringLength) {
	// Converts a Roman numeral to an integer value and returns that value.
	const int MIN_LENGTH = 0;
	int sum = 0, maxValue = 0, digitValue = 0;
	for (int i = stringLength - 1; i >= MIN_LENGTH; i--) {
		// For every element in input string (left to right)
		try {
			digitValue = valueOfLetter(tolower(romanNumeral[i]));
			// Assign digitValue with letters value (if valid)
		}
		catch(Invalid_Letter) {
			throw Invalid_Letter{}; 
			// If it was not valid, throw error back to main
		}
		
		if (digitValue >= maxValue) { // Give sum appropriate value
			sum += digitValue;
			maxValue = digitValue;
		}
		else {
			sum -= digitValue;
		}
	}
	return sum;
}

int main() {
	try {
		string romanNumeral;
		int value = 0;
		while(true) {
			cout << "Please enter a Roman numeral or enter Q to quit: ";
			cin >> romanNumeral; // User input
			
			if (tolower(romanNumeral[0]) == 'q') // If exit character entered, end loop
				break;
			
			value = romanNumeralToInt(romanNumeral, romanNumeral.length());
			// convert entered Roman numeral to integer and give that to value
			// (error thrown if invalid input string)
			
			cout << "The value is " << value << endl; // Display value
		}
		
		return 0;
	}
	catch(Invalid_Letter) { // If an invalid character is detected
		simple_error("An invalid character was detected. \nValid letters are I, V, X, L, C, D, M, or Q to Quit");
	}
	catch(...) { // All unaccounted for errors
		simple_error("The program has encountered an unexpected error and needs to close\n");
	}
}
