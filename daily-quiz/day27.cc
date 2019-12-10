#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int d10() {
    //VERSION 1 - Recursive solution
    int result = rand() % 10 + 1;
    if (result < 10) return result;
    return 10 + d10();

    //VERSION 2 - Loop based version
    int roll = 0;
    int result = 0;
    while (true) {
        roll = rand() % 10 + 1;
        result += roll;
        if (roll < 10) break;
    }
    return result;
}

int main() {
    srand(time(0));
    cout << "Rolling three exploding d10s -\n";
    cout << d10() << endl;
}