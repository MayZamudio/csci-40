#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    float a,b,c; //About 6 significant digits
    double x,y,z; //double precision gives about 12-13 sig figs
    cin >> x >> y;
    z = sqrt(x) * sin(y) - log10(x+y);
    cout << "sqrt: " << sqrt(x) << endl; //square root of x
    cout << "pow(x,3): " << pow(x,3) << endl; //x^3
    cout << "sin(x): " << sin(x) << endl; //sin
    cout << "cos(x): " << cos(x) << endl; //cos
    cout << "log(x): " << log(x) << endl; //natural log
    cout << "log10(x): " << log10(x) << endl; //log base 10
    cout << "hypot(x,y): " << hypot(x,y) << endl; //Pythagorean theorem
}