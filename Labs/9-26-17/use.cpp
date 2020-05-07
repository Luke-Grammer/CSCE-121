#include "my.h"
#include <iostream>

int foo;

int main() {
	foo = 7;
	print_foo();
	print(99);

	std::cout << "Please enter a character to exit\n";
	char ch;
	std::cin >> ch;
}