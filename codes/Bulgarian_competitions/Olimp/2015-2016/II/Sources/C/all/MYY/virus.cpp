#include<iostream>
#include<vector>
#include<string>
using namespace std;
long long int fun(long long int n)
{
    long long int i,j=1,sum=0,pr1=1;
    for (i=n;i>=1;i--)
    {
        pr1*=2;
    }
    return pr1-1;
}
long long int a[1024];
string binary(long long int n,long long int x)
{
    string a;
    int i;
    for (i=0;i<x;i++)
    {
        a=char(n%2+48)+a;
        n/=2;
    }
    return a;
}
vector<long long int>v[1024];
void generatee(long long int n,long long int x,long long int posit)
{
    int i,j;
    for (i=1;i<=n;i++)
    {
        string k=binary(i,posit);
        for (j=0;j<posit;j++)
        {
            if (k[j]=='1')v[j].push_back(i);
        }
    }
}
int main()
{
    long long int n,i,j;
    cin>>n;
    for (i=1;i<=50;i++)
    {
        a[i]=fun(i);
    }
    for (i=1;a[i]<n;i++);
   // i--;
    generatee(n,i,i);j=i;
    if (n>500)
    {
        cout<<j<<endl;
        return 0;
    }
    cout<<j<<endl;
    for (i=0;i<j;i++)
    {
        int sz=v[i].size();
        cout<<sz<<" ";
        int j;
        for (j=0;j<sz;j++)
        {
            cout<<v[i][j]<<" ";
        }
        cout<<endl;
    }
    return 0;
}
