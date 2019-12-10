#include <iostream>
#include <fstream>
#include <cmath>
using namespace std;
using std::cout;
using std::pow;
using std::sqrt;
using std::exp;
using std::cin;
using std::endl;
using std::ofstream;

int main() {
    int x = 0, y = 0;
    cin >> x >> y;
    ofstream outs("kitsune.txt",std::ofstream::app);
    outs << x * y << endl;
    cout << pow(sqrt(x),std::exp(3)) << " I LOVE STDS!\n";
}