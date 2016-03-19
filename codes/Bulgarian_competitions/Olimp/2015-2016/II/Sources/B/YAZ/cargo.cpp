#include<iostream>
#include<vector>
#include<cstdio>
using namespace std;
vector<long long> days[10000010];
long long n,m,p,x[10000010],y[10000010],e,border,today[10000010];
long long used[10000010];
bool flag;
void read()
{
    cin>>n>>m>>p;
    for(long long i=1; i<=m; i++)
    {
        scanf("%d%d",&x[i],&y[i]);
        border=max(border,y[i]);
        for(long long j=x[i]; j<=y[i]; j++)
            days[j].push_back(i);
    }
    e=p/2;
}
long long solve()
{
    for(long long i=1; i<=border; i++)
    {
        today[i]=e;
        if(i%7!=0&&i%7!=6)
            for(long long j=0; j<days[i].size(); j++)
            {
                long long next=days[i][j];
                if(used[next]==0)
                {
                    today[i]--;
                    used[next]=i;
                }
                if(today[i]==0)
                {
                    break;
                }
            }
    }
    for(long long i=1; i<=m; i++)
        if(used[i]==0)
        {
            flag=1;
            if(x[i]%7==6)
                today[x[i]]--;
            if(today[x[i]]<0)return 3;
            if(y[i]%7==6)
                today[y[i]]--;
            if(today[y[i]]<0)return 3;
        }
    if(flag==1)return 2;
    return 1;
}
void print()
{
    long long rt=solve();
    if(rt==1)
    {
        cout<<"OK\n";
    }
    if(rt==2)
    {
        cout<<"MIXED\n";
    }
    if(rt==3)
    {
        cout<<"IMPOSSIBLE\n";
    }
}
int main()
{
    read();
    print();
    return 0;
}
