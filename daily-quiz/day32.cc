#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    const size_t ARR_SIZE = 1234;
    int *arr = new int[ARR_SIZE];
    size_t ints_read = 0;
    for (size_t i = 0; i < ARR_SIZE; i++) {
        cin >> arr[i];
        if (arr[i] == -1) break;
        ints_read++;
    }
    for (size_t i = 0; i < ints_read; i++) {
        cout << arr[i] << endl;
    }
    delete[] arr;
}