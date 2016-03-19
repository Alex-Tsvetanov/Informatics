//Task: divisor
//Author: Kinka Kirilova-Lupanova
#include <iostream>

using namespace std;
int main()
{ long long n, p1, p2, x, q ;
  bool t;
  cin>>n;
  if (n<4) cout<<2*n<<endl;
  else 
       {p1=3; p2=5;
        while (p1+p2-2<n) 
              {t=false; x=p2;
               while (! t) 
                     {t=true; q=3; x=x+2;
                      while (t && q*q<=x) 
                            {t=x % q !=0;
                             q=q+2;
                            }
                     }
              p1=p2; p2=x;
             }
         cout<<p1*(n-p1+2)<<endl;
        }
return 0;
}                       

