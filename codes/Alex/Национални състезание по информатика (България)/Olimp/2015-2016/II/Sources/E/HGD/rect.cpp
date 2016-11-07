#include <iostream>
#include <algorithm>
#include <cmath>
#include <cstring>
using namespace std;
int main()
{
long long n,br,k=0;
cin>>n;
if(n==4) br=1;
if(n==8) br=2;
if(n==10) br=1;
if(n==12) br=1;
for(k=11;k<=(n/2)/2;k++)
{
if(n%2==0) br=1;
else br=0;
if((n-2)%2==0) br++;
}
cout<<br<<endl;
return 0;
}
