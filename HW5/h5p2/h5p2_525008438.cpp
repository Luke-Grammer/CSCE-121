//Luke Grammer
//CSCE 121-513
//Due: October 31, 2017
//h5p2_525008438.cpp

#include "std_lib_facilities_5.h"
#include "Simple_window.h"
#include "Graph.h"
#include "FL/Fl_JPEG_Image.H"

const int WINDOW_SIZE = 656, // Size of window
GRID_SIZE = WINDOW_SIZE / 8; // Dimensions of each square on board

int main()
try {
	Simple_window win1{ Point{100, 100}, WINDOW_SIZE, WINDOW_SIZE, "Checkers Board" }; // Create window
	Color moss_green(fl_rgb_color(0x8A, 0x9A, 0x5B)); // Define moss green
	Color cherry_blossom_pink(fl_rgb_color(0xFF, 0xB7, 0xC5)); // Define cherry blossom pink
	Color custom_red(fl_rgb_color(0xC2, 0x01, 0x04));
	Vector_ref<Rectangle> board; // Squares on board
	Vector_ref<Ellipse> pieces; // Game pieces
	Vector_ref<Ellipse> shadows; // Shadows of game pieces
	bool color_picker = false; 

	for (unsigned i = 0; i < 8; ++i) { // Loop through rows of game board
		for (unsigned j = 0; j < 8; ++j) { // Loop through columns of row i on game board
			board.push_back(new Rectangle(Point(j * GRID_SIZE, i * GRID_SIZE), GRID_SIZE, GRID_SIZE)); // Place a new square

			if (color_picker) { // If color picker is true, set square color to moss green
				board[board.size() - 1].set_fill_color(moss_green);
				board[board.size() - 1].set_color(moss_green);
				if (i < 3 || i > 4) { // If on the first 3 rows or last 3 rows, make a game piece and a shadow
					pieces.push_back(new Ellipse(Point(j * GRID_SIZE + int(GRID_SIZE / 2), i * GRID_SIZE + int(GRID_SIZE / 2)), int((GRID_SIZE / 2) * .68), int((GRID_SIZE / 2) * .56)));
					shadows.push_back(new Ellipse(Point(j * GRID_SIZE + int(GRID_SIZE / 2), i * GRID_SIZE + int(GRID_SIZE / 2) + 3), int((GRID_SIZE / 2) * .68) + 2, int((GRID_SIZE / 2) * .56) + 5));
					shadows[shadows.size() - 1].set_fill_color(Color::black); // Set shadow color to black
					// If in first 3 rows make game pieces red,  otherwise make them white
					(i < 3) ? pieces[pieces.size() - 1].set_fill_color(custom_red) : pieces[pieces.size() - 1].set_fill_color(Color::white);
				}
			}
			else { // If color picker is false, set square color to cherry blossom pink
				board[board.size() - 1].set_fill_color(cherry_blossom_pink);
				board[board.size() - 1].set_color(cherry_blossom_pink);
			}

			if (j != 7) // Change color picker unless on last column of row
				color_picker = !color_picker;
			// Attach square to window 
			win1.attach(board[board.size() - 1]);
		}
	}

	for (unsigned i = 0; i < pieces.size(); ++i) { // Loop through all game pieces and attach them to the window on top of their shadow
		win1.attach(shadows[i]);
		win1.attach(pieces[i]);
	}

	win1.wait_for_button(); // Wait for button
	return 0;
}
catch (exception& e) {
	cerr << "exception: " << e.what() << '\n';
	return 1;
}
catch (...) {
	cerr << "Oops! An unexpected error occured, please try again.\n";
	return 2;
}
