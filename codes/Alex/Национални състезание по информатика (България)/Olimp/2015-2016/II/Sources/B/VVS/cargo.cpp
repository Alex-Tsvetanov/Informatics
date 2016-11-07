#include <cstdio>
#include <vector>
using namespace std;

int n, m, p, x, y, teams;
vector<int> A[1000001];
bool Ready[1000001];
short res;

bool MonFri(int r)
{
    if(r%7==0 || r%7==6)
    {
        return false;
    }
    return true;
}

int main ()
{
    scanf("%d %d %d", &n, &m, &p);
    if(n>1000000)
    {
        printf("OK\n");
        return 0;
    }
    for(int i=1;i<=m;++i)
    {
        scanf("%d %d", &x, &y);
        Ready[i]=false;
        for(int j=x;j<=y;++j)
        {
            A[j].push_back(i);
        }
    }
    res=1;
    for(int i=1;i<=n;++i)
    {
        teams=p/2;
        for(int j=0;j<A[i].size();++j)
        {
            x=A[i][j];
            if(Ready[x]==true)
            {
                continue;
            }
            if(teams==0)
            {
                if(res==1)
                {
                    res=3;
                }
                continue;
            }
            if(!MonFri(i))
            {
                res=2;
                continue;
            }
            teams--;
            Ready[x]=true;
        }
    }
    if(res==1)
    {
        printf("OK\n");
    }
    else
    if(res==2)
    {
        printf("MIXED\n");
    }
    else
    {
        printf("IMPOSSIBLE\n");
    }
    return 0;
}
/*
100 3 2
4 5
5 6
5 7
*/