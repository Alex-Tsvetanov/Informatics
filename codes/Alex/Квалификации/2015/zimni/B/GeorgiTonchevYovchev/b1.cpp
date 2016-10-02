#include<iostream>
using namespace std;

short arr[1016][1016];
int dp[1016][1016];
int dp2[1016][1016];
int main()
{
    int N,M,n,m,MAX=0;
    cin>>N>>M>>n>>m;
    for(int i=0;i<N;i++)for(int j=0;j<M;j++){cin>>arr[i][j];dp[i][j]=arr[i][j];}
    dp2[0][0]=dp[0][0];
    for(int i=0;i<N;i++)for(int j=1;j<M;j++)
    {
        dp[i][j]=dp[i][j-1]+arr[i][j];
        if(j-m>=0)dp[i][j]-=arr[i][j-m];
        dp2[i][j]=dp[i][j];
    }
    for(int j=0;j<M;j++)for(int i=1;i<N;i++)
    {
        dp2[i][j]=dp2[i-1][j]+dp[i][j];
        if(i-n>=0)dp2[i][j]-=dp[i-n][j];
        if(dp2[i][j]>MAX)MAX=dp2[i][j];
    }
    cout<<MAX<<"\n";

    return 0;
}
