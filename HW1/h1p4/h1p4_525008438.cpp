// Luke Grammer
// CSCE 121-513
// Due: September 12, 2017
// h1p4_525008438.cpp

#include "std_lib_facilities_5.h"

int main() {
	int fact = 1;	//0!
	
	cout << "Factorial calculator v1.0" << endl;
	
	for(int n = 1; n <=20; ++n){
		fact *= n; // Multiply by current n to determine factorial value for n.
		cout << n << "! == " << fact << endl; // Display factorial value.
	}
	cout << endl;
	
	cout << "This program produced some strange values since the maximum " << endl
		 << "value of an integer in c++ is 2^31 - 1 or 2,147,483,647. Trying " << endl
		 << "to exceed that value will cause the value of the int to overflow and " << endl 
		 << "wrap around to the smallest integer it may contain, -2^31." << endl << endl;
		 
	keep_window_open();
	return 0;
}
