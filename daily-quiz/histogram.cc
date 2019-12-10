#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cctype>
using namespace std;

int main() {
    string secret;
    cout << "Please enter secret word:\n";
    cin >> secret;
    vector<int> count(26);
    for (char c : secret) {
        if (!isalpha(c)) continue;
        c = toupper(c); //Everything is uppercase now
        int index = c - 'A';
        count.at(index)++;
    }
    for (size_t i = 0; i < count.size(); i++) {
        if (count.at(i)) cout << char('A'+i) << ": " << count.at(i) << endl;
    }
}