#include <iostream>
#include <fstream>
#include <cctype>
#include <vector>
using namespace std;

int main() {
    cout << "Welcome to the FriendDestroyer 2000(tm)\n";
    cout << "Type in the file name to read from:\n";
    string filename;
    cin >> filename;
    ifstream invite_file(filename); //This opens the file named filename
    ofstream rsvp_file("rsvp_list.txt"); //The opens a file called rsvp_list.txt for writing
    if (!invite_file) {
        cout << "Could not open the file: " << filename << endl;
        exit(EXIT_FAILURE);
    }
    vector<string> invite_list;
    while (true) {
        string temp;
        invite_file >> temp; //If we did cin >> s it would read from keyboard
        if (!invite_file) break;
        invite_list.push_back(temp);
    }
    //cout << "These people made the cut:\n";
    rsvp_file << "These people made the cut:\n";
    for (string s : invite_list) {
        if (!isupper(s.at(0)))
            rsvp_file << s << " 😢 " << endl;
        else if (s.at(0) <= 'K')
            rsvp_file << s << " 😁" << endl;
        else
            rsvp_file << s << " 🤑 " << endl;
        //if (s.size() < 5) cout << "Not invited: " << s << endl;
        //else cout << "Invited: " << s << endl;
    }
}