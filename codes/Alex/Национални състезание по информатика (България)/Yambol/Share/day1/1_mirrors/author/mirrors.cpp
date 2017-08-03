//Task: mirrors
//Author: Kinka Kirilova-Lupanova
#include <math.h>
#include <iostream>
# include <iomanip>

using namespace std;

int main ()
{
  int k, b, xp, yp, xb, yb;
  cin>>k>>b>>xp>>yp>>xb>>yb;
  double nx = k, ny = -1, nl = sqrt(nx*nx + ny*ny), d = fabs((double)k*xb - yb + b)/nl;

  nx /= nl;
  ny /= nl;
  
  if (k*xb - yb + b > 0)
  {
    nx = -nx;
    ny = -ny;
  }
  
  double 
    xb1 = xb + 2*d*nx, yb1 = yb + 2*d*ny,
    dv = sqrt( (xp-xb)*(xp-xb)+ (yp-yb)*(yp-yb)),
    dm = sqrt((xp-xb1)*(xp-xb1)+ (yp-yb1)*(yp-yb1));
    
  if (dv < dm)
    cout<<fixed<<setprecision(6)<<dv<<endl;
  else
    cout<<fixed<<setprecision(6)<<dm<<endl;
    
  return 0;
}
