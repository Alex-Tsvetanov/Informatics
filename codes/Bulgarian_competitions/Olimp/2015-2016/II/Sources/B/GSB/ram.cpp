#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,i,j,z,p,m[100001],n[100001],max1,k,k1,l,l1,l2,b,a1;
int main()
{

    cin>>a;
    for(i=1; i<=sqrt(a)+50; i++)
    {
        for(j=1,z=3; j<=sqrt(a)+50; j++,z+=2)
        {
          if(((a+i)-j)%z==0)
          {
              k=((a+i)-j)/z;
              k1=j;


              if(k==1&&k1>k)b=2;
              else
              if(k1==1)b=1;
              else
                if(k1>k)b=k*2;
              for(l=k,l1=2,l2=3;l>l1;l1++,l2+=2)
              {
                  if(l1==k1)
                  {
                      b=l2;
                      break;
                  }
              }
              if(b==i)
              {
              //cout<<a+i<<endl;
              if(n[p]==((a+i)-j)/z&&m[p]==j);
              else
              {
              p++;
              n[p]=((a+i)-j)/z;
              m[p]=j;
              }
              }
              k1=((a+i)-j)/z;
              k=j;


              if(k==1&&k1>k)b=2;
              else
              if(k1==1)b=1;
              else
                if(k1>k)b=k*2;
              for(l=k,l1=2,l2=3;l>l1;l1++,l2+=2)
              {
                  if(l1==k1)
                  {
                      b=l2;
                      break;
                  }
              }
              if(b==i)
              {
              //cout<<a+i<<endl;
               if(m[p]==((a+i)-j)/z&&n[p]==j);
              else
              {
              p++;
              m[p]=((a+i)-j)/z;
              n[p]=j;
              }



              }
              }
          }
        }
    cout<<p<<endl;
    for(i=1; i<=p; i++) cout<<n[i]<<" "<<m[i]<<endl;
}
