#include<iostream>
using namespace std;
long long int dp[256][256];
int main()
{
    long long int p,n,s,i,sum=0,d=3,j,l;
    cin>>p>>n>>s;
    dp[0][0]=1;
    for(i=1;i<=n;i++)
    {
        for(j=0;j<s;j++)
        {
            for(l=0;l<p&&l<=j;l++)
            {
                dp[i][j]+=dp[i-1][j-l];
            }
        }
    }
    for(i=0;i<s;i++)sum+=dp[n][i];
    cout<<sum<<endl;
    return 0;
}
