
/*
This file is known as calculator02buggy.cpp

I have inserted 5 errors that should cause this not to compile
I have inserted 3 logic errors that should cause the program to give wrong results

First try to find an remove the bugs without looking in the book.
If that gets tedious, compare the code to that in the book (or posted source code)

Happy hunting!

*/

#include "std_lib_facilities_5.h"

//------------------------------------------------------------------------------

class Token{ // Added 'c' to "class" (compiler error 1)
public:
	char kind;
	double value; 
	Token(char ch)
		:kind(ch), value(0) { }
	Token(char ch, double val) 
		:kind(ch), value(val) { }
};

//------------------------------------------------------------------------------

class Token_stream {
public:
	Token_stream();
	Token get();
	void putback(Token t);
private:
	bool full;
	Token buffer;
};

//------------------------------------------------------------------------------

Token_stream::Token_stream()
	:full(false), buffer(0) {}

//------------------------------------------------------------------------------

void Token_stream::putback(Token t)
{
	if (full) error("putback() into a full buffer");
	buffer = t;
	full = true;
}

//------------------------------------------------------------------------------

Token Token_stream::get() // Added "Token_stream::" for member function get() (compiler error 2)
{
	if (full) {
		full = false;
		return buffer;
	}

	char ch;
	cin >> ch;

	switch (ch) {
	case '=':
	case 'x': case 'X':
	case '(': case ')': case '+': case '-': case '*': case '/':
		return Token(ch);
	case '.':
	case '0': case '1': case '2': case '3': case '4':
	case '5': case '6': case '7': case '8': case '9': // Added missing case (logic error 1)
	{
		cin.putback(ch);
		double val;
		cin >> val;
		return Token('8', val);
	}
	default:
		error("Bad token");
		return Token('8', 0);
	}
}

//------------------------------------------------------------------------------

Token_stream ts;

//------------------------------------------------------------------------------

double expression();

//------------------------------------------------------------------------------

double primary()
{
	Token t = ts.get();
	switch (t.kind) {
	case '(':
	{
		double d = expression();
		t = ts.get();
		if (t.kind != ')') error("')' expected"); // Added terminating " (compiler error 3)
			return d;
	}
	case '8':            
		return t.value;
	default:
		error("primary expected");
		return 0.0;
	}
}

//------------------------------------------------------------------------------

double term()
{
	double left = primary();
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '*':
			left *= primary();
			t = ts.get();
			break; // Added break (logic error 2)
		case '/':
		{
			double d = primary();
			if (d == 0) error("divide by zero");
			left /= d;
			t = ts.get();
			break;
		}
		default:
			ts.putback(t); 
			return left;
		}
	}
}

//------------------------------------------------------------------------------

double expression()
{
	double left = term(); // Added closing ) (compiler error 4)
	Token t = ts.get();

	while (true) {
		switch (t.kind) {
		case '+':
			left += term();
			t = ts.get();
			break;
		case '-':
			left -= term(); // Changed to -= from += (logic error 3)
			t = ts.get();
			break;
		default:
			ts.putback(t);
			return left;
		}
	}
}

//------------------------------------------------------------------------------

int main()
try
{
	cout << "Calculator Program v1.0" << endl;
	cout << "Welcome! Please enter an equation to get started." << endl
		<< "(Enter x to exit or = to evaluate your expression)" << endl;
	double val = 0.0; // Declared and initiailized val (compiler error 5)
	while (cin) {
		cout << "--> ";
		Token t = ts.get();

		if (t.kind == 'x' || t.kind == 'X') break;
		if (t.kind == '=')
			cout << val << '\n';
		else {
			ts.putback(t);
			val = expression();
		}
	}
	return 0;
}
catch (exception& e) {
	cerr << "error: " << e.what() << '\n';
	keep_window_open();
	return 1;
}
catch (...) {
	cerr << "Oops: unknown exception!\n";
	keep_window_open();
	return 2;
}