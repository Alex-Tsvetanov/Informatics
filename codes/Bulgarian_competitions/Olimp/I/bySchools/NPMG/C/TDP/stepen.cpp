#include<iostream>
#include<math.h>
using namespace std;
int main ()
{
    int x,y[100000],i=1,d[100000],m=1;
    cin>>x;
    d[m]=2;
    for(int k=1;x!=0;k++){
    if(x%d[m]==0)
    {
        y[i]=x-x/2;
        x=x/2;
        i++;
        m++;

    }
    else d[m]++;
    cout<<i<<y<<m;
                        }
      cout<<i;
      for(int k=1;k<=i;k++)
      {
          for(int ii=1;ii<=i;ii++)
          {
              cout<<y[ii];

          for(int mm;mm<m;mm++)
          {
              cout<<" "<<mm<<endl;
          }
          }
      }
    //x=pow(a,b);
    //cout<<a<<b;
    return 0;
}
