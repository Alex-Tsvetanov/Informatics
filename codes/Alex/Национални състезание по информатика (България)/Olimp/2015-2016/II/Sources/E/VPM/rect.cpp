#include <iostream>
#include <cstdlib>
using namespace std;
int main()
{
int a;cin>>a;int b=0,c=0;
while(b<a)
{
    b++;
    if((a-b)%(b*2+1)==0)c++;
}
cout<<c/2<<endl;


return 0;
}
