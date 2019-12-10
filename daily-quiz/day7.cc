#include <iostream>
using namespace std;

int main() {
    while (true) {
        cout << "Please enter a number:\n";
        int x = 0;
        cin >> x;
        if (x > 100) {
            cout << "That's just too big a number, man.\nI can't count that high.\n";
            continue;
        }
        if (!cin) {
            break; //This ends whatever loop we're in
        }
        else if (x % 2 == 1) cout << "You entered an odd number.\n";
        else cout << "You entered an even number.\n";
    }
    cout << "I hope you had fun!\n";
}