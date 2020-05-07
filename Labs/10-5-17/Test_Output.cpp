
#include "std_lib_facilities_5.h"

int main() {
	try {
		const unsigned short birth_year = 1995, age = 22;
		int a, b, c, d;
		vector<string> fnames = { "Luke", "Rebecca", "Kacy", "Jamie", "Mark", "Spencer" };
		vector<string> lnames = { "Grammer", "Rosamond", "Mayberry", "Ladnier", "Ketchersid", "Robinson" };
		vector<string> emails = { "Luke.grammer@tamu.edu", "Rebeccarosamond@tamu.edu", "kcatm995@gmail.com", 
								  "Jamie.ladnier@tccd.edu", "mkketchersid@gmail.com", "Spencer.robinson@hotmail.com" };
		vector<string> phones = { "817-437-4749", "214-592-7286", "817-559-2008", "214-683-9975", "817-988-6642", "817-888-0177" };

		cout << showbase;
		cout << setw(12) << left << "Octal:" << "\t" << oct << birth_year;
		cout << setw(12) << "\nDecimal:" << "\t" << dec << birth_year;
		cout << setw(12) << "\nHexadecimal:" << "\t" << hex << birth_year;
		cout << "\n\nAge:" << dec << age << "\n";

		cout << "\nEnter four numbers: ";
		cin >> a >> oct >> b >> hex >> c >> d;
		cout << a << '\t' << b << '\t' << c << '\t' << d << '\n';
		// Input is of different bases, not output. 
		// Since 1234 is valid in every base > 4, it's taking 1234 to be
		// an octal or hexadecimal number, and outputting its decimal value to the console

		cout << "\n" << 1234567.89;
		cout << "\n" << fixed << 1234567.89;
		cout << "\n" << scientific << 1234567.89 << "\n\n";
		// Fixed displays 13 significant figures, while the next closest, scientific, only displays 8.

		cout << setw(10) << "First:" << setw(13) << "Last:" << setw(31) << "emails:" << "phones:" << endl;
		for (unsigned i = 0; i < fnames.size(); i++) {
			cout << setw(10) << fnames[i] << setw(13) << lnames[i] << setw(31) << emails[i] << phones[i] << endl;
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