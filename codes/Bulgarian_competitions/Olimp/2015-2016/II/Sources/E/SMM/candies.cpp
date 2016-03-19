#include<iostream>
using namespace std;
int main()
{
int a,b,c,br;
cin>>a>>b>>c>>br;
while(a!=b&&c)
{
cin>>a;
if(a<b&&c)br++;
}
cout<<br<<endl;
return 0;
}
