#include<bits/stdc++.h>
#define MAXK 3010
#define MAXVALL (1LL<<31)-1
#define endl '\n'
using namespace std;

vector<int> G[MAXK];
bool used[MAXK];
queue<int> q;
int mas[MAXK],mas_s[MAXK],z,k;
long long dk,br;

void bfs (int s)
{
    k=0;
    q.push(s-1);
    used[s]=true;
    while(!q.empty())
    {
        for(int i=0; i<G[q.front()].size(); ++i)
        {
            if(!used[G[q.front()][i]])
            {
                q.push(G[q.front()][i]);
                used[G[q.front()][i]]=true;
            }
        }
        k++;
        q.pop();
    }
    mas[z]=k;
    z++;
}

int main()
{
    int m,n,b,e;
    z=-1;
    scanf("%d%d",&n,&m);
    for(int i=0;i<m;++i)
    {
        scanf("%d%d",&b,&e);
        G[b].push_back(e);
        G[e].push_back(b);
    }
    for(int i=0;i<n;++i)
    {
        bfs(i);
    }
    dk=MAXVALL;
    for(int i=0;i<n;++i)
    {
        if(mas[i]<dk)dk=mas[i];
    }
    for(int i=0;i<n;++i)
    {
        if(mas[i]==dk){br++;mas_s[br]=i;}
    }
    cout<<br+1<<endl;
    for(int i=0;i<=br;++i)
    {
        if(i==0)cout<<mas_s[0];
        else cout<<" "<<mas_s[i];
    }
    cout<<endl;
    return 0;
}
