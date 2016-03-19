#include<iostream>
#include<cmath>
using namespace std;
typedef struct
{
    int x;
    int y;
}Point;
typedef struct
{
    Point c;
    int r;
}Circle;
int n,m,q;
Circle a[10001];
int Pow[100001];
Point t[16];
void inp()
{
    cin>>n>>m>>q;
    for (int i=0;i<n;i++) 
    {
        cin>>a[i].c.x>>a[i].c.y>>a[i].r;
    }
    for (int i=0;i<m;i++) cin>>t[i].x>>t[i].y;
    for (int i=0;i<q;i++) cin>>Pow[i];
    
}
long long solve()
{
    long long Sol=0;
    long long last=0;
    for (int i=0;i<q;i++)
    {
        if (i>0 && !(last&1)) Pow[i]=Pow[i]<<1;
        last=0;
        for (int j=0;j<m;j++)
        {
            for (int k=0;k<n;k++)
            {
                if (sqrt((t[j].x-a[k].c.x)*(t[j].x-a[k].c.x)+(t[j].y-a[k].c.y)*(t[j].y-a[k].c.y))+a[k].r<Pow[i]) last++;
            }
        }
        Sol+=last;
    }
    return Sol;
}
int main()
{
    inp();
    cout<<solve()<<endl;
    return 0;
}