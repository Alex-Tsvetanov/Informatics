#include<iostream>
using namespace std;
int main()
{
    long long m, n, s, a=0;
    cin>>m>>n;
    s=m*n;
    while(m>1)
    {
        if(m%2==0)
        {
            ///cout<<"chetno";
            s=s/m;
            m=m/2;
            a++;
        }
        else
        {
            ///cout<<"nechetno";
            m=m/2+1;
            s-=m;
            ++a;
        }
    }
    while(n>1)
    {
        if(n%2==0)
        {
            ///cout<<"chetno";
            s=s/n;
            n=1;
            a++;
        }
        else
        {
            ///cout<<"nechetno";
            n=n/2+1;
            s-=n;
            ++a;
        }
    }
    cout<<a;
    return 0;
}
