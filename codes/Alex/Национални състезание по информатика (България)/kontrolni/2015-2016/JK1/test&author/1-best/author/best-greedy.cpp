#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
#include<vector>
using namespace std;
int n, m, v1, v2, br;
double p1, p2, ans=0;
pair<string, string> a[20010];
vector<string> b;
vector<string> c;
vector<int> d[10010];
vector<int> comp;
bool used[10010];

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
            comp.push_back(-br);
        }
    }
    sort(comp.begin(), comp.end());
    for(int i=0; i<comp.size(); i++)
    {
        comp[i]*=-1;
        if(comp[i]<=v1)
        {
            ans+=comp[i]*p1;
            v1-=comp[i];
        }
        else
        {
            if(comp[i]<=v2)
            {
                ans+=comp[i]*p2;
                v2-=comp[i];
            }

        }
    }
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
    printf("%.2llf\n", ans);
    return 0;
}
