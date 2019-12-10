#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

const size_t SIZE = 5;

int* load_map() {
    int min_val = 0, max_val = 0; //Stack allocated variable
    int *arr = new int[SIZE]; //Makes an array of size 10 - heap allocated
    //int arr[SIZE]; //Kinda the same?? But no - stack allocated
    //Fill the array with rando data
    for (size_t i = 0; i < SIZE; i++)
        arr[i] = rand() % 10;
        //*(arr+i) = rand() % 10; //Alternate way
    return arr;
}
int main() {
    //int *bob = 0; //Pointing to memory address 0
    //cout << *bob << endl; //Dereferencing a null pointer
    srand(time(0));
    cout << "Loading map 1...\n";
    int *arr = load_map();
    for (size_t i = 0; i < 10; i++)
        cout << arr[i] << endl;
    cout << "Loading map 2...\n";
    delete[] arr;
    arr = load_map();
    for (size_t i = 0; i < 10; i++)
        cout << arr[i] << endl;
    //The rule is that every new needs exactly one delete
    delete[] arr;
}