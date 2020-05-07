// Luke Grammer
// CSCE 121-513
// Due: September 19, 2017
// h2p3_525008438.cpp

#include "std_lib_facilities_5.h"

class Invalid_Input{};
class Input_Out_Of_Bounds{};

int valueOfLetter(char c) {	
// Checks that a valid Roman numeral character was entered
// And returns its Roman numeral value
	switch(c) {
		case 'i': return 1;
			break;
		case 'v': return 5;
			break;
		case 'x': return 10;
			break;
		case 'l': return 50;
			break;
		case 'c': return 100;
			break;
		case 'd': return 500;
			break;
		case 'm': return 1000;
			break;
		default: throw Invalid_Input{};
	}
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
		catch(Invalid_Input) {
			throw Invalid_Input{};
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
		string selectionAsRoman;
		int selection = 0;
		vector<string> amendments = {
			"The first amendment establishes freedom of religion, \n"
			"speech, and press, as well as assembly and petition. \n", // First amendment
			"The second amendment establishes the right of the \n"
			"people to keep and bear arms. \n", // Second amendment
			"The third amendment states that no troops shall be \n"
			"quartered on private property without consent of the \n"
			"owner of said property. \n", // Third amendment
		 	"The fourth amendment protects against unreasonable \n"
			"searches and seizures, as well as warrants issued \n"
			"without probable cause. \n", // Fourth amendment
		 	"The fifth amendment establishes double jeopardy and \n"
			"guarantees due process, as well as protects against \n"
			"appropriation of land without just compensation, \n"
			"and self-incrimination \n", // Fifth amendment
		 	"The sixth amendment grants the right to a speedy and \n"
			"public trial by jury, and the right to fair counsel. \n", // Sixth amendment
		 	"The seventh amendment states that the right to a trial \n"
			"by jury shall not be infringed upon in civil cases \n"
			"with a value exceeding 20 dollars. \n", // Seventh amendment
		 	"The eighth amendment protects against excessive bail \n"
			"and cruel and unusual punishment. \n", // Eighth amendment
		 	"The ninth amendment states that other unenumerated \n"
			"rights exist which may not be infringed upon. \n", // Ninth amendment
			"The last amendment in the bill of rights states that \n"
			"all powers not explicitly given to the federal \n"
			"government are to be retained by the states or the people.\n"}; // Tenth amendment
	
		while (true) {
			cout << "Select an amendment (I-X) or enter Q to quit: ";
			cin >> selectionAsRoman; // Collect user input
			
			if (tolower(selectionAsRoman[0]) == 'q') // Check for exit character
				break; // If exit character is found, exit loop
				
			selection = romanNumeralToInt(selectionAsRoman, selectionAsRoman.length());
			// convert entered Roman numeral to integer and give that to value
			// (error thrown if invalid input string)
			
		    if (selection < 1 || selection > 10) {
		    	throw Input_Out_Of_Bounds{}; // Range checking
  	 		}
	
			if (selection == 1) {
				cout << amendments[0]; // First amendment
			}
			else if (selection == 2) {
				cout << amendments[1]; // Second amendment
			}
			else if (selection == 3) {
				cout << amendments[2]; // Third amendment
			}
			else if (selection == 4) {				 
				cout << amendments[3]; // Fourth amendment
			}	     
			else if (selection == 5) {
				cout << amendments[4]; // Fifth amendment	
			}
			else if (selection == 6) {
				cout << amendments[5]; // Sixth amendment
			}	 
			else if (selection == 7) {
				cout << amendments[6]; // Seventh amendment
			}
			else if (selection == 8) {
				cout << amendments[7]; // Eighth amendment
			}
			else if (selection == 9) {
				cout << amendments[8]; // Ninth amendment
			}
			else if (selection == 10) {
				cout << amendments[9]; // Tenth amendment
			}
			else throw Input_Out_Of_Bounds{}; // Extra range checking
			
			cout << endl;
		}
	
		return 0;
	}
	catch(Input_Out_Of_Bounds){ // If converted input is not between 1 and 10
		simple_error("Your input is out of bounds.\nNext time enter a valid roman numeral I-X.");
	}
	catch(Invalid_Input){ // If an invalid character is detected
		simple_error("An invalid character was detected. \nValid letters are I, V, X, L, C, D, M, or Q to Quit");
	}
	catch(...) { // All unaccounted for errors
		simple_error("The program has encountered an unexpected error and needs to close\n");
	}
}
