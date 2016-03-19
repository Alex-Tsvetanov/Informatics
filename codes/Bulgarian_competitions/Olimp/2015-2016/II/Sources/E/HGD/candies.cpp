#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
long long A=0,B=0,C=0,i,j,k,n,a=1,b=1,c=1;
cin>>A>>B>>C;
if(b<=B)
{
for(n=1;n<=A;n++)
{
for(j=1;j<=B-1;j++)
for(k=2;k<=C;k++)
{
if(n-1==k) {a++;b++;}
if(n-1==i) {a++;b++;}
if(n-1==j)
{
if(n-2==i) {b++;c++;}
if(n-2==k) {a++;b++;}
}
}
}
}
cout<<a+b+c<<endl;
return 0;
}
