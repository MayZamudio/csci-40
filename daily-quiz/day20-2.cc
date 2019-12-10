#include <fstream>
#include <iostream>
#include <cmath>
#include <algorithm>
#include <vector>
using namespace std;

bool anagram(string s1, string s2) {
    sort(s1.begin(),s1.end());
    sort(s2.begin(),s2.end());
    if (s1 == s2) return true;
    return false;
}

bool palindrome(string s) {
    for (size_t i = 0; i < s.size() / 2; i++) {
        if (s.at(i) != s.at(s.size()-1-i)) return false;
    }
    return true;
}

int main() {
    string s1, s2;
    cout << "Please enter two strings:\n";
    cin >> s1 >> s2;
    //Part 1 - Do anagram detection
    //Example: DERE and REED are anagrams
    if (anagram(s1,s2)) cout << s1 << " is an anagram of " << s2 << endl;
    else cout << s1 << " ain't an anagram of " << s2 << endl;
    //Part 2 - Do palindrome detection
    //RADAR is a palindrome, as is TACOCAT, as is AMANAPLANACANALPANAMA
    if (palindrome(s1)) cout << s1 << " is an palindrome\n";
    if (palindrome(s2)) cout << s2 << " is an palindrome\n";

    //Part 3 - If you get the above done, use an ifstream with /usr/share/dict/words
    //And see if s1 and s2 are anagrams of any word in the dictionary
    //Part 4 - Print all palindromes in the dictionary
    ifstream ins("/usr/share/dict/words");
    while (ins) {
        string temp;
        ins >> temp;
        if (!ins) break;
        if (anagram(temp,s1)) cout << s1 << " is an anagram of " << temp << endl;
        if (anagram(temp,s2)) cout << s2 << " is an anagram of " << temp << endl;
        if (palindrome(temp)) cout << temp << " is a palindrome.\n";
    }


}