#include <iostream>
using namespace std;

int main() {

 long long a, b, c, d, sum;
 cin >> a >> b >> c >> d;

 if (a==b) {
  sum=b+c;
  c=sum-c;
  b=sum-b;
 }

 if (a==d) {
  sum=d+c;
  c=sum-c;
  d=sum-d;
 }

 if (b==c) {
  sum=c+d;
  c=sum-c;
  d=sum-d;
 }

 if (a==c and b==d) {
  cout << "Yes" << endl << a*b << endl;
 }

 else {
  cout << "No" << endl << a+b+c+d << endl;
 }












 return 0;
}
