///Simeon Atanasov Atanasov 7a MG
///NOI-2 2016 C3. Komputyrna mreja
#include<bits/stdc++.h>
#define endl '\n'
using namespace std;
vector <int> v[3000],nach;
queue <int> q;
int n,m,b,e;
int used[3000]={0};
bool f=true;
void dfs(int s)
{
    int j;
    used[s]=1;
    for(j=0;j<v[s].size();j++)
    {
        if(!used[v[s][j]])dfs(v[s][j]);
    }
}
void bfs(int s)
{
    int j;
    used[s]=1;
    q.push(s);
    ///cout << s << " ";
    while(!q.empty())
    {
        int p=q.front();
        q.pop();
        for(j=0;j<v[p].size();j++)
        {
            if(!used[v[p][j]])
            {
                ///cout << v[p][j] << " ";
                q.push(v[p][j]);
                used[v[p][j]]=1;
            }
            ///q.pop();
        }
    }
    ///cout << endl;
}
int main ()
{
    ios::sync_with_stdio(0);
    cin.tie(0);cout.tie(0);
    int i,j;
    cin >> n >> m; ///n=brv m=brr
    for(i=0;i<m;i++)
    {
        cin >> b >> e;
        v[b].push_back(e);
    }
    for(i=0;i<n;i++)
    {
        bfs(i);
        j=0;
        for(j=0;j<n;j++)
        {
            if(used[j]==0)f=false;
            used[j]=0;
        }
        if(f)nach.push_back(i);
        f=true;
    }
    ///sort(nach.begin(),nach.end());
    cout << nach.size() << endl;
    cout << nach[0];
    for(i=1;i<nach.size();i++)
    {
        cout << " " << nach[i];
    }
    cout << endl;
    return 0;
}
/**
8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4

**/
