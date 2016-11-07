#include<iostream>
using namespace std;
unsigned long long n,k;

char a,b;
long long fact(int j)
{
    unsigned long long br1=1;
    for(int i=1;i<=j;i++)
        br*=i;
    return br;
}
int main()
{
    cin>>n>>k;
    a='A'+n/k;
    k/=(n/k);
    cout<<a;
    b=a;
    for(int i=1;i<n-1;i++)
    {
       a='A'+k/n;
       k/=n;
       if(a==b)
        a++;
       cout<<a;
       b=a;
    }
    a='A'+k%n;
    if(a==b)a++;
    cout<<a;
}
/**
3 7
*/
