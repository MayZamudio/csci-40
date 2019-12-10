#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<string> list;
    list.push_back("Kerney");
    while (true) {
        cout << "Please enter a name to add to the wedding list. (QUIT to quit)\n";
        string temp;
        cin >> temp;
        if (!cin or temp == "QUIT") break;
        list.push_back(temp);
    }
    for (string s : list) cout << s << endl;
}