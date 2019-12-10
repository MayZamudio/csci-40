#include <iostream>
#include <cmath>
#include <algorithm>
#include <cstdlib>
#include <vector>
#include <random>
using namespace std;

int main() {
    random_device rd;
    const int MINVAL = 1, MAXVAL = 5;
    static_assert(MAXVAL >= MINVAL);
    uniform_int_distribution<int> dist(MINVAL,MAXVAL);
    //srand(time(0));
    vector<int> vec(100);
    for (size_t i = 0; i < vec.size(); i++) {
        //vec.at(i) = rand() % 21;
        vec.at(i) = dist(rd);
    }
    sort(vec.begin(),vec.end());
    random_shuffle(vec.begin(),vec.end());
    for (int i : vec) cout << i << endl;
    double sum = 0;
    for (int i : vec) sum += i;
    cout << "AVG = " << sum / vec.size() << endl;
    vector <int> count(MAXVAL-MINVAL+1);
    for (size_t i = 0; i < vec.size(); i++)
        count.at(vec.at(i)-MINVAL) += 1;
    for (size_t i = MINVAL; i <= MAXVAL; i++) {
    //  cout << "There are " << count.at(i) << " " << i << "s\n";
        for (int j = 0; j < count.at(i-MINVAL); j++) {
            cout << "*";
        }
        cout << endl;
    }
}