#include <iostream>
using namespace std;

int main() {
    int running_total = 0;
    while (true) {
        cout << "Please enter a score:\n";
        int score = 0;
        cin >> score;
        if (!cin) return 0;
        if (score < 0 or score > 1000) {
            cout << "Hint: the number must be between 0 and 1000.\n";
            continue;
        }
        running_total = running_total + score;
        cout << "The current running total is: " << running_total << endl;
    }
}