//Macros in Vim
//1. Let's make a macro named a - 'qa' will start recording a macro named a
//2. When you are done with your keystrokes you type q again. Stops recording
//3. To replay a macro named a, type @a
#include <iostream>
#include <fstream>
#include <algorithm>
#include <cmath>
#include <vector>
#include <numeric>
#include <cstdlib>
#include <cctype>
using namespace std;

void reverse_print_vec(vector<int> vec) {
    if (vec.size() == 0) return;
    cout << vec.back() << endl;
    vec.pop_back();
    reverse_print_vec(vec);
}

void count_down(int x) {
    if (x < 0) return;
    cout << x << endl;
    count_down(x-1);
}

//mpz_int - Boost multiprecision
//~ switches case in Vim
//Write factorial recursively! NO FOR LOOPS ARE ALLOWED TODAY
//5! = 5 * 4 * 3 * 2 * 1
//N! = N * (N-1)!
long long factorial(long long x) {
    //Base condition
    if (x <= 1) return 1;
    //Recursive 
    return x * factorial(x-1);
}

//YOU: Sum up a vector recursively
int sum_up(vector<int> vec) {
    if (vec.size() == 0) return 0;
    int temp = vec.back();
    vec.pop_back();
    return temp + sum_up(vec);
}
//YOU: Print the numbers from 1 to x


//TOPIC FOR TODAY IS RECURSION! FUN AND BRAIN MELTING
//x is the position in the fibonacci sequence to return
//fib(x) = fib(x-1) + fib(x-2)
unsigned int fib(unsigned int x) {
    //Caching - remember recently computed values and reuse them
    static vector<int> vec = {0,1,1}; //Static means a global only accessible here
    if (x < vec.size())
        return vec.at(x);
    vec.push_back(fib(x-1) + fib(x-2));
    return vec.back();
}

int main() {
    //vector<int> vec = {1, 2, 3, 4, 5};
    //reverse_print_vec(vec);
    cout << "Please enter a number:\n";
    int x = 0;
    cin >> x;
    cout << fib(x) << endl;
    string s;
    s = s + 'a';
    s += 'b';
    s += 'c';
    cout << s << endl;
    reverse(s.begin(),s.end());
    cout << s << endl;
}