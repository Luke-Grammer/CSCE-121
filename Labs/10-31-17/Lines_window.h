#ifndef MY_WINDOW
#define MY_WINDOW

#include "Simple_window.h"

struct Lines_window : Graph_lib::Window {
	Lines_window(Point xy, int w, int h, const string& title);
	Open_polyline lines;
private:
	Button next_button; // add (next_x,next_y) to lines
	Button quit_button;
	In_box next_x;
	In_box next_y;
	Out_box xy_out;
	void next();
	void quit();
};

#endif
