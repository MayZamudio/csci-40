#include <iostream>
#include <cmath>
#include <algorithm>
#include <numeric>
#include <vector>
using namespace std;
// ANSWER FOR #7: "int x" in the function definition should be (int &x)
void inc_fun(int x) {
    x++;
    cout << "Answer to Qs 7: " << x << endl;
}

void foo(string &s) {
    for (unsigned int i = 0; i < s.size(); i++)
        s.at(i) = toupper(s.at(i));
    for (auto x : s)
        cout << x;
    cout << endl;
}
// QUESTION 14
/*
You can't write a function with same name as that of class
But you have another option of making constructor it has the same name as that of the class
EG:-
class net {
    int a;
    net() {
        a = 10;
    }
};
Her net () is a constructor
Constructor are usually used for assigning value inside a class
https://www.quora.com/Can-we-write-an-instance-function-with-same-name-as-class-name-in-c++
*/
class Miho {
  public:
    int x, y, z;
    Miho() {
        x = 10;
        y = 5;
        z = 0;
    }
};
int main() {
    // QUESTION 3
    cout << endl;
    /*  cout << "Answer to #3: ";
        for (int i = 0 ; i < 10000; i++) {
            cout << i + 1;
        }*/

    // QUESTION 11 - What does this code do? It uses a pointer to loop over n int array and increments each element by one
    int arr[10] = {1, 2, 3, 4, 5, 6, 7, 8, 9, 10}; //Make an array of size 10 and initialize with 1 through 10
    cout << "QUESTION 11: Original Array: \n";
    for (auto x : arr) {
        cout << x;
    }
    cout << endl;
    int *ptr = arr;
    for (int i =  0; i < 10; i++) {
        *ptr = *ptr + 1;
        ptr++;
    }
    cout << "It uses a pointer to loop over n int array and increments each element by one: \n";
    for (int j = 0; j < 10; j++) {
        //cout << *(ptr + j);
        cout << arr[j];
    }
    cout << endl;
    cout << endl;
    // QUESTION 19
    cout << "QUESTION 19: Dollars < 1000 gives error message" << endl;
    int dollars = 0;
//  cin << dollars;
    cin >> dollars;
    if (!cin || dollars < 1000) cout << "Error message" << endl;
    else dollars++;
    cout << dollars;
    cout << endl;
    cout << endl;
    // QUESTION 17
    while (true) {
        cout << "Press F to pay respects\n";
        char c;
        cin >> c;
        if (tolower(c) == 'f') break;
    }
        cout << endl;
    cout << endl;
    // QUESTION 15
    cout << "Answer for # 15: ";
    for (int i = 0; i < 100; i++) {
        if (i % 2)
            cout << i << " ";
    }
    cout << endl;
    cout << endl;

    // QUESTION 9
    int y = 5.0 / 2;
    cout << "Answer to # 9: " << y << endl;
    cout << endl;

    // QUESTION 10
    string s;
    cout << "Question 10: Enter a string" << endl;
    cin >> s;
    foo(s);
    cout << endl;
    cout << endl;

    // QUESTION 7
    int score = 0;
    cout << "Question 7: Score increasing as expected " << endl;
    cin >> score;
    inc_fun(score);

    //Sum up a vector
    vector<int> vec = {1, 2, 3, 4, 5};
    for (size_t i = 0; i < vec.size(); i++) cout << "Question 5: " << vec.at(i) << endl;
    cout << endl;
    cout << endl;

    // QUESTION 6
    int x = 0;
    cout << "Number to cout the letter A ONLY: " << endl;
    cin >> x;
    if (x < 10) cout << "A\n";
    else if (x < 20) cout << "B\n";
    else cout << "C\n";
    cout << "D\n";
        //STL way
    int sum = accumulate(vec.begin(), vec.end(), 0);
    cout << "\nSUM = " << sum << endl;
    //For loop way
    sum = 0;
    for (size_t i = 0; i < vec.size(); i++)
        sum += vec.at(i);
    cout << "SUM = " << sum << endl;

    //STL way
    cout << "MIN = " << *min_element(vec.begin(), vec.end()) << endl;
    int min = vec.at(0);
    //For loop way
    for (int x : vec)
        if (min > x) min = x;
    cout << "MIN = " << min << endl;
}