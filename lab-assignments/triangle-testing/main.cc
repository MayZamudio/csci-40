//ZAMUDIO and YASIN
#include <iostream>
using namespace std;

//Enum is useful when you want to make large numbers of mutually exclusive constants
//This creates 5 constant integers, named EQUILATERAL (= 0), ISOCELES (= 1), etc.
//It also creates a new integer type that can only hold a value from 0 to 4.
enum triangle_t { EQUILATERAL, ISOCELES, RIGHT, OTHER, ERROR };

/* This is equivalent, kinda, to:
   const int EQUILATERAL = 0;
   const int ISOCELES = 1;
   const int RIGHT = 2;
   const int OTHER = 3;
   const int ERROR = 4;
   */


triangle_t triangle_tester(float side1, float side2, float side3) {
    //YOU: Do your work right here

    if (side1 == side2 and side2 == side3) {
        if (side1 <= 0 and side2 <= 0 and side3 <= 0) return ERROR; // equilateral = 0
        else return EQUILATERAL;
    } else if (side1 == side2 || side1 == side3 || side2 == side3) return ISOCELES;
    else if (side1 * side1 + side2 * side2 == side3 * side3 || side2 * side2 + side3 * side3 == side1 * side1 || side3 * side3 + side1 * side1 == side2 * side2) return RIGHT;

    else if (side1 + side2 == side3 or side2 + side3 == side1 or side3 + side1 == side2) return ERROR;
    else if (side1 < 0.01) return ERROR;
    else if (side2 + side3 < side1) return ERROR;
    else if (side1 + side2 > side3 or side2 + side3 > side1 or side3 + side1 > side2) {
        if (side1 >= 99000) return OTHER;
        else return OTHER;
    }
    return OTHER;
}
int main() {
    float side1 = 0.0, side2 = 0.0, side3 = 0.0;
    cin >> side1 >> side2 >> side3;

    triangle_t result = triangle_tester(side1, side2, side3);

    if (result == EQUILATERAL) {
        cout << "equilateral";
    } else if (result == ISOCELES)
        cout << "isoceles";
    else if (result == RIGHT)
        cout << "right";
    else if (result == OTHER)
        cout << "other";
    else if (result == ERROR)
        cout << "error";
    else
        cout << "This is unpossible!";
    cout << endl;
}