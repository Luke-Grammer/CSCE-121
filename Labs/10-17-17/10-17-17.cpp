#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

int NUM_GRIDLINES = 8;
int GRID_SIZE = 100;

int main()
try {
	Simple_window win1(Point(100,200),800,1000,"Grid"); // Make a simple window
	
	Lines grid;

	for (int i = GRID_SIZE; i <= NUM_GRIDLINES * GRID_SIZE; i += GRID_SIZE){
		grid.add(Point{i, 0}, Point{i, NUM_GRIDLINES * GRID_SIZE});
		grid.add(Point{0, i}, Point{NUM_GRIDLINES * GRID_SIZE, i});
	}

	win1.attach(grid);

	Image logo1 {Point{0,200}, "10-17-17_photo.jpg"};
	win1.attach(logo1);

	Image logo2 {Point{0,400}, "10-17-17_photo.jpg"};
	win1.attach(logo2);

	Image logo3 {Point{0,600}, "10-17-17_photo.jpg"};
	win1.attach(logo3);

	Rectangle rect1(Point(0,0), 100, 100);
	rect1.set_fill_color(Color::red); 
	win1.attach(rect1);

	Rectangle rect2(Point(100,100), 100, 100);
	rect2.set_fill_color(Color::red); 
	win1.attach(rect2);

	Rectangle rect3(Point(200,200), 100, 100);
	rect3.set_fill_color(Color::red); 
	win1.attach(rect3);
	
	Rectangle rect4(Point(300,300), 100, 100);
	rect4.set_fill_color(Color::red); 
	win1.attach(rect4);

	Rectangle rect5(Point(400,400), 100, 100);
	rect5.set_fill_color(Color::red); 
	win1.attach(rect5);

	Rectangle rect6(Point(500,500), 100, 100);
	rect6.set_fill_color(Color::red); 
	win1.attach(rect6);

	Rectangle rect7(Point(600,600), 100, 100);
	rect7.set_fill_color(Color::red); 
	win1.attach(rect7);

	Rectangle rect8(Point(700,700), 100, 100);
	rect8.set_fill_color(Color::red); 
	win1.attach(rect8);

	Image logo4 {Point{0,0}, "vault_boy.jpg"};
	win1.attach(logo4);

	int i = 0;
	int shift = 0;
	while(win1.wait_for_button()) {

		if (i < 7) {
			logo4.move(100, 0);
			i++;
		}
		else if (shift < 7) {
			logo4.move(-700, 100);
			shift++;
			i = 0;
		}
		else {
			logo4.move(-700, -700);
			shift = 0;
			i = 0;
		}

	}

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


