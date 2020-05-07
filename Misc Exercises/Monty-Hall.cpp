#include <stdio.h>
#include <random>
#include <string>
#include <time.h>
#include <algorithm>

using namespace std;

const int NUM_DOORS = 3;
const int NUM_ITERATIONS = 1000000;

int main() {
    srand(time(NULL));
    int cars_found = 0;
    char* doors[NUM_DOORS] = {"car", "goat", "goat"};
    char* temp;
    int temp_idx;

    for(int i = 1; i <= NUM_ITERATIONS; i++) {
        if (i % 100000 == 0) 
            printf("iteration: %i\n", i);

        for (int j = 0; j < NUM_DOORS; j++) 
        { // Shuffle array
            temp_idx = (rand() % (2 - j + 1)) + j;
            temp = doors[temp_idx];
            doors[temp_idx] = doors[j];
            doors[j] = temp;
        }

        if (doors[0] == "car") {
            cars_found++;
        }
    }
    printf("Number of rounds won without switching: %i\n", cars_found);
    printf("Average win percentage: %0.4f\n\n", cars_found / double(NUM_ITERATIONS));

    cars_found = 0;
    for(int i = 1; i <= NUM_ITERATIONS; i++) {
        if (i % 100000 == 0) 
            printf("iteration: %i\n", i);

        for (int j = 0; j < NUM_DOORS; j++) 
        { // Shuffle array
            temp_idx = (rand() % (2 - j + 1)) + j;
            temp = doors[temp_idx];
            doors[temp_idx] = doors[j];
            doors[j] = temp;
        }

        // Uncover door #2, or #3
        if(doors[1] == "goat") {
            if (doors[2] == "car")
                cars_found++;
        }
        else
            if (doors[1] == "car")
                cars_found++;
        
    }
    printf("Number of rounds won with switching: %i\n", cars_found);
    printf("Average win percentage: %0.4f\n\n", cars_found / double(NUM_ITERATIONS));
    return 0;
}