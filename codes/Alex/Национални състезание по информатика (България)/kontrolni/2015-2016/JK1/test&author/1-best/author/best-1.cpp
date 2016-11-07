#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
int n, m, v1, v2, br, brcomp;
double p1, p2, ans;
pair<string, string> a[20010];
vector<string> b;
vector<string> c;
vector<int> d[10010];
vector<int> comp;
bool used[10010];
double dp[2][10010];

void dfs(int x)
{
    used[x]=1;
    br++;
    for(int i=0; i<d[x].size(); i++)
    {
        if (used[d[x][i]]==0)
        {
            dfs(d[x][i]);
        }
    }
}

int main()
{
    cin>>n>>m;
    cin>>p1>>v1;
    cin>>p2>>v2;

    if(p1>p2)
    {
        swap(p1, p2);
        swap(v1, v2);
    }
    for (int i=1; i<=m; i++)
    {
        string name1, name2;
        cin>>name1>>name2;
        transform(name1.begin(), name1.end(), name1.begin(), ::tolower);
        transform(name2.begin(), name2.end(), name2.begin(), ::tolower);
        a[i].first=name1;
        a[i].second=name2;
        b.push_back(name1);
        b.push_back(name2);
    }
    sort(b.begin(), b.end());
    c.push_back(b[0]);
    for (int i=1; i<b.size(); i++)
    {
        if(b[i]!=b[i-1])
        {
            c.push_back(b[i]);
        }
    }
    for(int i=1; i<=m; i++)
    {
        int num1=lower_bound(c.begin(), c.end(), a[i].first)-c.begin()+1;
        int num2=lower_bound(c.begin(), c.end(), a[i].second)-c.begin()+1;
        d[num1].push_back(num2);
        d[num2].push_back(num1);
    }

    m=c.size();
    n-=m;
    for(int i=1; i<=m; i++)
    {
        if (used[i]==0)
        {
            br=0;
            dfs(i);
            comp.push_back(br);
        }
    }


    for(int j1=0; j1<=v1; j1++)
    {
        dp[0][j1]=200000000;
    }
    if(comp[0]<=v1) dp[0][comp[0]]=comp[0]*p1;
    if(comp[0]<=v2) dp[0][0]=comp[0]*p2;
    int s=comp[0];
    int r=0;
    for(int i=1; i<comp.size(); i++)
    {
        s+=comp[i];
        r^=1;
        for (int j1=0; j1<=v1; j1++)
        {
            dp[r][j1]=200000000;
            int j2=s-j1;
            if (j2<0 || j2>v2) continue;
            if(comp[i]<=j1)
                dp[r][j1]=min(dp[r][j1], dp[r^1][j1-comp[i]]+comp[i]*p1);
            if(comp[i]<=j2)
                dp[r][j1]=min(dp[r][j1], dp[r^1][j1]+comp[i]*p2);
        }
    }
    ans=200000000;
    int p;
    for(int j1=0; j1<=min(m,v1); j1++)
    {
        if (m-j1<=v2)
        {
            if(dp[r][j1]<ans)
            {
                ans=min(ans,dp[r][j1]);
                p=j1;
            }
        }
    }

    v1-=p;
    v2-=m-p;
    if(n<=v1)
    {
        ans+=n*p1;
    }
    else
    {
        ans+=v1*p1;
        n-=v1;
        ans+=n*p2;
    }
    printf("%.2llf\n",ans);
    return 0;
}
/*
7 4
10 4
20 5
a b
b c
d e
f g
*/
