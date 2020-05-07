// Luke Grammer
// CSCE 121-513
// Due: September 19, 2017
// h2p4_525008438.cpp

#include "std_lib_facilities_5.h"

class Invalid_Input{};
class Input_Out_Of_Bounds{};

int createHash(const char s[]) {
	// Takes an array of characters and returns a unique integer value. 
	int sum = tolower(s[0]); 
	// Initialize sum with the ASCII value of first letter converted to lowercase 
	int hash = sum - 2 * 'c'; 
	// Initialize hash with sum minus twice the smallest valid character for this application
	while (*s++) { 
	// If *s still points to a valid char, increment the pointers address by one char and continue
		sum += tolower(s[0]); // Add the next value converted to lowercase to sum 
		hash += sum; // Add sum to hash
	}
	return hash;
}

int main() {
	try {
		string selectionAsRoman;
		int selection = 0;
		vector<char> validLetters = {'i','v','x','l','c','d','m'}; 
		// Vector of valid Roman numeral letters
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
			cin >> selectionAsRoman; // Read user input as string
			
			if(tolower(selectionAsRoman[0]) == 'q') // Check if exit character is entered
				break; // If exit character is detected, exit loop 
				
			for (unsigned int i = 0; i < selectionAsRoman.length(); i++) {
				// For length of input string
				bool isValid  = false; // Initialize valid character check
				for (unsigned int j = 0; j < validLetters.size(); j++) {
					// For all valid letters
					if(tolower(selectionAsRoman[i]) == validLetters[j]) {
						// If current letter of input string matches a valid letter
						isValid = true; // Update valid character check
						break; // Exit inside loop
					}
				}
				if (!isValid) {
					// If current letter of input string does not match any valid characters
					throw Invalid_Input{};
				}			
			}

			selection = createHash(selectionAsRoman.c_str()); 
			// Convert selectionAsRoman to a unique integer and pass it to selection 
		
			switch(selection) {
				case 12:
					cout << amendments[0]; // First amendment
					break;
				case 327:
					cout << amendments[1]; // Second amendment
					break;
				case 747: 
					cout << amendments[2]; // Third amendment
					break;
				case 353:
					cout << amendments[3]; // Fourth amendment
					break;
				case 38:
					cout << amendments[4]; // Fifth amendment
					break;
				case 366:
					cout << amendments[5]; // Sixth amendment
					break;
				case 799:
					cout << amendments[6]; // Seventh amendment
					break;
				case 1337:
					cout << amendments[7]; // Eighth amendment
					break;
				case 357:
					cout << amendments[8]; // Ninth amendment
					break;
				case 42:
					cout << amendments[9]; // Tenth amendment
					break;
				default:
					throw Input_Out_Of_Bounds{}; 
			}
			cout << endl;
		}
	
		return 0;
	}
	catch(Input_Out_Of_Bounds){ // If the value of the roman numeral input is a number less than 1 or greater than 10
		simple_error("Your input is formatted incorrectly or out of bounds.\nNext time enter a valid roman numeral I-X.");
	}
	catch(Invalid_Input){ // If an invalid character is detected
		simple_error("An invalid character was detected. \nValid letters are I, V, X, L, C, D, M, or Q to Quit");
	}
	catch(...) { // All unaccounted for errors
		simple_error("The program has encountered an unexpected error and needs to close\n");
	}
}
