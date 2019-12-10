#include <iostream>
#include <fstream>
#include <vector>
using namespace std;

int main() {
    cout << "What file would you like to search through?\n";
    string filename;
    cin >> filename;
    ifstream ins(filename);
    if (!ins) {
        cout << "Error: File " << filename << " could not be opened.\n";
        exit(EXIT_FAILURE);
    }
    cout << "What word do you want to search for?\n";
    string word;
    cin >> word;
    while (ins) {
        string temp;
        ins >> temp;
        if (!ins) break;
        if (temp == word) {
            cout << word << " is in the file!\n";
            exit(EXIT_SUCCESS);
        }
    }
    cout << word << " is not in the file.\n";
}