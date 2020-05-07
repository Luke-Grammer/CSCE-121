//Luke Grammer
//CSCE 121-513
//Due: October 31, 2017
//h5p4_525008438.cpp

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"
#include<complex>

const int WINDOW_SIZE_X = 1280, // Global constants
WINDOW_SIZE_Y = 720,
NUM_POINTS = 1024,
BUTTON_WIDTH = 70,
BUTTON_HEIGHT = 20;

int H(double x) { // Heaviside Step Function (unit step function)
	if (x >= 0) return 1; // If positive, return 1
	else return 0; // If anything else, return 0
}

int sgn(double x) { // Sign function
	if (signbit(x)) return -1; // If the number is negative, return -1
	else if (x == 0) return 0; // If the number is zero, return 0
	else return 1; // If the number is positive, return 1
}

double w(double x) { // 'w' in formula
	complex<double> radicand( 1 - pow(x / 7.0, 2));
	return 3 * real(sqrt(radicand));
}

double l(double x) { // 'l' in formula
	complex<double> radicand(4 - pow(x + 1, 2));
	return 0.5 * (x + 3) - (3.0 / 7.0) * sqrt(10) * real(sqrt(radicand)) + (6.0 / 7.0) * sqrt(10);
}

double r(double x) { // 'r' in formula
	complex<double> radicand(4 - pow(x - 1, 2));
	return 0.5 * (3 - x) - (3.0 / 7.0) * sqrt(10) * real(sqrt(radicand)) + (6.0 / 7.0) * sqrt(10);
}

double h(double x) { // 'h' in formula
	return 0.5 * (3 * (abs(x + 0.5) + abs(x - 0.5) + 6) - 11 * (abs(x - 3.0 / 4.0) + abs(x + 3.0 / 4.0)));
}

double g(double x) { // 'g(x)' in formula (bottom half of logo)
	complex<double> radicand1(1 - pow(abs(abs(x) - 2) - 1, 2));
	complex<double> radicand2(1 - pow((1.0 / 7.0) * x, 2));
	return 0.5 * (abs(0.5 * x) + real(sqrt(radicand1)) - (1.0 / 112.0) * (3 * sqrt(33) - 7) * x * x + 3 * real(sqrt(radicand2)) - 3) * (sgn(x + 4) - sgn(x - 4)) - 3 * real(sqrt(radicand2));
}

double f(double x) { // 'f(x)' in formula (top half of logo)
	return (h(x) - l(x)) * H(x + 1) + (r(x) - h(x)) * H(x - 1) + (l(x) - w(x)) * H(x + 3) + (w(x) - r(x)) * H(x - 3) + w(x);
}

int main()
try {
	Simple_window win1{ Point{ 100, 100 }, WINDOW_SIZE_X, WINDOW_SIZE_Y, "Batman" }; // Initializes a window

	Color batman_yellow(fl_rgb_color(255, 208, 70)); // Define color batman_yellow

	Rectangle base1{ Point{ 0,0 }, Point{ win1.x_max() - BUTTON_WIDTH, win1.y_max() } }; // Creates two rectangles to fill window without covering button
	base1.set_fill_color(Color::black); // Set their color to black (For a background)
	Rectangle base2{ Point{ win1.x_max() - BUTTON_WIDTH, BUTTON_HEIGHT }, Point{ win1.x_max(), win1.y_max() } };
	base2.set_fill_color(Color::black);
	Ellipse base3{ Point{ win1.x_max() / 2, win1.y_max() / 2}, 400, 200 }; // Create an ellipse to house the logo
	base3.set_fill_color(batman_yellow); // Set its color to batman_yellow

	Function func1(f, -7.0, 7.0, Point{ win1.x_max() / 2, win1.y_max() / 2 }, NUM_POINTS, 50, 50); // Find points on f(x)
	Function func2(g, -7.0, 7.0, Point{ win1.x_max() / 2, win1.y_max() / 2 }, NUM_POINTS, 50, 50); // Find points on g(x)
	
	Closed_polyline batman; // Create a Closed_polyline to hold points

	for (unsigned i = 0; i < func1.number_of_points(); ++i) { // Add points from f(x)
		batman.add(func1.point(i));
	}
	for (unsigned i = func2.number_of_points() - 1; i < func2.number_of_points(); --i) { // Add points from g(x) in reverse order
		batman.add(func2.point(i));
	}

	batman.set_fill_color(Color::black); // Set fill color to black
	
	win1.attach(base1); // Attach background, logo housing, and logo
	win1.attach(base2);
	win1.attach(base3);
	win1.attach(batman);

	win1.wait_for_button(); // Wait for button
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
