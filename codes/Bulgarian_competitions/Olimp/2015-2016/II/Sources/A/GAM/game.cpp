#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

#define MAXN 10000
#define MAXM 10

int n,q,m;
unsigned long long ans;

struct circle
{
    int x;
    int y;
    int r;
};

circle c[MAXN];
int distances[MAXN*MAXM];
int counter;

int dist(circle a, int x, int y)
{
    return ceil(sqrt((a.x-x)*(a.x-x)+(a.y-y)*(a.y-y)))+a.r;
}

int bs(int x)
{
    int l,r,m;
    l=0;r=counter-1;

    while(r-l>0)
    {
        m=(l+r)/2;
        if(distances[m]>x) r=m;
        else l=m+1;
    }
    //cout<<"Bs finished, searched for "<<x <<" stopped at index "<<l<<" where a[i]="<<distances[l]<<" and a[i+1]="<<distances[l+1]<<endl;
    if(distances[l]>x) return l;
    //cout<<"gonna return max elements"<<endl;
    return l+1;

}

int main()
{
    int x, y, i;

    scanf("%d %d %d",&n, &m, &q);

    for(i=0;i<n;i++)
    {
        scanf("%d %d %d", &c[i].x, &c[i].y, &c[i].r);
    }
    for(i=0;i<m;i++)
    {

        scanf("%d %d", &x, &y);
        for(int j=0;j<n;j++)
        {
            distances[counter++]=dist(c[j],x,y);
        }
    }

    sort(distances,distances+counter);
    //for(i=0;i<counter;i++) cout<<distances[i]<<" ";
    //cout<<endl;

    bool doubled=0;

    while(q--)
    {
        cin>>x;
        if(doubled) { x*=2; doubled=0;}

        y=bs(x);

        if(y%2==0) doubled=1;
        ans+=y;
    }
    cout<<ans<<endl;
    return 0;
}
