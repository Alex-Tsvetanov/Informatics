#include<iostream>
#include<cstdio>
#include<vector>
#include<queue>
#include<cstring>
#define INF 1<<30
#define MAX_N 200003
using namespace std;
struct node
{
    int ver,edge;
    bool operator < (const node &p)const
    {
        return (edge>p.edge);
    }
    node () {};
    node(int x,int y)
    {
        ver=x;
        edge=y;
    }
};
int n,m,startp,endp;
unsigned dist[MAX_N];
vector<node> v[MAX_N];
void read()
{
    scanf("%d %d %d", &n, &startp, &endp);
    int i,x,y,z;
    while(cin>>x>>y)
    {
        v[x].push_back(node(y,0));
        v[y].push_back(node(x,1));
    }
}
void print2()
{
    int i;
    for(i=1;i<=n;i++)
        printf("%d ", dist[i]);
    printf("\n");
}
void init()
{
    int i;
    for(i=0;i<MAX_N;i++)
        dist[i]=INF;
}
void dijkstra(int start)
{
    bool used[MAX_N];
    init();
    //print2();
    memset(used, 0, sizeof(used));
    priority_queue<node> q;
    int i,sz,x,w;
    dist[start]=0;
    node u;
    q.push(node(start,0));
    while(!q.empty())
    {
        u=q.top(); q.pop();
        if(dist[u.ver]>=u.edge)
        if(!used[u.ver])
        {
            used[u.ver]=1;
            sz=v[u.ver].size();
            for(i=0;i<sz;i++)
            {
                x=v[u.ver][i].ver;
                w=v[u.ver][i].edge;
                if(dist[x]>w+u.edge)
                {
                    dist[x]=w+u.edge;
                    q.push(node(x,dist[x]));
                }
            }
        }
    }
}
void print()
{
    if(dist[endp]==INF)
        printf("X\n");
    else
        printf("%d\n", dist[endp]);
}
int main()
{
    read();
    dijkstra(startp);
    print();
	return 0;
}
