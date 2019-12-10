#include <iostream>
#include <string>
using namespace std;

void die() {
    cout << "BAD INPUT!" << endl;
    exit(1);
}

int main() {
    const int ADD = 1;
    const int MULTIPLY = 2;
    const int MAX_SIZE = 20; //At most a 20x20 table
    int choice = 0, min = 0, max = 0;
    cout << "Choose:\n";
    cout << "1. Addition Table\n";
    cout << "2. Times Table\n";
    cin >> choice;
    //YOU: Input choice here, and vet it for correctness
    if (!cin) die(); //Prints "BAD INPUT!" and quits.
    if (choice > 2 or choice < 1) die();
    cout << "Please enter the smallest number on the table:\n";

    //YOU: Input min here, and make sure cin is not false
    cin >> min;
    if (!cin) die();

    //YOU: Input max here, and make sure that cin is not false,
    // that min is not bigger than max, and that you will not
    // be outputting more than a 20x20 table

    cout << "Please enter the largest number on the table:\n";
    cin >> max;

    if (!cin) die();
    if (min > max) die();
    if (max - min >= MAX_SIZE) die();

//YOU: Now output the table
//Start by printing a + or X, then do the column headers
//Then do each row, starting with a row header
      if (choice == 1) {
  // add + and take away 0
          cout << "+\t";
          for (int k = min; k < (max + 1); k++) {
              cout << k << "\t";
          }
          cout << endl;
          for (int i = min; i < (max + 1); i++) {
              cout << i << "\t";
              for (int j = min; j < (max + 1); j++) {
                  cout << i + j << "\t";
              }
              cout << endl;
          }
      }
  //For multiplication
      if (choice == 2) {
          cout << "X\t";
          for (int k = min; k < (max + 1); k++) {
              cout << k << "\t";
          }
          cout << endl;
          for (int i = min; i < (max + 1); i++) {
              cout << i << "\t";
              for (int j = min; j < (max + 1); j++) {
                  cout << i * j << "\t";
              }
              cout << endl;
          }
      }
  }