#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

int main() {
    vector<int> vec = {10, 1, -1, 42, 3, 6, 90}, sorted_vec;
    while (vec.size()) {
        auto iter = max_element(vec.begin(),vec.end());
        sorted_vec.push_back(*iter);
        vec.erase(iter);
    }
    for (int i : sorted_vec) cout << i << endl;
}