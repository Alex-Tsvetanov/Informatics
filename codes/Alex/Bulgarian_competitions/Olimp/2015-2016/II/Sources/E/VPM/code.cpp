#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
char a;
char b;
int s=0,r=0;
while(a!='.')
{cin>>a;
if(b==a){s=s;}
else
{b=a;
s++;}
r++;}
if(r-s-1<0)cout<<0<<endl;
else cout<<r-s-1<<endl;
return 0;
}
