#include<iostream>
#define maxn 100
using namespace std;
int x, y, a1, b;
bool a[maxn][maxn];
bool flag=0;
int l, h, n, ms;
int t=0, t1=0, ts=0;
int main()
{
    cin>>l>>h;
    cin>>n;
    for(int i=0; i<h; i++)
        for(int j=0; j<l; j++)
            a[i][j]=false;
    for(int i=1; i<=n; i++)
    {
        cin>>x>>y>>a1>>b;
        for(int i=y; i<y+b; i++)
            for(int j=x; j<x+a1; j++)
                a[i][j]=true;
    }
    for(int i=0; i<h; i++)
        for(int j=0; j<l; j++)
        {
            if(a[i][j]!=true)
            {
                t=i;
                while(a[t][j]==false&&t<h)
                    t++;
                t-=i;
                t1=j;
                while(a[i][t1]==false&&t1<l)
                    t1++;
                t1-=j;
                for(int f=i; f<i+t; f++)
                {
                    for(int w=j; w<j+t1; w++)
                        if(a[f][w]==true)
                        {
                            flag=true;
                            break;
                        }
                    if(flag==true)break;
                }
                if(flag==false)
                {
                    ts=t1*t;
                    ms=max(ms,ts);
                }
            }
            t1=0;
            t=0;
            ts=0;
            flag=false;
        }
    cout<<ms<<endl;
    return 0 ;
}
