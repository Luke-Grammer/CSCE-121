// Luke Grammer
// CSCE 121-513
// Due: September 19, 2017
// h2p1_525008438.cpp

#include "std_lib_facilities_5.h"

class Invalid_Input{};
class Input_Out_Of_Bounds{};

int main() {
	try {
		string selectionAsString;
		int selection = 0; // Variable declarations
		
		while (true) {
			cout << "Select an amendment (1-10) or enter Q to quit: ";
			cin >> selectionAsString;
			if (tolower(selectionAsString[0]) == 'q') // Checking if exit character is entered 
				break;	// Immediately exit loop if exit character is entered
				
			for (unsigned int i = 0; i < selectionAsString.length(); i++){
				if (!isdigit(selectionAsString[i]))
					throw Invalid_Input{};
			// If exit character not found, make sure an integer was entered
			}
			
			selection = atoi(selectionAsString.c_str()); 
			// Convert input to integer
			
		    if (selection < 1 || selection > 10) { // Range checking
		    	throw Input_Out_Of_Bounds{};
	    	}
		
			if (selection == 1) { // First amendment
				cout << "The first amendment establishes freedom of religion, \n"
			         << "speech, and press, as well as assembly and petition. \n";
			}
			else if (selection == 2) { // Second amendment
				cout << "The second amendment establishes the right of the \n" 
					 << "people to keep and bear arms. \n";
			}
			else if (selection == 3) { // Third amendment
				cout << "The third amendment states that no troops shall be \n"
					 << "quartered on private property without consent of the \n"
					 << "owner of said property. \n";	
			}
			else if (selection == 4) { // Fourth amendment
				cout << "The fourth amendment protects against unreasonable \n"
					 << "searches and seizures, as well as warrants issued \n"
					 << "without probable cause. \n";	
			}	     
			else if (selection == 5) { // Fifth amendment
				cout << "The fifth amendment establishes double jeopardy and \n"
					 << "guarantees due process, as well as protects against \n"
					 << "appropriation of land without just compensation, \n"
					 << "and self-incrimination \n";			
			}
			else if (selection == 6) { // Sixth amendment
				cout << "The sixth amendment grants the right to a speedy and \n"
					 << "public trial by jury, and the right to fair counsel. \n";			
			}	 
			else if (selection == 7) { // Seventh amendment
				cout << "The seventh amendment states that the right to a trial \n"
					 << "by  jury shall not be infringed upon in civil cases \n"
					 << "with a value exceeding 20 dollars. \n";			
			}
			else if (selection == 8) { // Eighth amendment
				cout << "The eighth amendment protects against excessive bail \n"
					 << "and cruel and unusual punishment. \n";			
			}
			else if (selection == 9) { // Ninth amendment
				cout << "The ninth amendment states that other unenumerated \n"
					 << "rights exist which may not be infringed upon. \n";			
			}
			else if (selection == 10) { // Tenth amendment
				cout << "The last amendment in the bill of rights states that \n"
			       	 << "all powers not explicitly given to the federal \n"
			   	     << "government are to be retained by the states or the people.\n";
			}
			else {
				throw Input_Out_Of_Bounds{};
				// Extra range checking
			}
			
			cout << endl;
		}
	
		return 0;
	}
	catch(Invalid_Input) { // If a non-integer number or invalid character is entered 
		simple_error("An invalid character was entered. \nNext time enter a valid integer between 1 and 10.");
	}
	catch(Input_Out_Of_Bounds) { // If input is a number less than 1 or greater than 10
		simple_error("Your input is out of bounds. \nNext time enter a valid integer between 1 and 10.");
	}
	catch(...) { // For unaccounted for errors.
		simple_error("The program has encountered an unexpected error and needs to close\n");
	}
}
