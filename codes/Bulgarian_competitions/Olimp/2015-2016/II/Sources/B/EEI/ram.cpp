#include<iostream>
#include<algorithm>
#include<vector>
#include<math.h>
using namespace std;
int b(int n, int m)
{
    if (m>=n) return 2*n-1;
    return 2*m;
}
int f(int n, int m)
{
    return 2*n*m+n+m-b(n,m);
}
vector<pair<int, int> > sols;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(0);
    unsigned long long k,m,n,pr=0,curr;
    cin>>k;
    for (m=1;;++m)
    {
        n=m+k;
        curr=n%(2*m+1);
        //cout<<" "<<m<<" "<<n%(2*m+1)<<endl;
        if (pr>curr)
        {
            m+=curr/(pr-curr)-1;
            pr=0;
            continue;
        }
        pr=curr;
        if (2*m+1>n) break;
        if (n%(2*m+1)==0)
        {
            n/=2*m+1;
            if (m<n) sols.push_back(make_pair(m,n));
            else break;
        }
    }
    pr=0;
    for (n=1;;++n)
    {
        m=n+k-1;
        curr=m%(2*n+1);
        //cout<<" "<<n<<" "<<m%(2*n+1)<<endl;
        if (pr>curr)
        {
            n+=curr/(pr-curr)-1;
            pr=0;
            continue;
        }
        pr=curr;
        if (2*n+1>m) break;
        if (m%(2*n+1)==0)
        {
            m/=2*n+1;
            if (n<=m) sols.push_back(make_pair(m,n));
            else break;
        }
    }
    sort(sols.begin(),sols.end());
    cout<<sols.size()<<'\n';
    for (int i=0;i<sols.size();++i)
    {
        cout<<sols[i].first<<' '<<sols[i].second<<'\n';
    }
    return 0;
}