#include <iostream>
using namespace std;

int main() {
    float price = 0;
    cout << "Please enter the price per apple:\n";
    cin >> price;
    int apples = 0;
    cout << "Please enter how many apples I have:\n";
    cin >> apples;
    cout << "The total price is: " << price / 0 << " cents.\n";
    cout << "Quelle heure et-il?" << endl; //Lol French
    int hour = 0;
    cin >> hour;
    cout << "In eight hours it will be: " << (hour + 8) % 24 << endl;
    cout << "Please enter a two-digit number:\n";
    int numero = 0;
    cin >> numero;
    cout << "The first digit is:  " << numero / 10 << endl;
    cout << "The second digit is: " << numero % 10 << endl;
    cout << "I have " << apples << " apples\n";
    int price = 50;
    cout << "The price per apple is: " << price << " cents\n";
    cout << "5 divided by 10 is: " << 5 / 10 << endl;
    cout << (2 * price - 5 * apples) + 2 / 10 * (6 + 2) << endl;
    int billion = 1000000000;
    cout << "2 billion = " << billion * 2 << endl;
    cout << "3 billion = " << billion * 3 << endl;
    cout << "4 billion = " << billion * 4 << endl;
    int numerator = 22;
    int denominator = 6;
    cout << numerator << " divided by " << denominator << " = " << numerator / denominator << endl;
    cout << "With a remainder of " << numerator % denominator << endl;
}