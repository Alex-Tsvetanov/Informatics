//Task: best, O(N*N)
//Authors: Alexander Ivanov & Yoana Zelova
#include <iostream>
#include <cstdio>
#include <vector>
#include <map>
#include<queue>
#include<cfloat>
using namespace std;
using ldouble=long double;

int idCount=0;
map<string, int> idOf;
int get_id(string name)
{
    for(char &c : name)
    {
        if(c>='A'&&c<='Z')c+=(int('a')-int('A'));
    }
    if(idOf.find(name)==idOf.end())
    {
        idOf[name]=++idCount;
    }
    return idOf[name];
}

int n, m, v1, v2;
ldouble p1, p2;
vector<vector<int> > gr;

void read()
{
    cin>>n>>m;
    cin>>p1>>v1;
    cin>>p2>>v2;

    gr.resize(n+1);
    for(int i=0; i<m; i++)
    {
        string a, b;
        cin>>a>>b;
        int x=get_id(a), y=get_id(b);
        gr[x].push_back(y);
        gr[y].push_back(x);
    }
}

int bfs(int fr, vector<bool> &used)
{
    int rt=1;
    queue<int> q;
    q.push(fr);
    used[fr]=1;
    while(!q.empty())
    {
        int x=q.front();
        q.pop();
        for(int i=0; i<gr[x].size(); i++)
        {
            int next=gr[x][i];
            if(!used[next])
            {
                q.push(next);
                used[next]=1;
                rt++;
            }
        }
    }
    return rt;
}

void solve()
{
    vector<bool> used(n+1, false);
    vector<int> friendships;
    ldouble answer=LDBL_MAX;
    for(int i=1; i<=n; i++)
    {
        if(!used[i])friendships.push_back(bfs(i, used));
    }

    int dp[10010];
    dp[0]=1;
    for(int i : friendships)
    {
        for(int j=0;j+i<=v1;j++)
            if(dp[j])dp[i+j]=1;
    }
    for(int i=0;i<=v1;i++)
    {
        if(dp[i])
           if(n-i<=v2) answer=min(answer, p1*i+p2*(n-i));
    }
    printf("%.2llf\n", answer);
}

main()
{
    ios::sync_with_stdio(false);
    cin.tie(nullptr);
    read();
    solve();
}


