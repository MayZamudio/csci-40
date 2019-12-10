#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

pair<int,int> q_and_r(int dividend, int divisor) {
    int quotient = -1;
    while (dividend >= 0) {
        quotient++;
        dividend -= divisor;
    }
    dividend += divisor;
    return {quotient,dividend};
}

class Complex {
    public:
        float real;
        float imaginaree;
};

int main() {
    auto [quotient,remainder] = q_and_r(33,6); //C++17 feature "structured bindings"
    cout << "Quotient: " << quotient << " Remainder: " << remainder << endl;
    Complex first = {3.1,-5.1};
    first.real = 12.1;
    cout << first.real << showpos << first.imaginaree << "i" << endl;
}