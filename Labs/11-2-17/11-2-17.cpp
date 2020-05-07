
#include "My_window.h"
#include "Lines_window.h"

int main()
try {
	My_window win{ Point{ 100,100 },600,400,"Light Bulb" };
	Lines_window win1{ Point{ 100,100 },600,400,"Coordinates" };
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


