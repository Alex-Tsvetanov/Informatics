#include<iostream>
using namespace std;
int g[501];
int main()
{
    int n,k=0,a,b,c,d,e;
    long long m;
    cin>>n>>m;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        if(g[a]==0 and g[b]==0)
        {
            k++;
            g[a]=i+1;
            g[b]=i+1;
            goto here;
        }
        if(g[a]==0 and g[b]!=0)
        {
            g[a]=g[b];
            goto here;
        }
        if(g[a]!=0 and g[b]==0)
        {
            g[b]=g[a];
            goto here;
        }
        if(g[a]!=0 and g[b]!=0 and g[a]!=g[b])
        {
            c=g[a];
            d=g[b];
            e=min(c,d);
            for(int j=1;j<=n;j++)
            {
                if(g[j]==c or g[j]==d)
                {
                    g[j]=e;
                }
            }
            k--;
        }
        here:;
    }
    for(int i=1;i<=n;i++)
    {
        if(g[i]==0)
        {
            k++;
        }
    }
    cout<<k;
    return 0;
}
