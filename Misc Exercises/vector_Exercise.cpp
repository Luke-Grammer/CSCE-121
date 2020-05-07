// Simple vector exercise
// Written by Luke Grammer
// 9/4/18

#include <iostream>
#include <vector>

using namespace std;

/*
This exercise has 5 steps:
1) Declare a vector of integers
2) Insert 5 non-negative numbers into the vector
3) Using a for loop, find the largest number in the vector
4) Print the largest number
5) Finally, remove all values from the vector
*/

int main() {
    //Declare a vector of integers
    vector<int> v1;

    //Insert 5 non-negative numbers into the vector
    v1.push_back(3);
    v1.push_back(7);
    v1.push_back(4);
    v1.push_back(0);
    v1.push_back(9);

    //Using a for loop, find the largest number in the vector
    int max = -1;
    for(int i = 0; i < v1.size(); i++) {
        if (v1[i] > max) max = v1[i];
    }

    //Print the largest number
    cout << "The largest input value is " << max << "." << endl;

    //Finally, remove all values from the vector
    cout << "Removing values: ";
    for(int i = v1.size(); i > 0; i--) {
        cout << " " << v1[i - 1];
        v1.pop_back();
    }
    cout << endl << "Done!\n";

    return 0;
}