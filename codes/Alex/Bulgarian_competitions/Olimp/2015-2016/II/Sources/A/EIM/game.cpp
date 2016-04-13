#include <iostream>
#include <stdio.h>
#include <vector>
#include <cmath>
#include <algorithm>
using namespace std;
typedef long double Double;
typedef long long Int;

struct circle
{
    int x,y,r;
};

int n,m,q;
circle circles[10111];
pair<int,int> pts[21];

vector<Double> distances[21];

inline Double Sq(Double a)
{
    return a*a;
}

Double Dist(Double x1,Double y1,Double x2,Double y2)
{
    return sqrt( Sq(x1-x2)+Sq(y1-y2) );
}

int main()
{
    int i,j;
    Double dst;
    int s;
    bool lasteven=false;
    Double S;
    int l,r,mid,best;
    int ans=0;
    Int sumans=0;

    scanf("%d %d %d",&n,&m,&q);

    for (i=1;i<=n;i++)
    {
        scanf("%d %d %d",&circles[i].x,&circles[i].y,&circles[i].r);
    }

    for (i=1;i<=m;i++)
    {
        scanf("%d %d",&pts[i].first,&pts[i].second);

        for (j=1;j<=n;j++)
        {
            dst=Dist((Double)pts[i].first,(Double)pts[i].second,(Double)circles[j].x,(Double)circles[j].y);
            dst+=(Double)circles[j].r;

            distances[i].push_back(dst);
        }

        sort(distances[i].begin(),distances[i].end());
    }

    for (i=1;i<=q;i++)
    {
        scanf("%d",&s);
        if (lasteven)
        s*=2;

        S=(Double)s;
        ans=0;
        for (j=1;j<=m;j++)
        {
            l=0;
            r=(int)distances[j].size()-1;
            best=-1;

            while(l<=r)
            {
                mid=(l+r)/2;

                if (S>=distances[j][mid])
                {
                    best=mid;
                    l=mid+1;
                }
                else
                {
                    r=mid-1;
                }
            }

            ans+=(best+1);
        }

        sumans+=(Int)ans;

        if (ans%2==0)
        lasteven=true;
        else
        lasteven=false;
    }

    printf("%lld\n",sumans);

    return 0;
}
