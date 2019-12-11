#include <iostream>
#include <cmath>
#include <algorithm>
using namespace std;

void die() {
    cout << "BAD INPUT!\n";
    exit(1);
}

//All functions take doubles
//All functions return doubles, other than istriangle, which returns a bool

//Write f(x) = x^4-3x^2+7
//I am giving you the function signature for this one, but you have to write the others
double f(double x) {
    return pow(x, 4) - 3 * pow(x, 2) + 7; //YOU
}

//Write f2(x,y) = |x|-|y|
double f2(double x, double y) {
    return abs(x) - abs(y);
}   //YOU

//Write f3(x,y,z) = max(x,y,z)
double f3(double x, double y, double z) {
    if (x > y and x > z) {
        return x;
    } else if (y > x and y > z) {
        return y;
    } else return z;
}
//Returns the biggest value found within x, y, or z
//For example, if x is 1, y is 10, and z is 3, it will return 10
//YOU

//Write sas(a,b,theta) = 0.5 * a * b * sin(theta)
//Computes the area of a non-right triangle, given two sides and the angle in between
//YOU
double sas(double a, double b, double theta) {
    return (0.5 * a * b * sin(theta));
}
//Write istriangle(a,b,c) = returns {true: if the sides a,b,c could be a triangle, false: otherwise}
//YOU
bool istriangle(double a, double b, double c) {
    if (a + b > c and b + c > a and c + a > b)
        return true;
    else return false;
}
int main() {
    cout << "Welcome to the function competition!\n";
    cout << "Do you want to compute:\n";
    cout << "1. f(x) = x^4-3x^2+7\n";
    cout << "2. f2(x,y) = |x| - |y|\n";
    cout << "3. f3(x,y,z) = max(x,y,z)\n";
    cout << "4. sas(a,b,theta) = 0.5 * a * b * sin(theta)\n";
    cout << "5. istriangle(a,b,c) = returns true if the sides represented by a,b,c could be a triangle, else false.\n";
    int choice = 0;
    cin >> choice;
    if (!cin || choice < 0 || choice > 5) die();
    double first = 0, second = 0, third = 0; //Parameters are called this instead of x,y,z or a,b,theta, etc.
    cout << "Please enter the first parameter:\n";
    cin >> first;
    if (!cin) die();
    if (choice > 1) {
        cout << "Please enter the second parameter:\n";
        cin >> second;
        if (!cin) die();
    }
    if (choice > 2) {
        cout << "Please enter the third parameter:\n";
        cin >> third;
        if (!cin) die();
    }
    cout << "The result is: ";
    if (choice == 1) cout << f(first) << endl;
    if (choice == 2) cout << f2(first, second) << endl;
    if (choice == 3) cout << f3(first, second, third) << endl;
    if (choice == 4) cout << sas(first, second, third) << endl;
    if (choice == 5) cout << boolalpha << istriangle(first, second, third) << endl;
}