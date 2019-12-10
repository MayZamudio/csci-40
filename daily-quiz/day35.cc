#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

class Name {
    public:
        string first, last;
        bool operator< (Name b) {
            return last < b.last;
        }
};

bool sort_by_first_name(Name a, Name b) {
    return a.first < b.first;
}

bool sort_by_last_name(Name a, Name b) {
    return a.last < b.last;
}

int main() {
    vector<Name> vec;
    cout << "Please enter a bunch of first and last names. (DONE to be done)\n";
    while (true) {
        Name temp;
        cin >> temp.first >> temp.last;
        if (temp.first == "DONE") break;
        vec.push_back(temp);
    }
    cout << "Sorting by using the class's < operator... sorts by last name...\n";
    sort(vec.begin(),vec.end());
    for (Name n : vec)
        cout << n.first << " " << n.last << endl;
    cout << "Sorting by using the sort_by_first_name function...\n";
    sort(vec.begin(),vec.end(),sort_by_first_name);
    for (Name n : vec)
        cout << n.first << " " << n.last << endl;

    /* Find the element in the vector with the lowest last name
    Name min = vec.at(0);
    for (size_t i = 0; i < vec.size(); i++) {
        if (vec.at(i).last < min.last)
            min = vec.at(i);
    }
    cout << min.first << " " << min.last << endl;
    */
}