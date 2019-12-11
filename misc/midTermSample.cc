#include <iostream>
#include <cmath>
#include <vector>

using namespace std;

int foo(int *p, int s) {
    int count = 0;
    for (int i = 0; i < s; i++) {
        if (p[i] == 42) count++;
    }
    return count;
}
bool win(const vector<char> &vec) {

    for (size_t i = 0; i < vec.size(); i++)

        if (vec.at(i) == 'X' && vec[i + 1] == 'X' && vec.at(i + 2) == 'X') return true;

    return false;

}
void fun(int a, int b, int &c) {

    c = a + b / c;

}
int main() {


    size_t SIZE = 1000;
    int *arr = new int[SIZE];
    *(arr+10) = 20;

    /*  vector<int>vec;
    for (int i = 0; i < 10; i++) {
        vec.push_back(i * 10);
    }
    for (auto elem : vec) {
        cout << "6.) " << elem << endl;
    }

    int x = 0;
    int *y = &x;
    *y = 12;

    cout << x << endl;
    //Question 9
    char c = 'A';
    cin >> c;
    if (c != toupper(c)) cout << "A";
    cout << "B";
        for (int i = 0; i < 10; i++) cout << i << endl;
        vector<int> vec;

        while (true) {

            int x = 0;

            cin >> x;

            if (!cin || x == 0) break;

            vec.push_back(x);

        }
                //to check array
            int z = 0;
            int *arr = new int[1000];

            //to check vectors
            vector<char> vec = {'X', 'O'};
            if (win(vec)) cout << "win" << endl;

            z = foo(arr, 2);
            cout << "result: " << z;
            //make sue to delete
            delete[] arr;*/
}