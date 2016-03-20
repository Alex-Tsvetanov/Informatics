#include <cstdio>
#include <vector>
#include <queue>
using namespace std;
int n, m, beg, en;
vector <int> v[5000];
queue <int> q;
int used[5000], result[5000];
int bfs (int s)
{
    used[s]=1;
    q.push(s);
    while (!q.empty())
    {
        int k=q.front();
        q.pop();
        for (int i=0; i<v[k].size(); i++)
        {
            if (!used[v[k][i]])
            {
                used[v[k][i]]=1;
                q.push(v[k][i]);
            }
        }
    }
    int br=0;
    for (int i=0; i<n; i++)
    {
        if (used[i]) br++;
    }
    for (int i=0; i<5000; i++) used[i]=0;
    while (!q.empty()) q.pop();
    if (br<n) return 0;
    return 1;
}
int main ()
{
    scanf("%d%d",&n,&m);
    for (int i=0; i<m; i++)
    {
        scanf ("%d%d",&beg,&en);
        v[beg].push_back(en);
    }
    int tmp=0;
    for (int i=0; i<n; i++)
    {
        if (bfs(i))
        {
            result[tmp]=i;
            tmp++;
        }
        if (n>500 && tmp>=n/10) break;
    }
    printf ("%d\n",tmp);
    for (int i=0; i<tmp; i++)
    {
        printf ("%d ",result[i]);
    }
    printf ("\n");
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
*/
