// Luke Grammer
// CSCE 121-513
// Due: September 26, 2017
// h3p3_525008438.cpp

#include "std_lib_facilities_5.h"

double my_cbrt_1(double n) { // Function returns approximate cube root of n according to a Padé approximant
	long double rootNumerator = 0.0;
	long double rootDenominator = 0.0; // Declaring and initializing variables

	rootNumerator = 101.639 * pow(n, 2) + 207.853 * n + 29.7541; // Calculating numerator of Padé Approximant
	rootDenominator = -1 * pow(n, 3) + 42.945 * pow(n, 2) + 215.165 * n + 82.1357; // Calculating denominator of Padé Approximant

	return rootNumerator / rootDenominator; // Returning numerator divided by denominator
}

double my_cbrt_2(double n) { // Function returns approximate cube root of n, further improving accuracy of Padé approximant
	double result = 1.0;
	bool isNegative = false; // Flag for negative input

	if (n == 0.0)
		return 0; // If n is equal to zero, return 0
 	if (n < 0) { // If n is negative, take the absolute value of n and set flag to true
		n = abs(n);
		isNegative = true;
	}

	while (n < 1.05) { // Using algorithm provided by professer Daugherity
		result /= (9.0 / 8.0);
		n *= pow(9.0 / 8.0, 3);
	}
	while (n > 1.55) {
		result *= (9.0 / 8.0);
		n /= pow(9.0 / 8.0, 3);
	}

	if (isNegative) // If the flag is true
		return -1 * result * my_cbrt_1(n); // Return the negative of the value calculated
	else
		return result * my_cbrt_1(n); // Otherwise, return value calculated

}

int main() {
	try {
		vector<double> n = { -1.0e-100, -1.0e-10, -1.0, 0.0, 1.0, 1.0e+10, 1.0e+100 };
		for (unsigned int i = 0; i < n.size(); i++) { // Traversing n
			cout << setw(13) << "n:" << setw(13) << n[i]; // Output value of n
			cout << setw(9) << "Error:" << setw(12) << 100 * abs((my_cbrt_2(n[i]) - cbrt(n[i])) / cbrt(n[i]))
				 << "%" << endl; // On column 2, output the relative error of the cube root approximation given by the above equation.
			cout << setw(13) << "cbrt(n):" << setw(13) << cbrt(n[i]) << endl; // Output exact value of n^(1/3)
			cout << setw(13) << "my_cbrt_2(n):" << setw(13) << my_cbrt_2(n[i]) << endl << endl; // Output approximate value of n^(1/3)

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

