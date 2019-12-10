#include <iostream>
#include <fstream>
#include <vector>
#include <cstdlib>
#include <ctime>
#include <algorithm>
using namespace std;

void die() {
    cout << "Invalid input!\n";
    exit(EXIT_FAILURE);
}

void uppercaseify(string &s) {
    for (char &c : s)
        c = toupper(c);
}

void continue_check() {
    cout << "Do you want to continue?\n";
    char c;
    cin >> c;
    if (c == 'n' || c == 'N') exit(0);
}

//Returns true if needle is in haystack, false otherwise
bool string_search(const string &needle, const string &haystack) {
    size_t loc = haystack.find(needle);
    if (loc != string::npos) return true;
    return false;
}

//YOU: Write this function
bool word_find(string s, const vector<string> &vec) {
    //How tall the table is
    const size_t height = vec.size();
    //How wide table is
    const size_t width = vec.at(0).size();

    //Search through the vector
    for (size_t i = 0; i < height; i++) {
        string row = vec.at(i);
        //Search horizontal
        if (row.find(s) != string::npos) return true;
        //Search backwards horizontal
        reverse(row.begin(), row.end());
        if (row.find(s) != string::npos) return true;

    }
    //Search top to bottom
    for (size_t j = 0; j < width; j++) {
        string col;
        for (size_t i = 0; i < height; i++) {
            col.push_back(vec.at(i).at(j));
        }
        //reverse
        if (col.find(s) != string::npos) return true;
        reverse(col.begin(), col.end());
        if (col.find(s) != string::npos) return true;
    }
    string diagonalR = "";
    string diagonalL = "";
    int j = vec.size() - 1 ;
    //Search diagonal down right (main diagonal only)
    for (size_t i = 0; i < vec.size(); i++) {
        diagonalR = diagonalR + vec.at(i).at(i);
        diagonalL += vec.at(j).at(i);
        j--;
    }
        if (diagonalR.find(s) != string::npos) return true;
    //Reverse - diagonal down right (main diagonal only)
    reverse(diagonalR.begin(), diagonalR.end());
    if (diagonalR.find(s) != string::npos) return true;

    if (diagonalL.find(s) != string::npos) return true;
    //Reverse - diagonal down left (main diagonal only)
    reverse(diagonalL.begin(), diagonalL.end());
    if (diagonalL.find(s) != string::npos) return true;

    return false;
}

int main() {
    //PHASE 1 - Build up our table of letters for doing word searches
    cout << "Please enter lines of letters, all uppercase and the same length (blank line to stop):\n";
    vector<string> wordsearch; //All the words as entered - this is basically a 2D array

    while (true) {
        string temp;
        getline(cin, temp);
        if (temp == "") break;
        //YOU: Vet temp to make sure all letters are uppercase and are letters
        for (size_t i = 0; i < temp.size(); i++) {
            if (islower(temp.at(i))) die();
            if (isdigit(temp.at(i))) die();
        }
        //YOU: Make sure all words are size 3+
        if (temp.size() < 3) die();
        //YOU: Add temp to wordsearch
        wordsearch.push_back(temp);
    }
    //YOU: Die if no strings were entered
    if (wordsearch.empty()) die();
    
    //YOU: Now vet the vector of strings to make sure they are all the same length
    if (wordsearch.size() != wordsearch[0].size()) die();
    if (wordsearch.size() != wordsearch[1].size()) die();
    //YOU: Now print the table
    for (unsigned int i = 0; i < wordsearch.size(); i++) {
        cout << wordsearch[i] << endl;
    }

    continue_check();

    //PHASE 2 - Load the dictionary
    ifstream dict_file("/usr/share/dict/words");
    if (!dict_file) {
        cout << "Error opening dictionary file!\n";
        exit(1);
    }

    //YOU: Load from the dictionary into a vector
    string s;
    vector<string> dict;
    while (dict_file >> s) {
        bool validWord = true;
        for (char c : s) {
            if (!islower(c)) validWord = false;
            if (!isalpha(c)) validWord = false;
        }
        if (s.size() < 3) validWord = false;
        if (validWord) dict.push_back(s);

    }
    dict_file.close();
    //Print the dict like this if you want to see what you loaded -
//  for (string s : dict) cerr << s << endl;

    cout << dict.size() << " words loaded.\n";
    continue_check();

    //PHASE 3 - For each word in the dictionary, look through the wordsearch vector and print it if it is in there
    for (string s : dict) {
        //YOU: Uppercaseify S so that it can match
        uppercaseify(s);
        //YOU: Write this function above
        if (word_find(s, wordsearch)) {
            cout << "FOUND: " << s << endl;
        }
    }
    //GL; HF
}