#include <iostream>
#include <cmath>
#include <cctype>
using namespace std;

//Return a string where the first letter is uppercased
//toupper function, which is in cctype
//"hello" as input becomes "Hello" as output
string proper(string s) {
    if (s.size() <= 0) return s;
    s.at(0) = toupper(s.at(0));
    return s;
}

//Make a mocking spongebob function
//That either capitalizes every other one, or capitalizes randomly
string mocking_spongebob(string s) {
    bool coinflip = false;
    for (size_t i = 0; i < s.size(); i++) {
        //bool coinflip = rand() % 2;
        if (coinflip)
            s.at(i) = toupper(s.at(i));
        else
            s.at(i) = tolower(s.at(i));
        coinflip = !coinflip;
    }
    return s;
}

int f(int x) {
    return 10 * x - 5;
}

int g(int x) {
    return x*x - x;
    //return pow(x,2) - x;
}

int h(int x) {
    return sqrt(pow(x,9));
}

double k(double x) {
    return abs(sin(x)) - pow(cos(x),2);
}

int main() {
    srand(time(0));
    cout << "Please enter x: ";
    int x = 0;
    cin >> x;
    cout << "f(x) = " << f(x) << endl;
    cout << "g(x) = " << g(x) << endl;
    cout << "h(x) = " << h(x) << endl;
    cout << "k(x) = " << k(x) << endl;

    cout << "Please enter a sentence:\n";
    string s;
    //cin >> s; //This gets a word
    getline(cin,s); //This gets a sentence
    getline(cin,s); //This gets a sentence
    cout << "Proper(s) = " << proper(s) << endl;
    cout << "Spongebob(s) = " << mocking_spongebob(s) << endl;
}