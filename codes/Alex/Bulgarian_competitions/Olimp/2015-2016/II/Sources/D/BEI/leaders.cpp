#include<iostream>
using namespace std;
int main()
{
    long long i,n,c[1000000],j,g=0,p=0;
    cin>>n;
    for(i=0;i<n;i++)
    {
        cin>>c[i];
        if(g<c[i]){g=c[i];p=i;}
    }
    for(i=p;i<n-1;i=p)
    {
        cout<<c[i]<<' ';
        g=0;
        for(j=i+1;j<n;j++)
        {
            if(g<c[j]){g=c[j];p=j;}
        }
    }
    cout<<c[n-1]<<endl;
    return 0;
}
