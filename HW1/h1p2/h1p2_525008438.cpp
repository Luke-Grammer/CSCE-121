// Luke Grammer
// CSCE 121-513
// Due: September 12, 2017
// h1p2_525008438.cpp

#include "std_lib_facilities_5.h"

int main() {
	string operation = "";
	double num1 = 0.0, num2 = 0.0;
	
	// Get input and continue getting input
	cout << "Enter an operation followed by two numbers. (CTRL-Z to quit or CTRL-D for Unix)" << endl;
	while(cin >> operation >> left >> right) {
		cin >> num1 >> num2;
		
		// Convert operation to lowercase
		for(unsigned int i = 0; i < operation.length(); i++)
			operation[i] = tolower(*(operation.c_str() + i));

		if (operation == "+" || operation == "add")
			cout << num1 + num2 << endl; // Perform and display addition.
		else if (operation == "-" || operation == "sub")
			cout << num1 - num2 << endl; // Perform and display subtraction.
		else if (operation == "*" || operation == "mul")
			cout << num1 * num2 << endl; // Perform and display multiplication.
		else if (operation == "/" || operation == "div") {
			if (num2 != 0) {
				cout << num1 / num2 << endl; // If num2 is not zero, perform and display division. 				
			}
			else 
				simple_error("ERROR: Division by Zero.");
				// Error if num2 equals zero and division is requested.
		}
		else simple_error("ERROR: Unrecognized operation, try ADD, SUB, MUL, or DIV (not case sensitive)");
		// Error if operation is unrecognized.
	}
	
	cout << endl;
	keep_window_open();
	return 0;
}
