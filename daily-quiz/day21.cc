#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;

int main() {
    //Sum up a vector
    vector<int> vec = {1,2,3,4,5};
    //STL way
    int sum = accumulate(vec.begin(),vec.end(),0);
    cout << "SUM = " << sum << endl;
    //For loop way
    sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
        sum += vec.at(i);
    cout << "SUM = " << sum << endl;

    //STL way
    cout << "MIN = " << *min_element(vec.begin(),vec.end()) << endl;
    int min = vec.at(0);
    //For loop way
    for (int x : vec)
        if (min > x) min = x;
    cout << "MIN = " << min << endl;
}