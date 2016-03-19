#include<iostream>
#include<queue>
#include<utility>
using namespace std;
long long k;
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>k;
    priority_queue<pair<long long,long long> > q;
    for(long long i=1;i<=100000;i++)
    {
        if((i+k)%(2*i+1)==0 && i<(i+k)/(2*i+1))
        {
            q.push(make_pair(-i,(i+k)/(2*i+1)));
        }
        if((i+k-1)%(2*i+1)==0 && i==(i+k-1)/(2*i+1))
        {
            q.push(make_pair(-i,(i+k-1)/(2*i+1)));
        }
        if((k-i-1)%(2*i-1)==0 && i>(k-i-1)/(2*i-1) && k-i-1>0)
        {
            q.push(make_pair(-i,(k-i-1)/(2*i-1)));
        }
    }
    for(long long j=1;j<=100000;j++)
    {
        if(k>j && (k-j)%(2*j-1)==0 && (k-j)/(2*j-1)<j)
        {
            q.push(make_pair(-(k-j)/(2*j-1),j));
        }
        if(k-j-1>0 && (k-j-1)%(2*j-1)==0 && j==(k-j-1)/(2*j-1))
        {
            q.push(make_pair(-(k-j-1)/(2*j-1),j));
        }
        if((k+j-1)%(2*j+1)==0 && (k+j-1)/(2*j+1)>j)
        {
            q.push(make_pair(-(k+j-1)/(2*j+1),j));
        }
    }
    priority_queue<pair<long long,long long> > q1;
    long long a=0,b=0;
    while(q.size()!=0)
    {
        if(a!=q.top().first || b!=q.top().second)
        {
            a=q.top().first;
            b=q.top().second;
            q1.push(make_pair(a,b));
        }
        q.pop();
    }
    cout<<q1.size()<<endl;
    while(q1.size()!=0)
    {
        cout<<-q1.top().first<<" "<<q1.top().second<<endl;
        q1.pop();
    }
    return 0;
}
