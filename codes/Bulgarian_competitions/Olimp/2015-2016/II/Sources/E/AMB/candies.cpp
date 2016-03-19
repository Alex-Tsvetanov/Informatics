#include <iostream>
using namespace std;
int main()
{
int a,b,c,i,s,br=0;
cin>>a>>b>>c;
s=a+b+c;
while(a>0||b>0||c>0)
{
if(a==0)break;
else{a--;br++;}
if(b==0)break;
else{b--;br++;}
if(c==0)break;
else{c--;br++;}
if(b==0)break;
else{b--;br++;}
}
cout<<br<<endl;
return 0;
}
