#include <iostream>
using namespace std;

//This is a comment
int main() {
    string s = "Hello World!"; //Strings hold words
    cout << "Please enter your name: ";
    cin >> s; //THIS READS ONE WORD EXACTLY!!!11!!!!!1!
    cout << "Hello, " << s << ", you must be a super cool person\n";
    cout << "Please enter three ints: ";
    int x,y,z;
    cin >> x >> y >> z;
    cout << "x+y = " << x+y << endl;
    cout << "(2*x)/z = " << (2*x)/z << endl;
    cout << "(y-z)*(x-z)/4 = " << (y-z)*(x-z)/4 << endl;
}