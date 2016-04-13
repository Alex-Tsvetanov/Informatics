#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstring>
using namespace std;
struct coords
{
    int x, y, r;
}cir[10010];
double hit[20][10010];
long long curans, ans;
int main()
{
    int n, m, q, i, j, k, x, y, s;
    bool l=0;
    cin>>n>>m>>q;
    for(i=1;i<=n;i++)
    {
        cin>>cir[i].x>>cir[i].y>>cir[i].r;
    }
    for(i=1;i<=m;i++)
    {
        cin>>x>>y;
        for(j=1;j<=n;j++)
        {
            hit[i][j]=sqrt(abs(cir[j].x-x)*abs(cir[j].x-x)+abs(cir[j].y-y)*abs(cir[j].y-y))+cir[j].r;
        }
        sort(hit[i]+1, hit[i]+n+1);
    }
    for(i=1;i<=q;i++)
    {
        cin>>s;
        curans=0;
        if(l)
        {
            s*=2;
            l=0;
        }
        for(j=1;j<=m;j++)
        {
            for(k=1;k<=n;k++)
            {
                if(s>=hit[j][k])
                {
                    curans++;
                }
                else break;
            }
        }
        if(curans%2==0)
        {
            l=1;
        }
        ans+=curans;
    }
    cout<<ans<<endl;
    return 0;
}
/**
4 2 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 5
4 3 3


4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
**/
