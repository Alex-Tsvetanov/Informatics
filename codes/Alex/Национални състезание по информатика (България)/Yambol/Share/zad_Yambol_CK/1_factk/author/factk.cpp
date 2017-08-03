//Task: factk
//Author: Kinka Kirilova-Lupanova
#include <iostream>
using namespace std;

int p[1000], a[1000], pn, mmin, i, j, k, l, m, n;
bool   f;

int find(int n, int m)
{int r;
  r = 0;
  while (n > 0) 
      {r = r + n / m;
       n = n / m;
      }
  return  r;
}

int main()
{ cin>>n>>k;
  p[1]= 2;
  pn = 1;
  i = 3;
  while (i <= k) 
    {j = 1;
     f = true;
     while (p[j] * p[j] <= i) 
       {if (i % p[j] == 0) 
          {f= false;
           break;
          }
        j++;
       }
    if (f) 
       {pn++;
        p[pn] = i;
       }
    i=i+2;
   }
 for (i = 1; i<= pn; i++) 
    a[i] = find(n, p[i]);
 mmin = 1000000000;
 for (j = 1; j<=pn; j++) 
       {l = 0;
        while (k % p[j] == 0) 
           {k = k / p[j];
            l++;
           }
        if (l > 0) 
           {if (a[j] / l < mmin) mmin = a[j] / l;
           }
       }
       
  if (mmin == 1000000000)  mmin = 0;

  cout<<mmin<<endl;
    return 0;
}


