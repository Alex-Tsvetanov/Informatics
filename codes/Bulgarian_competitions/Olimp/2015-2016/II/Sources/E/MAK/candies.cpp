#include<iostream>
using namespace std;
int main ()
{
long long a,b,c,br=0,k=1;
cin>>a>>b>>c;
while(k!=10)
{
if(a==0)break;
else {a=a-1;br++;}
if(b==0)break;
else {b=b-1;br++;}
if(c==0)break;
else {c=c-1;br++;}
if(b==0)break;
else {b=b-1;br++;}
}
cout<<br<<endl;
return 0;
}