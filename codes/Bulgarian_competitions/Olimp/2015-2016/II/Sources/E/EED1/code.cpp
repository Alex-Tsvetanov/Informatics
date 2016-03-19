#include <iostream>
using namespace std;

int main()
{
  int c = 1000000,l = 0;
  string a,b;
  cin >> a;
  b = a;
  for (int j = 0; j < c; j++)
    {
      if (b[j] == '.')
        {
          c = 0;
          break;
        }
      if (l == 0)
        {
          j = 0;
          l++;
        }
      if (b[j] != b[j + 1] && b[j] != b[j - 1])
        {

        }

    }
}
