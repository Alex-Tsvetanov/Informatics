#include<iostream>
using namespace std;
int main()
{
    long long a,b,c,d,g=3;
    cin>>a>>b>>c>>d;

    if(a==b)
    {
        g=g-1;
    }
    if(a==c)
    {
        g=g-1;
    }
    if(a==d)
    {
        g=g-1;
    }

if(a!=b)
{
    g=g-1;
}
if(a!=c)
{
    g=g-1;
}
if(a!=d)
{
    g=g-1;
}

if(g==0)
    if(a==b && b==c && c==d)
    {
        cout<<"YES"<<endl<<a;
        return 0;
    }
cout<<"YES"<<endl<<a*b;

if(g==1)
{
    if(a==b)
    {
        cout<<"YES"<<endl<<a*c;
    }
    if(a==c)
    {
        cout<<"YES"<<endl<<a*b;
    }
    if(a==d)
    {
        cout<<"YES"<<endl<<a*b;
    }
}
return 0;
}
