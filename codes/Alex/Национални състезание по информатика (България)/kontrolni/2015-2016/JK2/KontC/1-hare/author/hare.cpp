//Task: hare
//Author: Kinka Kirilova-Lupanova

  #include <iostream>
  #include <math.h>
  using namespace std;
 long long gcd(long long a, long long b)
 {long long r;
  while (b!=0)    
    {r=a%b;
     a=b;
     b=r;
    }
  return a;
  } 
void extended_euclid(long long a, long long b, long long &x1, long long &y1)
{ int q, r, x2,  y2,  t;
  x1 = 1; y1 = 0;
  x2 = 0; y2 = 1; 
  while (b != 0) 
        {q = a/ b; 
         r = a % b;
         a=b;b=r;
         t=x2;
         x2=x1-q*x2;
         x1=t;
         t=y2;
         y2=y1-q*y2;
         y1=t;
        } 
}

  int main()
{long long a, b, c, x, y, answer  ;
 cin>>a>>b>>c;
 if (c < 0)  c = -c;
 long long d=gcd(a,b);
 if (c%d==0) 
  { a=a/d;
    b=b/d;
    c=c/d;
   extended_euclid(a,b, x, y);
   long long x0=x*c; 
   long long y0=y*c; 
   long long kmin = (long long)ceil(-1.0 * x0 / b); 
   long long kmax = (long long)floor(1.0 * y0 / a);
   
   // ----- slu4aj 1: x >= 0, y >= 0 -----
   if (kmax >= kmin)  answer = x0 + kmin * b + y0 - kmin * a;
  
  // ----- slu4aj 2: x >= 0, y <= 0 -----
  long long k2 = max(kmin, kmax + 1);
  long long ans = x0 + k2 * b - y0 + k2 * a;
  if (answer < 0 || ans < answer) answer = ans;
 
  // ----- slu4aj 3: x <= 0, y >= 0 -----
  long long k3 = min(kmin - 1, kmax);
  ans = y0 - k3 * a - x0 - k3 * b;
  if (answer < 0 || ans < answer) answer = ans;
  cout << answer<<endl;
  }
 else cout<<"Impossible\n"; 
 return 0;
}  

