#include <iostream>
#include <cmath>
using namespace std;

int main() {
    double x=0,y=0,z=0;
    cin >> x >> y;
    if (!cin) return 0;
    z = hypot(x,y);
    cout << z << endl;
}