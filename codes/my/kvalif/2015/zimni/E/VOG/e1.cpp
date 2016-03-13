#include <iostream>
using namespace std;

int main () {

 long long x,y,d,perimetar,p2,aa,ba,ab,bb;

 cin >> x >> y;
 cin >> d;

 perimetar = x*100+y;

 long long a,b;

 p2 = perimetar / 2;

 a = (p2 - d)/2;

 b = a+d;

 aa = a/100;
 ab = a%100;
 ba = b/100;
 bb = b%100;

 cout << ba << ' ' << bb << endl << aa << ' ' << ab << endl;

 return 0;
}
