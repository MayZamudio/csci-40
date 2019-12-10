#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <numeric>
using namespace std;
void die() {
    cout << "BAD INPUT!" << endl;
    exit(1);
}
int main() {
    cout << "Please enter daily rainfall data (-1 to quit):\n";
    vector<int> userVals;
    int num;
    int nonRainyDays = 0;
    cin >> num;
    if (!cin) die();
  
    while (num != -1) {
        if (num > -1) userVals.push_back(num);
        if (num == 0) nonRainyDays++;
        cin >> num;
        if (!cin) die();
    }
    sort(userVals.begin(), userVals.end(), greater<>());

    int average = accumulate(userVals.begin(), userVals.end(), 0.0) / userVals.size();
    int numRainyDays = (userVals.size() - nonRainyDays);
    int averageRainy = 0;
    if (numRainyDays != 0) {
        averageRainy = accumulate(userVals.begin(), userVals.end(), 0.0) / numRainyDays;
    }
    
    while (true) {
        int choice = 0;
        cout << "1) Average daily rainfall\n";
        cout << "2) Average rainfall on rainy days\n";
        cout << "3) Count of days that had rain\n";
        cout << "4) Maximum rainfall\n";
        cout << "5) Top 5 days of rain\n";
        cout << "6) Quit\n";
        cin >> choice;
        if (!cin) die();
        if (choice == 1) {
            if (userVals.empty()) cout << "NO DATA\n";
            else cout << average << endl;
        } else if (choice == 2) {
            if (userVals.empty() || numRainyDays == 0) cout << "NO DATA\n";
            else cout << averageRainy << endl;
        } else if (choice == 3) {
            cout << numRainyDays << endl;
        } else if (choice == 4) {
            if (userVals.empty() || numRainyDays == 0) cout << "NO DATA\n";
            else cout << userVals.at(0) << endl;
        } else if (choice == 5) {
            if (userVals.at(0) == 0) cout << "NO DATA\n";
            else {
                for (unsigned int i = 0; i < 5; i++) {
                    if (i > userVals.size() - 1 || userVals.at(i) == 0) break;
                    cout << userVals.at(i) << endl;
                }
            }
        } else break;
    }
}