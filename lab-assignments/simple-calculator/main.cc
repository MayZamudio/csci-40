#include <iostream>
using namespace std;

int main() {
    cout << "1) addition 2) subtraction 3) multiplication 4) division: \n";
    int num1 = 0;
    cin >> num1;
    if (!cin) {
        cout << "BAD INPUT!\n";
        return 0;
    }
    if (num1 < 1 or num1 > 5) {
        cout << "BAD INPUT!" << endl;
        return 0;
    } else if (num1 > 1 or num1 < 5) {
        cout << "Please enter two numbers: " << endl;
    }
    int num2, num3;
    cin >> num2 >> num3;
    if (!cin) {
        cout << "BAD INPUT!" << endl;
        return 0;
    }
    if (num1 == 1) {
        cout << num2 + num3 << endl;
    } else if (num1 == 2) {
        cout << num2 - num3 << endl;
    } else if (num1 == 3) {
        cout << num2 * num3 << endl;
    } else if (num1 == 4) {
        if (num3 != 0) cout << num2 / num3 << endl;
        else cout << "BAD INPUT!" << endl;
    } else if (num1 == 5) {
        if (num3 != 0) cout << num2 % num3 << endl;
        else cout << "BAD INPUT!" << endl;
    }
    return 0;
}