#include<iostream>
#include<cstdio>
#include<algorithm>

using namespace std;

int n,m,p;

struct tuhla
{
    int a,b;
} s[1000000];

bool cmp(tuhla q, tuhla w)
{
    if(q.a!=w.a) return q.a<w.a;
    else return q.b<w.b;
}

void read()
{
    scanf("%d%d%d",&n,&m,&p);
    for(int i=0;i<m;i++)
    {
        scanf("%d%d",&s[i].a,&s[i].b);
    }
}

int ok()
{
    int i,r=0,curr,cr=0,br=0;
    for(i=0;i<n;i++)
    {
        if(i%7==0 || (i+1)%7==0) continue;
        if(s[r].a<=i && s[r].b>=i)
        {
            cr++;
            curr=s[r].a;
            r++;
            br=1;
            while(s[r].a==curr)
            {
                if(br==p/2) break;
                br++;
                r++;
                cr++;
            }
        }
    }
    if(cr==m)
    {
        return 1;
    }
    else return 0;
}

int mix()
{
    int i,r=0,curr,cr=0,br=0;
    for(i=0;i<n;i++)
    {
        curr=0;
        if(s[r].a<=i && s[r].b>=i)
        {
            cr++;
            curr=s[r].a;
            r++;
            br=1;
            while(s[r].a==curr)
            {
                if(br==p/2) break;
                br++;
                r++;
                cr++;
            }
        }
    }
    if(cr==m)
    {
        return 1;
    }
    else return 0;
}

void solve()
{
    sort(s,s+m,cmp);
    if(ok()==1)
    {
        printf("OK\n");
        return;
    }
    if(mix()==1)
    {
        printf("MIXED\n");
        return;
    }
    printf("IMPOSSIBLE\n");
}

int main()
{
    read();
    solve();
    return 0;
}
