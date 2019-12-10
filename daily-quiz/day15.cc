#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

//Sum up the vector passed in
//Most of the time a vector will be passed in by const reference
//Const means the vector cannot change
//Reference means it passes the original vector in and doesn't make a copy
//Return the product of all elements
int product(const vector<int> &vec) {
    int total = 1;
    for (int x : vec) total *= x;
    return total;
}
//Write a function that will return the maximum element in vec
int max_element(const vector<int> &vec) {
    if (vec.size() == 0) {
        cout << "vec can't be size 0\n";
        exit(1);
    }
    int max = vec.at(0);
    for (int x : vec) if (x > max) max = x;
    return max;
}
int min_element(const vector<int> &vec) {
}

//This is called a forward declaration
int add_up(const vector<int> &vec);

//Return the floating point average of the vector
float average(const vector<int> &vec) {
    return float(add_up(vec)) / vec.size();
}

int add_up(const vector<int> &vec) {
    int total = 0;
    for (int x : vec) total += x;
    return total;
}

//Input into two vectors the score for away team and home team each inning
//If they type in a negative number exit early
//If the game went at least 5 innings, print the innings and victor
//If it reaches the bottom of the 9th+ and it is tied, keep going
// Otherwise, end.
  int main() {
      vector<int> away_scores, home_scores;
      int inning = 0, total_away = 0, total_home = 0;
      while (true) {
          inning++;
          cout << "Please enter the visitor's score for inning: " << inning << endl;
          int away_score;
          cin >> away_score;
          cout << "Please enter the home team's score for inning: " << inning << endl;
          int home_score;
          cin >> home_score;
          if (!cin || away_score < 0 || away_score > 100 || home_score < 0 || home_score > 100)
          {
              if (inning < 5) exit(0);
              break;
          }
          away_scores.push_back(away_score);
          home_scores.push_back(home_score);
          total_away = add_up(away_scores);
          total_home = add_up(home_scores);
          for (int x : home_scores) total_home += x;
          if (inning >= 9 and total_away != total_home) break;
      }
  
      //Print out the vector (version 1)
      cout << "Away scores:\n";
      for (int x : away_scores) cout << x << " ";
      cout << "\nTotal: " << add_up(away_scores) << endl;
      cout << "Home scores:\n";
      for (int x : home_scores) cout << x << " ";
      cout << "\nTotal: " << add_up(home_scores) << endl;
      cout << endl;
  
      /*
      //Initialize vec to the powers of 2
      for (int i = 0; i < vec.size(); i++) {
          vec.at(i) = pow(2,i);
      }
  
      //Print out the vector (version 2)
      for (int i = 0; i < vec.size(); i++) {
          cout << vec.at(i) << endl;
      }
      */
  
  }