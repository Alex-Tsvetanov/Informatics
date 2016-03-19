#include<bits/stdc++.h>
using namespace std;
int days,q,ek;
int x[1048576];
pair<int,int>p[1048576];
int ans;
bool cmp(pair<int,int>a,pair<int,int>b)
{
    if(a.second>b.second)return 1;
    else if(a.second==b.second)
    {
        if(a.first>b.first)return 1;
        else return 0;
    }
    else return 0;
}
int find_next(int i,int j)
{
    int m=i;
    while((x[i]==ek || (i%7==6 || i%7==0)) && i<=j)
        i++;
    if(i==j+1)
    {
        i=m;
        while(x[i]==ek && i<=j)
            i++;
        return i;
    }
    return i;
}
int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cin>>days>>q>>ek;
    ek/=2;
    for(int i=0;i<q;i++)
        cin>>p[i].first>>p[i].second;
    sort(p,p+q,cmp);
    for(int i=0;i<q;i++)
    {
        int idx=find_next(p[i].first,p[i].second);
        if(idx==p[i].second+1)
        {
            ans=2;
        }
        else x[idx]++;
        if((idx%7==6 || idx%7==0) && ans==0)ans=1;
    }
    if(ans==0)cout<<"OK"<<endl;
    if(ans==1)cout<<"MIXED"<<endl;
    if(ans==2)cout<<"IMPOSSIBLE"<<endl;
    return 0;
}
