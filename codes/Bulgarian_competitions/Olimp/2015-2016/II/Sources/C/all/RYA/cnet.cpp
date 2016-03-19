#include <iostream>
#include <vector>
#include <queue>
using namespace std;
int n,m;
bool r;
vector<int> v[3000];
int t[3000],br,brmin=1<<30;
void bfs(int s)
{
    queue<int> q;
    q.push(s);
    t[s]=0;
    int i;
    while(q.size()>0)
    {
        if(brmin<br){r=1;break;}
        int p=q.front( );
        q.pop( );
        for(i=0;i<v[p].size( );i++)
        {
            if(t[v[p][i]]==-1)
            {
                t[v[p][i]]=t[p]+1;
                if(br<t[v[p][i]])br=t[v[p][i]];
                q.push(v[p][i]);
            }
        }
    }
}
int main( )
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);
    cin>>n>>m;
    int i,b,e,res[3000],f,j,brv=0,vr[300];
    for(i=0;i<m;i++)
    {
        cin>>b>>e;
        v[b].push_back(e);
    }
    for(i=0;i<n;i++)
    {
        br=0;
        r=0;
        for(j=0;j<n;j++)t[j]=-1;
        bfs(i);
        f=0;
        for(j=0;j<n;j++)
        {
            if(t[j]==-1)
            {
                f=1;
                break;
            }
        }if(f==1)continue;

        res[i]=br;
        if(br<brmin)brmin=br;
    }
    for(i=0;i<n;i++)
        if(res[i]==brmin)
           vr[brv++]=i;
    cout<<brv<<endl;
    for(i=0;i<brv-1;i++)
           cout<<vr[i]<<" ";
    cout<<vr[brv-1]<<endl;
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
*/
