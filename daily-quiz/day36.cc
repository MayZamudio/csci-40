#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//HOW TO COPY FROM ONE FILE TO ANOTHER
//mx sets mark x on a spot
//y'x copies to mark x
//:e edits a new file, be like :e main.cc
//Then p to paste the code you copied

//Today, we will learn how to search through a vector of a class

//Here's a stripped down version of our Pokemon class
struct Pokemon {
    string name;
    float att, def;
};

//Here's how to teach C++ how to cout a Pokemon
ostream& operator<<(ostream &outs, const Pokemon &p) {
    outs << "Name: " << p.name << " Attack: " << p.att << " Defense: " << p.def;
    return outs;
}

//Default sort order for Pokemon set here - (Here's how to teach C++ how to sort Pokemon by name)
bool operator<(const Pokemon &lhs, const Pokemon &rhs) {
    return lhs.name < rhs.name;
}

//If you want custom sort functions you can make other ways of sorting Pokemon like this
bool sort_by_att(const Pokemon &lhs, const Pokemon &rhs) {
    return lhs.att < rhs.att;
}
bool sort_by_def(const Pokemon &lhs, const Pokemon &rhs) {
    return lhs.def < rhs.def;
}

int main() {
    vector<Pokemon> vec = {{"Pika",15,20},{"Bulba",10,25},{"Chamillionaire",30,5},{"Squirtle",5,30}};
    cout << "Here is the starting vector:\n";
    for (const auto &p : vec) cout << p << endl;
    auto result = minmax_element (vec.begin(),vec.end(), sort_by_att);
    cout << "Using minmax_element, the smallest Pokemon is: " << *result.first  << endl;
    cout << "It is at position: " << result.first - vec.begin() << endl;
    cout << "Using minmax_element, the biggest  Pokemon is: " << *result.second << endl;
    cout << "It is at position: " << result.second - vec.begin() << endl;
    cout << "\nCalling default sort on the vector (which uses < by default to sort):\n";
    sort(vec.begin(),vec.end());
    for (const auto &p : vec) cout << p << endl;
    cout << "\nCalling sort on the vector passing in a third parameter to sort to sort by attack:\n";
    sort(vec.begin(),vec.end(),sort_by_att);
    for (const auto &p : vec) cout << p << endl;
    cout << "Pokemon with the biggest attack is: " << vec.back() << endl; //same as vec.at(vec.size() -1);
    cout << "Pokemon with the littlest attack is: " << vec.front() << endl; //same as vec.at(0);
    cout << "\nCalling sort on the vector passing in a third parameter to sort to sort by defense:\n";
    sort(vec.begin(),vec.end(),sort_by_def);
    for (const auto &p : vec) cout << p << endl;
}