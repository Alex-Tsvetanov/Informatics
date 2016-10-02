#include <iostream>
using namespace std;

int main() {

  long long x, y, d, P, a, b, poluP;
  cin >> x >> y >> d;
  P=x*100+y;
  poluP=P/2;
  a=(poluP-d)/2;
  b=a+d;

  cout << b/100 << ' ' << b%100 << endl;
  cout << a/100 << ' ' << a%100 << endl;

  return 0;
}
