// Luke Grammer
// CSCE 121-513
// Due: October 5, 2017
// randint_525008438.cpp

#include "randint_525008438.h"
#include <chrono>

using namespace std::chrono;

//linear congruential pseudorandom number generator
int randint() {
	//use the clock for an initial pseudorandom number
	static long x = time_point_cast<microseconds>(system_clock::now())
		.time_since_epoch().count();
	//calculate the next pseudorandom number
	//parameters from glibc(?)
	x = (((1103515245L * int(x)) & 0x7fffffff) + 12345) & 0x7fffffff;
	return x;
}
