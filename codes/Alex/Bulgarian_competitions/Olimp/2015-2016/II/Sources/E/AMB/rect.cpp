#include <iostream>
using namespace std;
int main()
{
int brkv=0,n,i,x,brkl=0;
cin>>n;
x=3;
for(i=4;i<=n;i+=3)
{
if((n-4)%x==0)brkv++;
else{break;cout<<brkv<<endl;}
}
cout<<brkv<<endl;
return 0;
}

