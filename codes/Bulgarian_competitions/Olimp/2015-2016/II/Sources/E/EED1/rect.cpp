#include <iostream>
using namespace std;

int main()
{
  int a,b,c,d;
  c = 0;
  d = 0;
  b = 4;
  cin >> a;
  d = a / 8;
  for (int j = 1; j <= a; j++)
    {
      a--;
    }
  if (a > 0) d = 0;
  cout << d << endl;
}
