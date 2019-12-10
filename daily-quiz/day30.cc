#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

void uppercaseify(string *s) {
    for (char &c : *s)
        c = toupper(c);
}

string strip(string &s) {
    string retval;
    for (char c : s)
        if (isalpha(c)) retval.push_back(c);
    return retval;
}

void set_to_9000(int *ptr) {
    *ptr = 9000;
}

int main() {
    int *arr = new int[1000000]; //4) NEW OPERATOR - allocates memory for 1M ints and returns the addr of the first one
    *arr = 42;
    *(arr+1) = 50;
    arr[-2] = 100;
    cout << *arr << endl; //Print the value of the first int in the region of memory
    cout << *(arr+1) << endl; //Print the value of the second int in the region of memory
    cout << *(-2+arr) << endl; //BAD - but will work with ASAN turned off because no bounds checking

    delete[] arr; //We're done with it free up memory

    string bob = "   b o b    ";
    cout << bob << endl;
    uppercaseify(&bob);
    cout << bob << endl;
    cout << strip(bob) << endl;
        //1) Reference operator (&) returns the memory address of a variable
    //2) Pointer variables (int *, etc.) hold memory addresses of OTHER variables
    //3) Dereference operator (*) returns the variable at that memory address
    int x = 42;
    set_to_9000(&x); //This will set x to 9000
    cout << *&x << endl; //No
    cout << &x << endl;
    int* x_ptr = &x; //int* means it holds the memory address of an int
    cout << x_ptr << endl;
    *x_ptr = 500; //This is the same as writing x = 500;
    cout << *x_ptr << endl;
}