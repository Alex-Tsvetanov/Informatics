#include<bits/stdc++.h>
using namespace std;
long long n,m,pilots,used[10000010],a,b, um[10000010], av;
bool flag=false,mixed=false;
struct query
{
    int s,e;
}st[10000010];
bool f(query i,query j)
{
    if(i.e==j.e)
    {
        return i.s<j.s;
    }
    return i.e<j.e;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>pilots;
    pilots/=2;
    for(int i=0;i<m;i++)
    {
        cin>>a>>b;
        st[i].s=a;
        st[i].e=b;
    }
    sort(st,st+m,f);
    av=st[0].s;
    for(int i=0;i<m;i++)
    {
        a=st[i].s;
        b=st[i].e;
        flag=false;
        for(int j=av;j<=b;j++)
        {
            if((j%7!=0 && (j+1)%7!=0)&&used[j]<pilots)
            {
                used[j]++;
                av=j;
                if(used[j]==pilots)
                {
                    av++;
                }
                flag=true;
                j=b;
            }
        }
        if(!flag)
        {
            mixed=true;
            i=m;
        }
    }
    if(mixed)
    {
        av=st[0].s;
        for(int i=0;i<m;i++)
        {
            a=st[i].s;
            b=st[i].e;
            flag=false;
            for(int j=av;j<=b;j++)
            {
                if(um[j]<pilots)
                {
                    um[j]++;
                    av=j;
                    if(um[j]==pilots)
                    {
                        av++;
                    }
                    flag=true;
                    j=b;
                }
            }
            if(!flag)
            {
                cout<<"IMPOSSIBLE\n";
                return 0;
            }
        }
        cout<<"MIXED\n";
    }
    else
    {
        cout<<"OK\n";
    }
    return 0;
}
/*
100 7 4
2 5
3 4
5 7
8 9
6 8
6 9
9 11

OK
*/
