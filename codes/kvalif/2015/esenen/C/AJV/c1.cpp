#include<iostream>
using namespace std;
long long n,m,sysedi[1000][1000],zaetolie[1000],kolko=0,sysednaa[1000];
long long pretyrsvane(long long kydesym)
{
    zaetolie[kydesym]=1;
    for(long long i=0; i<sysednaa[kydesym]; i++)
    {
        if(zaetolie[sysedi[kydesym][i]]==0)
        {
            pretyrsvane(sysedi[kydesym][i]);
        }
    }
}
int main()
{
    cin>>n>>m;
            long long a,b;
    for(long long i=0; i<m; i++)
    {
        cin>>a>>b;
        sysedi[a][sysednaa[a]]=b;
        sysednaa[a]++;
        sysedi[b][sysednaa[b]]=a;
        sysednaa[b]++;
    }
    for(long long i=1; i<=n; i++)
    {
        if(zaetolie[i]==0)
        {
          //  cout<<i;
            kolko++;
            pretyrsvane(i);
        }
    }
    cout<<kolko;
    return 0;
}
/*
if(zaetolie[a]!=1 and zaetolie[b]!=1){
kolko++;
}
zaetolie[a]=1;
zaetolie[b]=1;*/
