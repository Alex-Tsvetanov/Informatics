#include<iostream>
#include<queue>
using namespace std;
queue <long long > q;
long long n, a, b, x, y, m[2000][2000],i, w;
void BFS (long long x)
{
    for(;!q.empty();)
    {
        for(i=1; i<=n; i++)
        {
            if(m[x][i]==1 || m[x][i]==-1)
            {
                q.push(i);
                BFS(i);
                if(m[i][a]==-1) w--;
                return;

            }
        }
    }
}
int main()
{
    cin>>n>>a>>b;
    for(;cin>>x>>y;)
    {
        m[x][y]=1;
        m[y][x]=-1;
    }
    q.push(a);
    cout<<"X"<<endl;
    return 0;
}
