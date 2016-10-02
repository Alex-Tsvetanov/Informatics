#include<iostream>
using namespace std;
int skokove[256];
int koshnici[200004];
int       dp[200004];
long long n=0,m=0,curr=0,maxx=0, istMAX=0, ind=0;
int main(){
cin.tie(NULL);
ios::sync_with_stdio(false);
cin>>n>>m;
for(int i=0;i<m;i++)
{
    cin>>skokove[i];
}
for(int i=0;i<=n;i++)
{
    cin>>koshnici[i];
}
dp[0]=koshnici[0];
for(int i=1;i<=n;i++)
{
    maxx=0;
    bool da=0;
    for(int j=0;j<m;j++)
    {
        curr=0;
        if(i-skokove[j]>=0 && dp[i-skokove[j]]>-1)
        {
            curr=koshnici[i]+dp[i-skokove[j]];
            da=1;
        }
        if(curr>maxx)
            maxx=curr;
    }
   /* for(int j=0;j<=n;j++)
        cout<<dp[j]<<" ";
    cout<<endl;*/
    if(da){
    dp[i]=maxx;
    if(dp[i]>istMAX)
    {
        istMAX=dp[i];
        ind=i;
    }
    }
    else
        dp[i]=-1;
}
cout<<istMAX<<" "<<ind<<endl;
return 0;
}
