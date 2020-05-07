//Luke Grammer
//CSCE 121-513
//Due: October 31, 2017
//h5p3_525008438.cpp

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

const int WINDOW_SIZE_X = 640,
WINDOW_SIZE_Y = 480,
BUTTON_WIDTH = 70,
BUTTON_HEIGHT = 20,
RADIUS = 70;

int main()
try {
	Simple_window win1{ Point{ 100, 100 }, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Alternate Olympic Flag" }; // Initializes a window
	Color olympic_blue(fl_rgb_color(0x01, 0x85, 0xC8)); // Define custom colors for olympic rings
	Color olympic_yellow(fl_rgb_color(0xF2, 0xC3, 0x02));
	Color olympic_green(fl_rgb_color(0x01, 0x9E, 0x3E));
	Color olympic_red(fl_rgb_color(0xE1, 0x00, 0x24));
	Vector_ref<Circle> rings;

	Rectangle base1{ Point{ 0,0 }, Point{ win1.x_max() - BUTTON_WIDTH, win1.y_max() } }; // Creates two rectangles to fill window without covering button
	base1.set_fill_color(Color::black); // Set their color to black (background for flag)
	Rectangle base2{ Point{ win1.x_max() - BUTTON_WIDTH, BUTTON_HEIGHT }, Point{ win1.x_max(), win1.y_max() } };
	base2.set_fill_color(Color::black);

	win1.attach(base1); // Attach background to window
	win1.attach(base2);

	int h_space = -10;
	for (unsigned i = 1; i < 6; ++i) { // Loop through all rings (pun intended)
		int x = ((win1.x_max() - 6 * RADIUS) / 2) + (i * RADIUS + h_space); // Places ring in middle of screen and offsets it by an appropriate amount in x
		int y = (i % 2 == 0) ? (((win1.y_max() - 3 * RADIUS) / 2) + ((2 * RADIUS) + 10)) : (((win1.y_max() - 3 * RADIUS) / 2) + RADIUS); // Offsets every other ring in y
		rings.push_back(new Circle(Point(x, y), RADIUS)); // Adds new Circle to rings with appropriate coordinates and radius
		h_space += 5; // Adjust horizontal offset value
		rings[rings.size() - 1].set_style(Line_style{ Line_style::solid, 5 }); // Increase ring thickness to 5px
	}

	rings[0].set_color(olympic_blue); // Set rings to their appropriate color
	rings[1].set_color(olympic_yellow);
	rings[2].set_color(Color::white);
	rings[3].set_color(olympic_green);
	rings[4].set_color(olympic_red);

	for (unsigned i = 0; i < rings.size(); ++i) { // Loop through all rings again
		win1.attach(rings[i]); // Attach ring to window
	}

	win1.wait_for_button(); // Wait for button
	return 0;
}
catch (exception& e) { 
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Some exception\n";
	return 2;
}
