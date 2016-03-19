#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

pair <pair <int,int>, int> a[10005];
double x,y,x1,y11,r;
int m,n,q;
double count1[11][10005],temp;

int bins(int x)
{
    int l,r,mid;
    int ans=0;
    for(int i=1;i<=m;i++)
    {
        l=0;r=n+1;
        for(;;)
        {
            mid=(l+r)/2;
            if(x>=count1[i][mid])l=mid;
            else r=mid;
            if(l+1==r)break;
            if(l>=r)break;
        }
        ans+=l;
    }
    return ans;
}

int main()
{
    cin>>n>>m;cin>>q;
    for(int i=1;i<=n;i++)
        cin>>a[i].first.first>>a[i].first.second>>a[i].second;
    for(int i=1;i<=m;i++)
    {
        cin>>x>>y;
        for(int j=1;j<=n;j++)
        {
            x1=a[j].first.first;
            y11=a[j].first.second;
            r=a[j].second;
            temp=sqrt((x1-x)*(x1-x)+(y11-y)*(y11-y));
            count1[i][j]=temp+r;
        }
        sort(count1[i]+1,count1[i]+n+1);
        count1[i][n+1]=count1[i][n]+20;

    }

    int    ans=0;
    int r1;
    for(int i=1;i<=q;i++)
    {
        cin>>r1;
        if(i>1 && ans%2==0)r1=r1*2;
        ans+=bins(r1);

    }
    cout<<ans<<endl;
    return 0;
}
/*

4 1 3
2 2 1
3 5 2
6 2 3
8 8 1
4 4
4 3 3

*/

