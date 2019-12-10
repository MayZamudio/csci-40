#include <iostream>
using namespace std;

//Don't worry about compound interest unless you finish early
int main() {
    float annual_income = 0, years_till_retirement = 0;
    cout << "Please enter your annual income and years till retirement:\n";
    cin >> annual_income >> years_till_retirement;
    //1. Compute and output how much money they will make before retirement
    float money_before_retirement = annual_income * years_till_retirement;
    cout << "You'll make " << money_before_retirement << " dollars before retirement\n";

    //2. Ask them how much money they want to have per year when they've retired and how long they plan to live
    // This is basically the same as 1 but different variable names
    float retirement_income = 0, years_till_death = 0;
    cout << "Please enter your annual income and years till retirement:\n";
    cin >> retirement_income >> years_till_death;
    //1. Compute and output how much money they will make before retirement
    float money_after_retirement = retirement_income * years_till_death;

    //3. If they have enough money for retirement, tell them they're coolio
    // If they do not have enough money for retirement, tell them to die quicker
    if (money_before_retirement >= money_after_retirement) {
        cout << "You have enough money to retire, good job\n";
    } else {
        cout << "Learn to like the taste of cat food\n";
    }
}