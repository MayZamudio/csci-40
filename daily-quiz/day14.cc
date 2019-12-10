#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
#include <iomanip>
using namespace std;

int main() {
    cout << "Welcome to baseball scoring!\n";
    cout << "How many innings did the game go?\n";
    unsigned int innings = 0;
    cin >> innings;
    if (!cin or innings > 40) {
        cout << "Your input was bad and you should feel bad.\n";
        exit(1);
    }
    vector<unsigned int> home(innings), away(innings);
    unsigned int best_home = 0, best_away = 0;
    for (unsigned int i = 0; i < innings; i++) {
        cout << "Please enter the score for inning " << i+1 << " for the away team:\n";
        cin >> away.at(i);
        if (away.at(i) > 100 or !cin) {
            cout << "BAD!\n";
            exit(1);
        }
        if (away.at(i) > best_away) best_away = away.at(i);

        cout << "Please enter the score for inning " << i+1 << " for the home team:\n";
        cin >> home.at(i);
        if (home.at(i) > 100 or !cin) {
            cout << "BAD!\n";
            exit(1);
        }
        if (home.at(i) > best_home) best_home = home.at(i);
    }
    cout << "^L"; //ctrl-v ctrl-l
    cout << "========== Results ==========\n";
    cout << "AWAY: ";
    //cout << setfill('X');
    unsigned int away_score = 0;
    for (unsigned int x : away) {
        away_score += x;
        cout << left << setw(4) << x << " ";
    }
        cout << "Total: " << away_score << endl;
    cout << "Avg: " << double(away_score)/innings << endl;
    cout << "Best: " << best_away << endl;
    //Remember, to make a double out of an int...
    //double(away_score)
    //static_cast<double>(away_score)
    cout << "HOME: ";
    for (unsigned int x : home) cout << left << setw(4) << x << " ";
    unsigned int home_score = accumulate(home.begin(),home.end(),0);
    cout << "Total: " << home_score << endl;
    cout << "Avg: " << static_cast<double>(home_score)/innings << endl;
    cout << "Best: " << best_home << endl;
    cout << endl;
    if (home_score > away_score) cout << "Home team wins!\n";
    else if (away_score > home_score) cout << "Away team wins!\n";
    else cout << "Tie, WTF?\n";
}