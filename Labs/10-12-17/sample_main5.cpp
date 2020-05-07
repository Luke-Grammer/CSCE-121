#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

int main()
try {
  Simple_window win1(Point(100,200),600,400,"My Window");
  Line vert_l(Point(100, 100), Point(100, 150));  // make a horizontal line
  Line horiz_l(Point(100, 150), Point(120, 150));     // make a vertical line
  horiz_l.set_color(Color::green);
  vert_l.set_color(Color::green);
  Line a1(Point(125,150), Point(135,100));
  Line a2(Point(130,125), Point(140,125));
  Line a3(Point(135,100), Point(145,150));
  a1.set_color(Color::blue);
  a2.set_color(Color::blue);
  a3.set_color(Color::blue);
  Line g1(Point(150, 100), Point(150, 150));
  Line g2(Point(150, 100), Point(170, 100));
  Line g3(Point(150, 150), Point(170, 150));
  Line g4(Point(170, 150), Point(170, 125));
  Line g5(Point(170, 125), Point(160, 125));
  g1.set_color(Color::red);
  g2.set_color(Color::red);
  g3.set_color(Color::red);
  g4.set_color(Color::red);
  g5.set_color(Color::red);

  
  win1.attach(g1);
  win1.attach(g2);
  win1.attach(g3);
  win1.attach(g4);
  win1.attach(g5);
  win1.attach(a1);
  win1.attach(a2);
  win1.attach(a3);
  win1.attach(vert_l);
  win1.attach(horiz_l);
  win1.wait_for_button();
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
