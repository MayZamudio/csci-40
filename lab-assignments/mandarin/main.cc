#include <iostream>
#include <cmath>
#include <cstdlib>
using namespace std;

//ERROR CHECKING:If the user ever makes an error on input, print "BAD INPUT!" to the screen and quit.
void die() {
    cout << "BAD INPUT!" << endl;
    exit(1);
}
//Mandarin Dictionary:
string toMandarin(int &firstNum) {
    if (firstNum == 0) return "ling";
    if (firstNum == 1) return "yi";
    if (firstNum == 2) return "er";
    if (firstNum == 3) return "san";
    if (firstNum == 4) return "si";
    if (firstNum == 5) return "wu";
    if (firstNum == 6) return "liu";
    if (firstNum == 7) return "qi";
    if (firstNum == 8) return "ba";
    if (firstNum == 9) return "jiu";
    if (firstNum == 10) return "shi";
}

int main() {
    int maxValue = 0;
    int firstNum = 0;
    int stepSize = 0;

    //Step 1. Ask the user how high they want the program to count.
    cout << "Please enter a number that you want to count up to in Mandarin.\n";
    cin >> maxValue;
    if (!cin) die();
    if (maxValue < 0 or maxValue > 99999) die();

    //Step 2. Ask the user what number they want to start with.
    cout << "Please enter what number to start with:\n";
    cin >> firstNum;
    if (!cin) die();
    if (firstNum > maxValue) die();
    if (firstNum < 0) die();

    //Step 3. Ask the user what step size they want to count up by.
    cout << "What step size do you want to use?\n";
    cin >> stepSize;
    if (!cin) die();
    if (stepSize <= 0) die();
          cout << endl;
  
      for (int i = firstNum; i <= maxValue; i++) {
          if (firstNum > maxValue) break;
  
          int onesPlace = firstNum % 10;
          int tensPlace = ((firstNum % 100) - onesPlace) / 10;
          int hundPlace = ((firstNum % 1000) - ((10 * tensPlace) + onesPlace)) / 100;
          int thousPlace = ((firstNum % 10000) - ((100 * hundPlace) + (10 * tensPlace) + onesPlace)) / 1000;
          int tenThousPlace = (firstNum - ((1000 * thousPlace) + (100 * hundPlace) + (10 * tensPlace) + onesPlac  e)) / 10000;
  
          if (firstNum <= 10) {
              cout << firstNum << " " << toMandarin(firstNum) << endl;
          }
          if (firstNum >= 11 && firstNum <= 19) {
              cout << firstNum << " shi " << toMandarin(onesPlace) << endl;
          }
          if (firstNum >= 20 && firstNum <= 99) {
              cout << firstNum << " " << toMandarin(tensPlace) << " shi ";
              if (onesPlace != 0) cout << toMandarin(onesPlace) << endl;
              else cout << endl;
          }
          if (firstNum >= 100 && firstNum <= 999) {
              cout << firstNum << " " << toMandarin(hundPlace) << " bai ";
              if (tensPlace != 0) cout << toMandarin(tensPlace) << "shi ";
              if (onesPlace != 0) cout << toMandarin(onesPlace) << endl;
              else cout << endl;
          }
          if (firstNum >= 1000 && firstNum <= 9999) {
              cout << firstNum << " " << toMandarin(thousPlace) << " qian ";
              if (hundPlace != 0) cout << toMandarin(hundPlace) << "bai ";
              if (tensPlace != 0) cout << toMandarin(tensPlace) << "shi ";
              if (onesPlace != 0) cout << toMandarin(onesPlace) << endl;
              else cout << endl;
          }
          if (firstNum >= 10000 && firstNum <= 99999) {
              cout << firstNum << " " << toMandarin(tenThousPlace) << " wan";
              if (thousPlace != 0) cout << " " << toMandarin(thousPlace) << " qian";
              if (hundPlace != 0) cout << " " << toMandarin(hundPlace) << " bai";
              if (tensPlace != 0) cout << " " << toMandarin(tensPlace) << " shi";
              if (onesPlace != 0) cout << " " << toMandarin(onesPlace) << endl;
              else cout << endl;
          }
          firstNum += stepSize;
      }
  }