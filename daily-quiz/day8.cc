#include <iostream>
using namespace std;

int main() {
    //Option 1 - infinite loop, used when we don't know how many times we're going to do something.
    while (true) {
        cout << "Please enter the password.\n";
        string s;
        cin >> s;
        if (s == "p4ssw0rd") break;
    }

    //Option 2 - for loop, used when we know how many times we're going to do something
    //Write code to output the numbers from 10 to 1
    for (int i = 0; i < 10; i++) {
        cout << 2*i << endl;
    }
}