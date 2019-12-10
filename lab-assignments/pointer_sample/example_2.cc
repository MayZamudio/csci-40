#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int *example_2() {
    cout << "This function allocates memory to hold some integers, does stuff with it, and then returns the raw pointer.\n";
    cout << "This is a correct but potentially dangerous example of how to create and return raw pointers.\n";
    cout << "Why is it potentially dangerous? When you return a pointer, the calling function often has no way of knowing if it is responsible for deleting it when you're done with it.\n";
    size_t size = 0;
    cout << "Please enter how many integers you want to hold in a dynamic array:\n";
    cin >> size;
    if (!cin) exit(EXIT_FAILURE);
    //Step 1 - Allocate memory to hold an array
    int *a = new int[size];
    //Step 2 - Do stuff with the dynamic array
    for (size_t i = 0; i < size; i++) {
        if (i < 2) a[i] = 1;
        else a[i] = a[i-1] + a[i-2]; //Fibonacci sequence
    }
    cout << "Which element of the Fibonacci sequence would you like to know?\n";
    size_t choice = 0;
    cin >> choice;
    if (choice >= size) {
        cout << "Out of bounds! Going to leak memory accidentally AND return a null pointer!\n";
        return nullptr; //Why is this a problem?
    }
    cout << "Element " << choice << " is " << a[choice] << endl;
    //Step 3 - Return a back to main
    return a;
}