
#include "My_window.h"

My_window::My_window(Point xy, int w, int h, const string& title)
	:Window{ xy,w,h,title },
	next_button{ Point{ x_max() - 140,0 }, 70, 20, "Turn On",
	[](Address, Address pw) {reference_to<My_window>(pw).next(); } },
	quit_button{ Point{ x_max() - 70,0 }, 70, 20, "Exit",
	[](Address, Address pw) {reference_to<My_window>(pw).quit(); } },
	light(Point{ x_max() / 2, y_max() / 2 }, 40),
	light_color(Color::black),
	temp{ true }
{
	light.set_fill_color(light_color);
	attach(light);
	attach(next_button);
	attach(quit_button);
}

void My_window::quit() {
	hide();
}

void My_window::next() {
	if (temp) {
		light_color = Color::yellow;
		next_button.label = "Turn Off";
	}
	else {
		light_color = Color::black;
		next_button.label = "Turn On";
	}
	temp = !temp;

	light.set_fill_color(light_color);
	redraw();
}

