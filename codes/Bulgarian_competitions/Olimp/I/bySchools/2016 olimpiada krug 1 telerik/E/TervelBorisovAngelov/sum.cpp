#include<iostream>
using namespace std;
int main()
{
    long long a,b,ca,da,ea,cb,db,eb;
    char j='+';
    cin>>a>>j>>b;
    long long t=a,p=b;
    ca=a/100;
    da=(a/10)%10;
    ea=a%10;
    cb=b/100;
    db=(b/10)%10;
    eb=b%10;
    if(ea+eb>=10)
    {
        a=a-10;
    }
    if(da+db>=10)
    {
        a=a-100;
    }
    cout<<a+b<<endl;
    cout<<t+p;
    return 0;
}
