#include <iostream>
using namespace std;

int main()
{
  int a,b,c,a1,b1,c1,e,z;
  z = 0;
  a1 = 0;
  cin >> a >> b >> c;
  e = 1;
  while (z != 1) // dokato nqma prazna kupa
    {
      while (e == 1 && a > 0) //1va kupa
        {
          if (b == 0 || c == 0)
            {
              z = 1;
            }
          a--;
          a1++;
          e++;
        }
      while (e == 2 && b != 0) //2ra kupa
        {
          if (a == 0 || c == 0)
            {
              z = 1;
            }
          b--;
          a1++;
          e++;
        }
      while (e == 3 && c != 0) //3ta kupa
        {
          if (a == 0 || b == 0)
            {
              z = 1;
            }
          c--;
          a1++;
          e--;
        }
    }
  cout << a1 << endl;
  return 0;
}
