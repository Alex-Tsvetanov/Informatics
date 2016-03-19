#include<iostream>
using namespace std;
long long a,b,c,brb,min1;
int main()
{
cin>>a>>b>>c;

if(a!=1  &&  a<b)brb=(a+b)+2;
else
if(a==b)brb=a+b+1;
else
if(a==1  && b==1)brb=3;
else
if(a==1  &&  b>a  &&  c>a)brb=4;

if(a>b  &&  c!=1)brb=a+b;
else
if(a>b  &&  c==1)brb=6;

if(b==1)brb=3;
if(c==1)brb=6;
if(a==b==c==1)brb=4;
if(b==c==1)brb=3;
if(a==c==1)brb=4;

if(b==c)brb=a+b+2;
if(a==c)brb=a+b+3;

if(a==0)brb=0;
if(b==0)brb=1;
if(c==0)brb=2;
cout<<brb<<endl;
return 0;
}
