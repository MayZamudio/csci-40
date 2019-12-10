#include <iostream>
using namespace std;

int main() {
    for (int i = 0; i < 10; i++) {
        for (int j = 0; j < 10; j++) {
            cout << i * j << "\t";
        }
        cout << endl;
    }
    //1. Print the numbers from 10 to 1, in decreasing order
    for (int i = 0; i < 10; i++) {
        cout << 10 - i << endl;
    }

    //2. Print the numbers from 2 to 20 by 2s
    for (int i = 0; i < 10; i++) {
        cout << 2 * i + 2 << endl;
    }

    //3. Print the numbers from 1 to 100, following the following rules
    //  1) If the number is divisible by 3, print "Fizz" instead of the number
    //  2) If the number is divisible by 5, print "Buzz" instead of the number
    //  3) If the number is divisible by 15, print "Fizzbuzz" instead
    //If you finish early, make these things also happen based on the sum of the digits.
    //So 21 would print "Fizz", 23 would print "Buzz", 78 would print "Fizzbuzz".
    for (int i = 0; i < 100; i++) {
        int num = i + 1;
        int first_digit = num / 10;
        int second_digit = num % 10;
        int sum = first_digit + second_digit;
        if (num % 15 == 0 or !(sum % 15)) cout << "Fizzbuzz\n";
        else if (!(num % 3)) cout << "Fizz\n";
        else if (!(num % 5) or !(sum % 5)) cout << "Buzz\n";
        else cout << num << endl;
    }
}