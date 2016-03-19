#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<queue>
using namespace std;
long long n,m,p,a[100001],b[100001];
int used[100001];
bool flagg=0;
long long rec(long long x)
{
    if(x==m)
    {
        if(flagg==0)
        {
            cout<<"OK"<<endl;
        }
        else
        cout<<"MIXED"<<endl;
        exit(0);
    }
    queue<int> q;
    for(long long i=a[x];i<=b[x];i++)
    {
        if(i%7==0 || i%7==6)
        {
            q.push(i);
        }
        else
        if(used[i]<p/2)
        {
            used[i]++;
            rec(x+1);
            used[i]--;
        }
    }
    flagg=1;
    while(q.size()!=0)
    {
        int j=q.front();
        q.pop();
        if(used[j]<p/2)
        {
            used[j]++;
            rec(x+1);
            used[j]--;
        }
    }
    flagg=0;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>n>>m>>p;
    for(int i=0;i<m;i++)
    {
        cin>>a[i]>>b[i];
    }
    queue<int> q;
    for(long long j=a[0];j<=b[0];j++)
    {
        if(j%7==0 || j%7==6)
        q.push(j);
        else
        {
            used[j]++;
            rec(1);
            used[j]--;
        }
    }
    flagg=1;
    while(q.size()!=0)
    {
        int j=q.front();
        q.pop();
        used[j]++;
        rec(1);
        used[j]--;
    }
    cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
