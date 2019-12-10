#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
#include <cstdlib>
using namespace std;

bool check(char c, vector<vector<char>> vec) {
    for (int i = 0; i < 3; i++) {
        if ((vec.at(i).at(0) == c and vec.at(i).at(1) == c and vec.at(i).at(2) == c)) return true;
    }
    for (int i = 0; i < 3; i++) {
        if ((vec.at(0).at(i) == c and vec.at(1).at(i) == c and vec.at(2).at(i) == c)) return true;
    }
    if ((vec.at(0).at(0) == c and vec.at(1).at(1) == c and vec.at(2).at(2) == c)) return true;
    if ((vec.at(0).at(2) == c and vec.at(1).at(1) == c and vec.at(2).at(0) == c)) return true;

    return false;
}

int main() {
    cout << "Please enter a random seed:\n";
    int seed = 0;

    int numX = 0, numO = 0, numSpace = 0;

    cin >> seed;
    if (!cin) exit(1);
    srand(seed);
    vector<vector<char>> vec = { {'a', 'b', 'c'}, {'x', 'a', 'x'}, {'a', 'x', 'c'} };
    //Let's generate a tic tac toe board
    for (vector<char> &row : vec) {
        for (char &c : row) {
            int roll = rand() % 3;
            if (roll == 0) {
                c = 'X';
                numX++;
            } else if (roll == 1) {
                c = 'O';
                numO++;
            } else {
                c = ' ';
                numSpace++;
            }
        }
    }
        //This code here prints a 2D array
    for (const vector<char> &v : vec) {
        for (char c : v)
            cout << c << " ";
        cout << endl;
    }
    //YOUR JOB WILL BE TO PRINT ONE OF FOUR THINGS:

    if ((numX < numO) or (numX - numO > 1) or (check('X', vec) and check('O', vec))) {
        cout << "ERROR\n";
    } else if (check('X', vec)) {
        cout << "X WINS!\n";
    } else if (check('O', vec)) {
        cout << "O WINS!\n";
    } else if (!check('X', vec) and !check('O', vec) and numSpace == 0) cout << "DRAW!\n";
    else cout << "NOTHING!\n";

}