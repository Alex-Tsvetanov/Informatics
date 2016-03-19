#include <iostream>
using namespace std;
int main()
{
    long long i,j,t,a,b,c,br=0,acpy,bcpy,ccpy,min;
    cin>>a>>b>>c;
    acpy=a;
    bcpy=b;
    ccpy=c;
    min=a;
    if(min>b)min=b;
    if(min>c)min=c;
    if(acpy==0)cout<<"0"<<endl;
else
    if(bcpy==0 && acpy>0)cout<<"1"<<endl;
    else
    if(ccpy==0 && acpy>0 && bcpy>0)cout<<"2"<<endl;
else
if(min==c)cout<<c*3+2<<endl;
else
if(min==a)cout<<a*3<<endl;
else
if(min==b)cout<<b*3+1<<endl;

    return 0;
}
