#include<iostream>
#include<fstream>
#include<queue>
#include<vector>
#define MAXN 200000
using namespace std;
int a,b,n, p,q, top, s=1,component[MAXN];
bool used[MAXN];
vector< vector<int> > t;
void bfs(int v)
{
    queue<int> q;
    q.push(v);
    used[v]=1;
    while(!q.empty())
    {
        top=q.front();
        for(int i=0;i<t[top].size();i++)
        {
            if(used[t[top][i]]==0)
            {
                used[t[top][i]]=1;
                q.push(t[top][i]);
            }
        }
        if(component[top]==0) component[top]=s;
        q.pop();
    }
}

int main()
{
    cin>>n>>a>>b;
    while(cin.eof())
    {
        cin>>p>>q;
        t[p].push_back(q);
    }
    for(int i=1;i<=n;i++)
    {
        if(used[i]==0)
        {
            bfs(i);
            s++;
        }
    }
    if(component[a]==component[b]) cout<<0<<endl;
    else cout<<"X"<<endl;
    return 0;
}
