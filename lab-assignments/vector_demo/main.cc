#include <vector>
#include <iostream>
using namespace std;

int main() {
    //Part 1 - Averaging 20 numbers
    size_t x;
    cout << "How many games did your baseball team play?\n";
    cin >> x;
    if (!cin) exit(1);
    vector<int> scores(x); //Create x integers to hold our season scores
    //while (true) {
    for (size_t i = 0; i < x; i++) {
        cout << "Please enter the game number and the team's score (-1 to quit):\n";
        int game_number = 0, score = 0;
        cin >> game_number >> score;
        if (!cin) exit(1);
        if (game_number == -1 || score == -1) break;
        scores.at(game_number) = score;
    }
    cout << "====================\n";
    cout << "Season Scores:\n";
    cout << "====================\n";
    for (int x : scores) cout << x << endl; //One line vector print
    int subtotal = 0;
    for (int x : scores) subtotal += x; //Add up the vector
    cout << "Average score: " << float(subtotal) / scores.size() << endl;
    

    //Part 2 - Growing a vector from size 0
    vector<int> vec;
    vec.push_back(42);
    vec.push_back(420);
    vec.push_back(4200);
    cout << "The vector contains:\n";
    //Here is how you can print a vector
    for (int x : vec)
        cout << x << endl;
    while (true) {
        int x = 0;
        cout << "Please enter a number to add (0 to quit): "; 
        cin >> x;
        if (x == 0 || !cin) break;
        vec.push_back(x);
    }
    cout << "The vector now contains:\n";
    //This is another way to print a vector
    for (size_t i = 0; i < vec.size(); i++)
        cout << vec.at(i) << endl;
}