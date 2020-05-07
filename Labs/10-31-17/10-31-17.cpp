
#include "Lines_window.h"

int main()
try {
	Lines_window win{ Point{ 100,100 },600,400,"Light Bulb" };
	return gui_main();

	return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}


