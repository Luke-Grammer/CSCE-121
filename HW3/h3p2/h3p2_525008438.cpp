// Luke Grammer
// CSCE 121-513
// Due: September 26, 2017
// h3p2_525008438.cpp

#include "std_lib_facilities_5.h"

double my_cbrt_1(double n) { // Function returns approximate cube root of n according to a Padé approximant
	long double rootNumerator = 0.0;
	long double rootDenominator = 0.0; // Declaring and initializing variables

	rootNumerator = 101.639 * pow(n, 2) + 207.853 * n + 29.7541; // Calculating numerator of Padé Approximant
	rootDenominator = -1 * pow(n, 3) + 42.945 * pow(n, 2) + 215.165 * n + 82.1357; // Calculating denominator of Padé Approximant

	return rootNumerator / rootDenominator; // Returning numerator divided by denominator
}

int main() {
	try {
		double n = 0.0; // Declaring and initializing n

		for (auto k : { -100, -10, -1, 0, 1, 10, 100 }) { // Iterate k through list of integers
			n = M_PI * pow(10.0, k); // multiply pi (constant defined in standard library file math.h) by 10^k and assign to n
			cout << "k = " << k << endl; // Output value of k
			cout << setw(13) << "n:" << setw(13) << n << endl; // Output value of n
			cout << setw(13) << "cbrt(n):" << setw(13) << cbrt(n) << endl; // Output exact value of n^(1/3)
			cout << setw(13) << "my_cbrt_1(n):" << setw(13) << my_cbrt_1(n) << endl << endl; // Output approximate value of n^(1/3)
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

