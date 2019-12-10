#include <unistd.h>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//Variables look like this hi_my_name_is_bill or score_team_1
//Classes look like this: Circle, TeamKill, Stuff
//Constants look like this: MAX_SIZE, ROWS, etc.
class Circle {
    public:
        float radius; //Member variable
        int x,y; //Member variable
        float get_area() { //Member function / AKA a method
            return M_PI * radius * radius;
        }
        bool is_in(int other_x, int other_y) {
            //Return true if (other_x,other_y) is within our circle
            float distance = hypot(other_x-x,other_y-y);
            //Don't recommend float distance = sqrt(pow((other_x-x),2)+pow((other_y-y),2));
            if (distance <= radius) return true;
            return false;
        }
};

//Free function
bool is_overlapping(const Circle &a, const Circle &b) {
    float distance = hypot(a.x-b.x,a.y-b.y);
    if (distance <= a.radius + b.radius) return true;
    return false;
}

const int MAX_ROWS = 30;
const int MAX_COLS = 30;
void print_circle(Circle &c) {
    cout << '^L'; //system("clear");
    for (int i = 0; i < MAX_ROWS; i++) {
        for (int j = 0; j < MAX_COLS; j++) {
            if (c.is_in(j,i)) cout << '*';
            else cout << ' ';
        }
        cout << endl;
    }
}

int main() {
    cout << boolalpha; //Prints true or false instead of 0 or 1
    Circle a;
    a.radius = 10;
    a.x = 0;
    a.y = 0;
    Circle b = {4,0,0};
    cout << "The area of circle a is: " << a.get_area() << endl;
    cout << "The area of circle b is: " << M_PI * b.radius * b.radius << endl;
    cout << "A overlaps b? " << is_overlapping(a,b) << endl;
    cout << "Is point (6,7) within a circle of radius 10 on the origin: " << a.is_in(6,7) << endl;
    cout << boolalpha << "Is point (6,7) within a circle of radius 5 at (3,0): " << b.is_in(6,7) << endl;
    int vel_x = 1;
    int vel_y = 1;
    while (true) {
        print_circle(b);
        b.radius = b.x;
        b.x += vel_x;
        b.y += vel_y;
        if (b.x <= 0 or b.x >= MAX_COLS) vel_x *= -1;
        if (b.y <= 0 or b.y >= MAX_ROWS) vel_y *= -1;
        usleep(50000);
    }
}