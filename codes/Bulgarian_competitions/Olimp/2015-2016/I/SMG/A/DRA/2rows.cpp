#include<cstdio>
#include<map>
using namespace std;
map<int,int> p[5];
int n;
int main()
{
    int i,j,x,t,a;
    for(i=0;i<5;++i)
    {
        a=1;t=0;
        scanf("%d",&n);
        for(j=1;j<=n;++j){scanf("%d",&x);p[i][x]=j;}
        scanf("%d",&n);
        for(j=1;j<=n;++j){scanf("%d",&x);if(p[i][x]>0){if(p[i][x]>t){t=p[i][x];}else{a=0;}}}
        printf("%d",a);
    }
    printf("\n");
    return 0;
}
