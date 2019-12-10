#include <iostream>
using namespace std;

int main() {
    int balance = 0;
    cout << "Please input your balance: ";
    cin >> balance;
    if (!cin or balance < 1 or balance > 5) {
        cout << "BAD INPUT!\n";
        return 1;
    }
    cout << "Your balance is: " << balance << endl;
    int target = 0;
    cout << "Please enter how much you want to have: ";
    cin >> target; //errry time we do a cin we must vet it
    if (!cin) { cout << "BAD INPUT!\n"; return 0; }
    cout << "Your target is: " << target << endl;
    if (balance >= target) cout << "You're fine.\n";
    else cout << "You're not fine.\n";
}