#include <iostream>
using namespace std;

int main () {

 long long m, c, k, a, b;

 cin >> m >> c;
 cin >> k;

 if ( c * k < 10) {
    cout << m * k << " ";
    cout << c * k;
 }

 if ( c * k < 1000) {
    a = c * k / 10;
    b = a * 10;
    cout << m * k + a << " ";
    cout << c * k - b;
 }

 if ( c * k < 10000) {
    a = c *k/ 100;
    b = a * 100;
    cout << m * k + a << " ";
    cout << c * k - b;
 }

 if ( c * k == 10000) {
    a = c * k / 1000;
    b = a * 1000;
    cout << m * k + a << " ";
    cout << c * k - b;
 }




 return 0;
}
