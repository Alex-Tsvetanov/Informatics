#include <iostream>
using namespace std;

int main () {

 long long a;
 long long b;
 long long c;

 cin >> a >> b >> c;

 if (a * b != c and a + b == c and a - b != c) {
    cout << "+";
    cout << endl;
 }

 if (a + b != c and a * b != c and a - b != c) {
    cout << "0";
    cout << endl;
 }

 if (a * b == c and a + b != c and a - b != c) {
    cout << "*";
    cout << endl;
 }

 if (a - b == c and a + b != c and a * b != c) {
    cout << "-";
    cout << endl;
 }

 if (a == 0 and b == 0 and c == 0) {
    cout << "+";
    cout << endl;
 }

 return 0;
}
