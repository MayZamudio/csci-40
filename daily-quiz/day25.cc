#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

unsigned long long f(unsigned long long x) {
    //Base condition
    if (x == 0) return 0;
    //Inductive Step
    return 2*(f(x-1)+1);
}

void f2(unsigned long long x) {
    cout << x << endl;
    //Base condition?????
    if (x <= 1) return;
    if (x % 2 == 0) //even
        f2(x/2);
    else //odd
        f2(x+1);
}

int main() {
    cout << "f(5) = "  << f(5)  << endl;
    cout << "f2(10) = ";
    f2(10);
    cout << endl;
}