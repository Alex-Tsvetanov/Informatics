#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;
struct Point{
    int x,y;
};
Point pointArr[2000],angles[2000];
int surfaceArea(Point a,Point b,Point c)
{
    return (a.x-b.x)*(a.y+b.y)+(b.x-c.x)*(b.y+c.y)+(c.x-a.x)*(c.y+a.y);
}
bool angleSort(Point a,Point b)
{
    double sb=(2*surfaceArea(pointArr[0],pointArr[b.x],pointArr[b.y]))/(hypot(pointArr[b.x].x,pointArr[b.x].y)*hypot(pointArr[b.y].x,pointArr[b.y].y));
    sb=sqrt(1-sb*sb);
    double sa=(2*surfaceArea(pointArr[0],pointArr[a.x],pointArr[a.y]))/(hypot(pointArr[a.x].x,pointArr[a.x].y)*hypot(pointArr[a.y].x,pointArr[a.y].y));
    sa=sqrt(1-sa*sa);
    if(sb<0)
    {
        if(sa<0) return sa>sb;
        else return false;
    }
    if(sa<0) return false;
    return sa<sb;
}
int main()
{
    unsigned int n,a=0,i,j,k;
    //Point pointArr[2000],angles[2000];
    ios::sync_with_stdio(false);
    cin>>n;
    for(i=0;i<=n;++i)
    {
        cin>>pointArr[i].x>>pointArr[i].y;
    }
    for(i=1;i<n;++i)
    {
        long long si,sj;
        for(j=i+1;j<=n;++j)
        {
            for(k=1;k<=n;++k)
            {
                if(k!=i && k!=j)
                {
                    si=surfaceArea(pointArr[0],pointArr[i],pointArr[k]);
                    sj=surfaceArea(pointArr[0],pointArr[j],pointArr[k]);
                    if(((si>0&&sj>0)||(si<0&&sj<0))) {
                        angles[a].x=i;
                        angles[a].y=j;
                        a++;
                        break;
                    }
                }
            }
        }
    }
    sort(angles,angles+a,angleSort);
    for(i=0;i<a;++i)
    {
        cout<<angles[i].x<<" "<<angles[i].y<<endl;
    }
    return 0;
}

