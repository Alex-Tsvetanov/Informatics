#include<iostream>
using namespace std;
int main()
{
int a,b,c;
cin>>a>>b>>c;
int n=a&&b&&c;
while(n!=0)
{
cout<<n--;
cin>>n;
}
cout<<n<<endl;
return 0;
}
