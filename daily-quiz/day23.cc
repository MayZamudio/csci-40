#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

int main() {
    srand(time(0));
    vector<vector<char>> vec = { {'a','b','c'}, {'x','a','x'}, {'a','x','c'} };
    //Let's generate a tic tac toe board
    for (vector<char> &row: vec) {
        for (char &c : row) {
            int roll = rand() % 3;
            if (roll == 0)
                c = 'X';
            else if (roll == 1)
                c = 'O';
            else
                c = ' ';
        }
    }
    //This code here prints a 2D array
    for (const vector<char> &v : vec) {
        for (char c : v)
            cout << c << " ";
        cout << endl;
    }
    //Count how many 'x' are in the array
    int count = 0;
    for (const auto &v : vec) {
        for (char c : v)
            if (c == 'X')
                count++;
    }
    cout << "There are: " << count << " X's in the array.\n";
}