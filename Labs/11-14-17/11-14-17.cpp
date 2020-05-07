
#include "std_lib_facilities_5.h"

int main() {
	try {
		vector<int> v{ 1, 2, 3, 4, 5 };
		for (unsigned i = 0; i < v.size(); ++i) {
			cout << v[i] << " "; 
		}
		cout << endl;
		for (auto i : v) {
			cout << i << " ";
		}
		cout << endl;
		for (vector<int>::iterator i = v.begin(); i != v.end(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		for (vector<int>::reverse_iterator i = v.rbegin(); i != v.rend(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		for (vector<int>::const_iterator i = v.cbegin(); i != v.cend(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		for (vector<int>::const_reverse_iterator i = v.crbegin(); i != v.crend(); ++i) {
			cout << *i << " ";
		}
		cout << endl;
		keep_window_open();
		return 0;
	}
	catch (exception& e) {
		cerr << "Error: " << e.what() << endl;
		keep_window_open();
		return 1;
	}
	catch (...) {
		cerr << "The program encountered an unexpected problem and needs to close!" << endl;
		keep_window_open();
		return 2;
	}
}
