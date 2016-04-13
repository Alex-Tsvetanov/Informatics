#include<iostream>
#include<cstdio>
#include<cmath>
#include<algorithm>
using namespace std;
long long a,b,c,k,k1,i;
int main()
{
    cin>>a>>b>>c;
    for(i=1; i<=b; i++)
    {
        cin>>k>>k1;
    }
    if(c>b)
        cout<<"OK"<<endl;
        else
    if(b>=c*c) cout<<"IMPOSSIBLE"<<endl;
        else
        cout<<"MIXED"<<endl;
    return 0;
}
