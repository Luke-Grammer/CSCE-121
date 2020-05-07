//Luke Grammer
//CSCE 121-513
//Due: October 31, 2017
//h5p1_525008438.cpp

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

const int WINDOW_SIZE_X = 640,
WINDOW_SIZE_Y = 480,
BUTTON_WIDTH = 70,
BUTTON_HEIGHT = 20;

int main() // Draws a Texas flag in the center of a 480p window
try {
	Simple_window win1{ Point{100, 100}, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Texas Flag" }; // Initializes a window
	
	Rectangle base1{ Point{0,0}, Point{win1.x_max() - BUTTON_WIDTH, win1.y_max()} }; // Creates two rectangles to fill window without covering button
	base1.set_fill_color(Color::black); // Set their color to black (background for flag)
	Rectangle base2{ Point{win1.x_max() - BUTTON_WIDTH, BUTTON_HEIGHT}, Point{win1.x_max(), win1.y_max()} };
	base2.set_fill_color(Color::black);

	// Total flag width: 200. Total flag length: 300. Flag width to length ratio: 2:3.
	Rectangle rec1{ Point{170, 140}, Point{270, 340} }; // Create 100x200 Blue field for flag (width 1/3 total length of flag)
	rec1.set_fill_color(Color::dark_blue);
	rec1.set_color(Color::dark_blue);

	Rectangle rec2{ Point{270, 140}, Point{470, 240} }; // Upper horizontal 200x100 stripe (1/2 flag width, 2/3 flag length)
	rec2.set_fill_color(Color::white);
	rec2.set_color(Color::white);

	Rectangle rec3{ Point{270, 240}, Point{470, 340} }; // Lower horizontal 200x100 stripe (same dimensions as upper stripe)
	rec3.set_fill_color(Color::red);
	rec3.set_color(Color::red);

	Closed_polyline star_triangles; // Constructs outer triangles of star with 5 lines (radius 3/4 of vertical bar width)
	star_triangles.add(Point{220, 202});
	star_triangles.add(Point{242, 270});
	star_triangles.add(Point{184, 228});
	star_triangles.add(Point{256, 228});
	star_triangles.add(Point{198, 270});
	star_triangles.set_fill_color(Color::white);
	star_triangles.set_color(Color::white);

	Closed_polyline star_pentagon; // Creates a pentagon to fill inside of star
	star_pentagon.add(Point{211, 228});
	star_pentagon.add(Point{229, 228});
	star_pentagon.add(Point{234, 244});
	star_pentagon.add(Point{220, 255});
	star_pentagon.add(Point{205, 244});
	star_pentagon.set_fill_color(Color::white);
	star_pentagon.set_color(Color::white);

	win1.attach(base1); // Attach shapes to window
	win1.attach(base2);
	win1.attach(rec1);
	win1.attach(rec2);
	win1.attach(rec3);
	win1.attach(star_triangles);
	win1.attach(star_pentagon);
	win1.wait_for_button(); // Wait for button
	return 0;
}
catch(exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops! An unexpected error occured, please try again.\n";
	return 2;
}
