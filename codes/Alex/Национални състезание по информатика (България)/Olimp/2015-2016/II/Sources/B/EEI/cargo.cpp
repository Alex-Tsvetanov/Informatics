#include<iostream>
#include<algorithm>
#include<queue>
using namespace std;
struct fl
{
    int s,e;
    
};
bool operator< (fl a, fl b)
{
    return a.e>b.e;
}
bool cmp (fl a, fl b)
{
    if (a.s<b.s) return 1;
    else return 0;
}
fl f[1000100];
int buisness_days(int start, int end)
{
    int ans=0;
    start+=6;
    end+=6;
    while (start<end && (end-start)%7)
    {
        ++start;
        if (start%7<5) ++ans;
    }
    ans+=(end-start)/7*5;
    return ans;
}
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    int n,m,p;
    cin>>n>>m>>p;
    p/=2;
    for (int i=0;i<m;++i)
    {
        cin>>f[i].s>>f[i].e;
    }
    sort(f,f+m,cmp);
    int pos=0;
    priority_queue<fl> pq;
    bool mixed=1;
    int day=0;
    priority_queue<int> ds;
    ds.push(-n);
    for (int i=0;i<m;++i)
    {
        ds.push(-f[i].s);
        ds.push(-f[i].e);
    }
    int prd=0;
    while (1)
    {
        while (day==prd)
        {
            day=-ds.top();
            ds.pop(); 
        }
        //cout<<day<<" "<<prd<<endl;
        if (!pq.empty())
        {
            for (int i=0;i<p*(day-prd);++i)
            {
                //cout<<day<<" "<<pq.top().s<<" "<<pq.top().e<<endl;
                if (pq.empty()) break;
                pq.pop();
            }
            //cout<<" "<<day<<" "<<pq.top().s<<" "<<pq.top().e<<endl;
            if (!pq.empty() && pq.top().e<=day)
            {
                mixed=0;
                break;
            }
        }
        for (;pos<m;++pos)
        {
            if (f[pos].s<=day)
            {
                pq.push(f[pos]);
            }
            else break;
        }
        prd=day;
        if (ds.empty() || day>=n) break;
    }
    if (!pq.empty()) mixed=0;
    if (!mixed)
    {
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    day=0;
    pos=0;
    prd=0;
    while (!ds.empty()) ds.pop();
    ds.push(-n);
    for (int i=0;i<m;++i)
    {
        ds.push(-f[i].s);
        ds.push(-f[i].e);
    }
    while (1)
    {
        while (day==prd)
        {
            day=-ds.top();
            ds.pop(); 
        }
        //cout<<day<<" "<<prd<<endl;
        if (!pq.empty())
        {
            for (int i=0;i<p*buisness_days(prd,day);++i)
            {
                //cout<<day<<" "<<pq.top().s<<" "<<pq.top().e<<endl;
                if (pq.empty()) break;
                pq.pop();
            }
            //cout<<" "<<day<<" "<<pq.top().s<<" "<<pq.top().e<<endl;
            if (!pq.empty() && pq.top().e<=day)
            {
                mixed=0;
                break;
            }
        }
        for (;pos<m;++pos)
        {
            if (f[pos].s<=day)
            {
                pq.push(f[pos]);
            }
            else break;
        }
        prd=day;
        if (ds.empty() || day>=n) break;
    }
    if (!pq.empty()) mixed=0;
    if (!mixed)
    {
        cout<<"MIXED\n";
        return 0;
    }
    cout<<"OK\n";
    return 0;
}