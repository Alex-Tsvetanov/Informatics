#include <iostream>
using namespace std;
int main()
{
    int i,n,j,h,r,l,a,b,c,br=0;
    cin>>a>>b>>c;
      while(a!=0 && b!=0 && c!=0)
      {
        for(i=a; n<b; i++)
        {
          if(i=n)
          {
           i--;
           n--;
          }
           br++;
           cin>>a;
          }
        for(j=b; h=c; j++)
        {
          if(j=n)
          {
           j--;
           h--;
          }
           br++;
           cin>>b;
        }
        for(r=c; n=a; r++)
        {
          if(r=l)
          {
           r--;
           l--;
          }
           br++;
           cin>>c;
           }
      }
    cout<<br<<endl;
    return 0;
}
