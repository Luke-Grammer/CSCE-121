
#include "Point.h"

class FileIOException {};

int main() {
	try {
		const int NUM_POINTS = 7; // The number of points to be used
		const char filepath[] = "H:\\CSCE121\\Lab 10-3-17\\mydata.txt"; // Filepath to be used
		vector<Point> original_points, processed_points;
		Point p = Point();

		cout << "Please enter " << NUM_POINTS << " valid x y pairs in the form (x,y): " << endl;

		for (unsigned i = 0; i < NUM_POINTS; i++) { // Reading points from user
			cin >> p;
			original_points.push_back(p);
		}

		ofstream ost{ filepath }; // Opening output filestream
		if (!ost) {
			throw FileIOException{};
		}
		cout << "\nOriginal points: " << endl;
		for (unsigned i = 0; i < original_points.size(); i++) { // Outputting to console and file
			cout << original_points[i] << endl;
			ost << original_points[i] << endl;
		}
		ost.close();

		ifstream ist{ filepath }; // Opening input filestream
		if (!ist) {
			throw FileIOException{};
		}

		while (ist >> p) { // Reading from file
			processed_points.push_back(p);
		}
		if (ist.eof()) { 
			ist.close();
		}
		else if (ist.fail() || ist.bad()) {
			throw FileIOException();
		}

		cout << "\nProcessed points from mydata.txt: " << endl;
		for (unsigned i = 0; i < processed_points.size(); i++) { // Outputting processed points to console
			cout << processed_points[i] << endl;
			ost << processed_points[i] << endl;
		}

		for (unsigned i = 0; i < processed_points.size(); i++) { // Checking processed points against originals
			if (processed_points[i].getX() != original_points[i].getX() || processed_points[i].getY() != original_points[i].getY()) {
				cout << "\nSomething's wrong!" << endl;
				break;
			}
		}

		cout << "\nNo discrepancies detected!" << endl;
		keep_window_open();
		return 0;
	}
	catch (Invalid) { // Invalid point input format (defined in Point.h)
		cout << "Error: Invalid input." << endl;
		keep_window_open();
		return 1;
	}
	catch (FileIOException) {
		cout << "Error: There was a problem with reading from or writing to the file." << endl;
		keep_window_open();
		return 2;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		keep_window_open();
		return 3;
	}
	catch (...) {
		cerr << "Oops, the problem has encountered an error and needs to close!" << endl;
		keep_window_open();
		return 4;
	}
}