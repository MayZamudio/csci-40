#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int *example_3() {
    cout << "This function creates a stack-allocated array, and returns a pointer to it, which is really, really bad.\n";
    cout << "We'll try using it the same way as a heap-allocated array, and see what happens...\n";
    size_t size = 0;
    cout << "Please enter how many integers you want to hold in a stack allocated array:\n";
    cin >> size;
    if (!cin) exit(EXIT_FAILURE);

    //Step 1 - Stack allocate memory to hold an array
    //Turn on -pedantic-errors to stop this from compiling...
    int a[size]; //This is not valid C++! Arrays have to have compile-determinable size, but some compilers allow this anyway
    int *b = a;

    //Step 2 - Do stuff with the array
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
    return b; //Bad bad bad bad bad - the array gets deallocated here, but we return the address anyway!
}