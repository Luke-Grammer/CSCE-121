// Luke Grammer
// CSCE 121-513
// Due: September 12, 2017
// h1p3_525008438.cpp

#include "std_lib_facilities_5.h"

// Decide if an integer is plural or not.
bool isPlural(int num) {
	if (num == 1 || num == -1)
		return true;
	else return false;
}

int main() {
	int num_pennies = 0, num_nickels = 0, num_dimes = 0, num_quarters = 0, num_half_dollars = 0;
	double total_value = 0.0; // Declare variables
	
	cout << "How many pennies do you have?" << endl; // Collect user input.
	cin >> num_pennies;
	cout << "How many nickels do you have?" << endl;
	cin >> num_nickels;
	cout << "How many dimes do you have?" << endl;
	cin >> num_dimes;
	cout << "How many quarters do you have?" << endl;
	cin >> num_quarters;
	cout << "How many half dollars do you have?" << endl;
	cin >> num_half_dollars;
	
	total_value = num_pennies + (5 * num_nickels) + (10 * num_dimes) + (25 * num_quarters)
				 + (50 * num_half_dollars); // Determine total value of coinage.
				 
	cout << endl << "You have " << num_pennies 
		 << ((isPlural(num_pennies)) ? " penny." : " pennies."); 
		 // Display number of pennies (ternary operator for use of word 'penny' if singular or 'pennies' if plural).
	cout << endl << "You have " << num_nickels 
		 << ((isPlural(num_nickels)) ? " nickel." : " nickels.");
		 // Display number of nickels in same fashion as pennies.
	cout << endl << "You have " << num_dimes 
		 << ((isPlural(num_dimes)) ? " dime." : " dimes.");
		 // Display number of dimes in same fashion as pennies.
	cout << endl << "You have " << num_quarters 
		 << ((isPlural(num_quarters)) ? " quarter." : " quarters.");
		 // Display number of quarters in same fashion as pennies.
	cout << endl << "You have " << num_half_dollars 
		 << ((isPlural(num_half_dollars)) ? " half dollar." : " half dollars.") << endl;
		 // Display number of half dollars in same fashion as pennies.
		 
	cout << "The value of all your coins is $" << fixed << showpoint << setprecision(2) << total_value / 100.0 << "." << endl << endl;
	// display total value in the form $X.XX
	
	keep_window_open();
	return 0;
} 


