#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void example_1() {
    cout << "This function allocates memory to hold some integers, does stuff with it, and then deallocates it properly.\n";
    cout << "This is a CORRECT EXAMPLE of how to use new and delete with raw pointers.\n";
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
        cout << "Fibonacci sequence element " << i << ": " << a[i] << endl;
    }
    cout << "Which element of the Fibonacci sequence would you like to know?\n";
    size_t choice = 0;
    cin >> choice;
    if (choice >= size) {
        cout << "Out of bounds! Going to leak memory accidentally!\n";
        return; //Why is this a problem?
    }
    else
        cout << a[choice] << endl;
    //Step 3 - Done. Deallocate
    delete[] a;
}