#include<iostream>
#include<cstdio>
#include<algorithm>
#include<cmath>
using namespace std;
const int MAX_R=24150;
const int MAX_N=10008;
int n,m,q;
struct circle
{
    int x;
    int y;
    int r;
};
circle ci[MAX_N];
int br[MAX_R];
int main()
{
    int d,last=-1,udar,ans=0;
    int a,b;
    scanf("%d%d%d",&n,&m,&q);
    for(int i=1;i<=n;++i)scanf("%d%d%d",&ci[i].x,&ci[i].y,&ci[i].r);
    for(int i=1;i<=m;++i)
    {
        scanf("%d%d",&a,&b);
        for(int j=1;j<=n;++j)
        {
            double ok=sqrt((a-ci[j].x)*(a-ci[j].x)+(b-ci[j].y)*(b-ci[j].y))+ci[j].r;
            int f=ok;
            if(f<ok)++f;
            ++br[f];
        }
    }
    for(int i=1;;++i)
    {
        d=i;
        br[i]+=br[i-1];
        if(br[i]==n*m)break;
    }
    for(int i=1;i<=q;++i)
    {
        scanf("%d",&udar);
        if(last%2==0)udar*=2;
        if(udar>d)
        {
            ans+=n*m;
            last=n*m;
        }
        else
        {
            ans+=br[udar];
            last=br[udar];
        }
    }
    printf("%d\n",ans);
    return 0;
}
/**
4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3
**/
