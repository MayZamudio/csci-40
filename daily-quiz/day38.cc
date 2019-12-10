#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <numeric>
#include <cstdlib>

using namespace std;

int main() {
    //Here is how you can use figlet with variables
    string name;
    cout << "Please enter your name:\n";
    cin >> name;
    string figlet = "figlet Hello my name is " + name + " | lolcat";
    system(figlet.c_str());
    string pokemon = "pokemon --pokemon "s + name + " | lolcat";
    system(pokemon.c_str());

    //Compute mean, median, and mode for a vector
    vector<int> vec = {7,2,2,2,3,4,1,9,3,2,4,5,9,1,9};
    vector<int> mode_count(10);
    int sum = accumulate(vec.begin(),vec.end(),0);
    cout << "Average = " << sum / vec.size() << endl;
    sort(vec.begin(),vec.end());
    if (vec.size() % 2) //Odd number of elements
        //If vec.size = 5, then the middle element is 2
        cout << "Median = " << vec.at(vec.size() / 2) << endl;
    else
        cout << "Median = " << (vec.at(vec.size() / 2) + vec.at(vec.size() / 2 + 1)) / 2 << endl;

    for (int x : vec) //Make a histogram of how often each int appears
        mode_count.at(x)++;

    //for (int x : mode_count) cout << x << endl; //Print the count of each integer in vec

    cout << "Mode = " << max_element(mode_count.begin(),mode_count.end()) - mode_count.begin() << endl;
}