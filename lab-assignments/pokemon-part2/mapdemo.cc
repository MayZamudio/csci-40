#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <map>
using namespace std;

//One way to convert from type name to row number in the type_system.txt file
int lookup_type(string s) {
    if (s == "Normal") return 0;
    else if (s == "Fighting") return 1;
    else if (s == "Flying") return 2;
    //Etc...
    else
        return -1;
}

int main() {
    map<string,int> m;
    m["Normal"] = 0;
    m["Fighting"] = 1;
    m["Flying"] = 2;
    m["Poison"] = 3;
    m["Ground"] = 4;
    m["Rock"] = 5;
    m["Bug"] = 6;
    m["Ghost"] = 7;
    m["Steel"] = 8;
    m["Fire"] = 9;
    m["Water"] = 10;
    m["Grass"] = 11;
    m["Electric"] = 12;
    m["Psychic"] = 13;
    m["Ice"] = 14;
    m["Dragon"] = 15;
    m["Dark"] = 16;
    m["Fairy"] = 17;
    cout << "Please enter a type:\n";
    string s;
    cin >> s;
    cout << "Its row is: " << m[s] << endl;
}