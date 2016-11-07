#include<iostream>
using namespace std;
int main()
{int l,h,n,x,y,z,k,a,b,max=0,i,j,f,e,s;
cin>>l>>h>>n>>x>>y>>z>>k;
for(i=l;i>=1;i--)
{if(y>i&&k>+i)
for(j=h;j>=1;j--)
if(x>j&&z>=j)s=i*j;
if(s>max)max=s;
}
for(i=1;i<l;i++)
{if(y>=i&&k>i)
for(j=1;j<h;j++)
if(x>=j&&z>j){f=l-i;e=h-j;s=f*e;
if(s>max)max=s;
}
for(i=l;i>=1;i--)
{for(f=1;f<i;f++)
    if(y>i&&k>=i&&y>=f&&k>f)
for(j=h;j>=1;j--)
for(e=1;e<j;j++)
if(x>j&&z>=j&&x>=e&&z>e){a=i-f;b=j-e;s=a*b;};
if(s>max)max=s;
}
cout<<max<<endl;
return 0;
}}