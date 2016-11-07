#include <iostream>
#include <cstdio>
#include <vector>
#include <algorithm>
#include <cmath>
using namespace std;
int n,m,q,ss,pres,br,mina;
int pt[11][2];
int ans[10101];

struct L
{
    int x,y,r;
};

vector<L>cir;

bool f(L p, L q)
{
    if (p.r<q.r) return 1;
    if (p.r==q.r && p.x<q.x) return 1;
    if (p.x==q.x && p.r==q.r && p.y<q.y) return 1;
    return 0;
}


void blabla()
{
    double a,b,c,c1;
    for (int i=1; i<10001; i++)
    {
        br=0;
        for (int o=0; o<m; o++)
        {
            for (int j=0; j<n; j++)
            {
                if (i<=cir[j].r) break;
                if (pt[o][0]-i >= cir[j].x-cir[j].r) continue;
                if (pt[o][0]+i <= cir[j].x+cir[j].r) continue;
                if (pt[o][1]-i >= cir[j].y-cir[j].r) continue;
                if (pt[o][1]+i <= cir[j].y+cir[j].r) continue;
                a=fabs(pt[o][0]-cir[j].x);
                b=fabs(pt[o][1]-cir[j].y);
                c=(a*a+b*b);
                c=sqrt(c);
                c1=c+cir[j].r;
                if (i <= c1) continue;
                br++;
            }

        }
        ans[i]=br;
    }
}

void read()
{
    scanf("%d %d %d",&n,&m,&q);
    int bla,bla1,bla2;
    L l;
    for (int i=0; i<n; i++)
    {
        scanf("%d %d %d",&bla,&bla1,&bla2);
        l.x=bla;
        l.y=bla1;
        l.r=bla2;
        cir.push_back(l);
    }
    sort(cir.begin(),cir.end(),f);
    for (int i=0; i<m; i++)
        scanf("%d %d",&pt[i][0],&pt[i][1]);

    blabla();

    for (int o=0; o<q; o++)
    {
        scanf("%d",&ss);
        if (o!=0 && mina%2==0) ss*=2;
        mina=ans[ss];
        pres+=mina;
    }
}

int main ()
{
    read();
    printf("%d\n",pres);
    return 0;
}

