#include <iostream>
#include <math.h>
using namespace std;
double dist(double x,double y,double x1,double y1)
{
    return sqrt((x-x1)*(x-x1)+(y-y1)*(y-y1));
}
int n,q,m,x[10000],y[10000],y2[10000],x2[10000],r[10000],s[10000];
int main()
{
    cin>>n>>m>>q;
    for(int i=0; i<n; i++)
        cin>>x[i]>>y[i]>>r[i];
    for(int i=0; i<m; i++)
        cin>>x2[i]>>y2[i];
    for(int i=0; i<q; i++)
        cin>>s[i];
    int ans=0;
    int power=s[0];
    for(int i=0; i<q; i++)
    {
        int sum=0;
        for(int j=0; j<m; j++)
        {
            for(int k=0; k<n; k++)
            {
                if(power-(dist(x2[j],y2[j],x[k],y[k])+r[k])>0.01)
                {
                    sum++;
                }
            }
        }
        cout<<sum<<endl;
        if(sum%2==0)
            power=s[i+1]*2;
        else
            power=s[i+1];
        ans+=sum;
    }
    cout<<ans<<endl;
}
/*
4 3 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
3 3
2 2
4 3 3

*/
