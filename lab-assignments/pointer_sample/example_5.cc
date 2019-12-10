#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <memory>
using namespace std;

shared_ptr<int[]> example_5() {
//void example_5() {
    cout << "Welcome to smartpointer-ville!\n";
    cout << "Smart pointers detect when they're not needed any more and automatically free up their allocated memory.\n";
    size_t size = 0;
    cout << "Please enter how many integers you want to hold in a dynamic array:\n";
    cin >> size;
    if (!cin) exit(EXIT_FAILURE);
    //Step 1 - Allocate memory to hold an array
    //auto a = make_shared<int[]>(size);
    auto a = shared_ptr<int[]>(new int[size]);

    //Step 2 - Do stuff with the dynamic array
    for (size_t i = 0; i < size; i++) {
        if (i < 2) a[i] = 1;
        else a[i] = a[i-1] + a[i-2]; //Fibonacci sequence
    }
    cout << "Which element of the Fibonacci sequence would you like to know?\n";
    size_t choice = 0;
    cin >> choice;
    if (choice >= size) {
        cout << "Out of bounds! Going to leak memory accidentally!\n";
        return nullptr; //Why is this a problem?
    }
    cout << "Element " << choice << " is " << a[choice] << endl;

    //Step 3 - Done. Don't need to Deallocate since it's a smart pointer
    return a;
}