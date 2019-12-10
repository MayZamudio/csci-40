#include <iostream>
using namespace std;

char first_letter(string s) {
    if (s.size() <= 0) return '\0';
    return s.at(0);
}

int bill_abs(int x) {
    if (x < 0) x *= -1;
    return x;
}

float bill_abs(float x) {
    if (x < 0) x *= -1;
    return x;
}

int main() {
    auto x = -5;
    auto f = -9.1f;
    cout << bill_abs(x) << " " << bill_abs(f) << endl;
    cout << first_letter("") << endl;
}
