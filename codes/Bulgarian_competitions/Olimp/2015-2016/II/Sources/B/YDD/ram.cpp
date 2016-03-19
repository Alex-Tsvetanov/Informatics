#include<iostream>
#include<algorithm>
#include<vector>
#include<ctime>
#define MAX_N 1000000
using namespace std;
long long int k;
int check(long long int x,long long int y)
{
    long long int ogr=x*(y+1)+(x+1)*y,br;
    if(x<=y)
        br=ogr-x-x+1;
    if(y<x)
        br=ogr-y-y;
    if(br==k)
        return 0;
    if(br>k)
        return 1;
    return -1;
}
int binary_search2(long long int x)
{
    long long int l=1,r=MAX_N,mid;
    while(l<=r)
    {
        mid=(l+r)/2;
        long long int prov=check(x,mid);
        if(prov==0)
            return mid;
        if(prov==1)
            r=mid-1;
        else
            l=mid+1;
    }
    return -1;
}
void solve()
{
    vector< pair<int,int> > ans;
    long long int i,otg;
    for(i=1;i<=MAX_N;i++)
    {
        otg=binary_search2(i);
        if(otg!=-1)
            ans.push_back(make_pair(i,otg));
    }
    int sz=ans.size();
    cout<<sz<<endl;
    for(i=0;i<sz;i++)
        cout<<ans[i].first<<' '<<ans[i].second<<endl;
}
int main ()
{
    cin>>k;
    solve();
	return 0;
}
