#include<iostream>
using namespace std;
int t[20],sum=1,p,n,s;
void f(int i,int l)
{
    if(i==n+1)
    {
        return;
    }
    if(l==s)
    {
        return;
    }
    t[i]++;
    if(t[i]==p)
    {
        t[i]--;
        f(i+1,l);
    }
    sum++;
    f(i,l+1);
    f(i+1,l+1);
}
int main()
{
    cin>>p>>n>>s;
    f(1,0);
    cout<<sum;
    return 0;
}
