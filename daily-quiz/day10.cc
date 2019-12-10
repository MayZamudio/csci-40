#include <iostream>
#include <cmath>
#include <cstdlib>
#include <cctype>
using namespace std;

int main() {
    //WARNING: ONLY USE SRAND ONCE IN YOUR PROGRAM
    srand(0); //Initialize the random number generator
    cout << (rand() % 6) + 1 << endl; //Generates a "random" int from 1 to 6
    cout << (rand() % 6) + 1 << endl; //Generates a "random" int from 1 to 6
    cout << (rand() % 6) + 1 << endl; //Generates a "random" int from 1 to 6
    cout << (rand() % 6) + 1 << endl; //Generates a "random" int from 1 to 6
    return 0;

    string s;
    cout << "Please enter a password\n";
    cin >> s;
    cout << "Your password has: " << s.size() << " letters\n"; //.size() returns the size of the string
    //.at(x) grabs the letter at index x
    int count_upper = 0;
    int count_lower = 0;
    int count_digit = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (isupper(s.at(i))) count_upper++;
        if (islower(s.at(i))) count_lower++;
        if (isdigit(s.at(i))) count_digit++;
    }
    cout << "Your password has " << count_upper << " uppercase letters " << count_lower  << " lowercase letters and " << count_digit << " digits.\n";
    cout << "Now we will uppercaseify your password.\n";
    for (size_t i = 0; i < s.size(); i++) {
        //toupper takes in a letter as input, and returns the capital version as output
        //WARNING: It returns an int, not a char, so stuff it into a char
        char c = toupper(s.at(i));
        cout << c;
    }
    cout << endl;
}