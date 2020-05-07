#ifndef MY_WINDOW
#define MY_WINDOW

#include "Simple_window.h"

struct My_window : Graph_lib::Window {
	My_window(Point xy, int w, int h, const string& title);

	private:
	Button next_button;
	Button quit_button;
	Circle light;
	Color light_color;
	bool temp;
	void quit();
	void next();
};

#endif
