#include <iostream>
#include <algorithm>
using namespace std;
int main()
{
    unsigned long long int a[3001],b[100001],c[10001],n,m,i,max,br=0;
    unsigned long long int d[10001];
    cin>>n>>m;
    for(i=0; i<m; i++)
    {
        cin>>a[i]>>b[i];
        c[a[i]]++;
        d[a[i]]++;
    }
    sort(d,d+n);
    max=d[n-1];
    for(i=0; i<m; i++)
    {
        if(c[i]==max)br++;
    }
    cout<<br<<endl;
    for(i=0; i<m; i++)
    {
        if(c[i]==max)cout<<i<<" ";
    }
    return 0;
}
