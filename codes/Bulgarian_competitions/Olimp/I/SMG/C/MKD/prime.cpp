#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
bool f(int k)
{
    if(k%2==0)
    {
        return false;
    }
    int t=3,r=sqrt(k);
    while(t<=r)
    {
        if(k%t==0) return false;
        t+=2;
    }
    return true;
}
int main()
{
    char p[3001];
    int n=3;
    long long s=0;
    cin>>p;
    if(p[0]=='1') s+=2;
    for(int i=1;i<strlen(p);i++)
    {
        s+=(p[i]=='1')*n;
        while(true)
        {
            n+=2;
            if(f(n)) break;
        }
    }
    cout<<s;
    return 0;
}
