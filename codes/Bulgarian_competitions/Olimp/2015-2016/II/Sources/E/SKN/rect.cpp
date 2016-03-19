#include<iostream>
using namespace std;
int main()
{
long long a,b,c,br=4,ar=br;
cin>>a>>b>>c;
for(int i=0; i<10; i++)
{

a--;
b-2;
c--;
cout<<a<<" "<<b<<" "<<c<<" ";
br++;
if(a==0 || b==0 || c==0)
{
ar=br;
}
}
cout<<ar;
return 0;
}

