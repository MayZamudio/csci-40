#include <iostream>
#include <cctype>
#include <cmath>
using namespace std;

//Call by reference
//This doesn't make a copy of the variable, it IS the original variable
void increment(int&a) {
    a++;
}

//Call by value - makes duplicate
//string uppercaseify(string s) {

//Call by reference - no duplicate
void uppercaseify(string &s) {
    for (size_t i = 0; i < s.size(); i++) {
        s.at(i) = toupper(s.at(i));
    }
}

//Set uppers equal to the number of uppercase letters in s
//Set lowers equal to the number of lowercase letters in s
void count_letters(const string &s, int &uppers, int &lowers) {
    uppers = lowers = 0;
    for (size_t i = 0; i < s.size(); i++) {
        if (isupper(s.at(i))) uppers++;
        if (islower(s.at(i))) lowers++;
    }
}

int main() {
    string s = "When in the course of human events it becomes...";
    int uppers = 0, lowers = 0;
    count_letters(s,uppers,lowers);
    cout << s << " has " << uppers << " uppercase letters and " << lowers << " lowercase letters.\n";
    uppercaseify(s);
    count_letters(s,uppers,lowers);
    cout << s << " has " << uppers << " uppercase letters and " << lowers << " lowercase letters.\n";
}