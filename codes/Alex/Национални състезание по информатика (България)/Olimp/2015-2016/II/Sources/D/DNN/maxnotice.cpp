#include <iostream>
using namespace std;
long long m[100][100];
void zr(long long l,long long h)
{
    for(int i=0;i<h;i++)
    {
        for(int j=0;j<l;j++)
        {
            m[i][j]=0;
        }
    }
}
void one(long long x,long long y,long long a,long long b)
{
    for(int i=y;i<y+b;i++)
    {
        for(int j=x;j<x+a;j++)
        {
            m[i][j]=1;
        }
    }
}
int main()
{
    long long l,h,n,x1,y1,a,b,s=0,ms=0,ma=128,mb=128;
    cin>>l>>h;
    zr(l,h);
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>x1>>y1>>a>>b;
        one(x1,y1,a,b);
    }

    for(int i=0;i<h;i++)
    {
        for(int j=0;j<l;j++)
        {
            ma=999;
            for(int a1=i;a1<h;a1++)
            {
                if(m[a1][j]==1)break;

                for(a=0;a<l;a++)
                {
                    if(m[a1][a]==1)break;
                }
                ma=min(ma,a);
                ms=max(ms,(ma*(a1-i+1)));
            }

        }
    }

    cout<<ms<<endl;

    return 0;

}
