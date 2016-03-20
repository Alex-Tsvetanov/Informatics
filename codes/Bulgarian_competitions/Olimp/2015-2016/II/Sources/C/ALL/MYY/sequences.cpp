#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;
long long int p,n,s,ans,br=0;
void backtracking(int i)
{
    if (i==n)
    {
        ans2++;
        kk+=sum;
      //  cout<<kk<<" "<<ans<<endl;
        return ;
    }
    int j;
    for (j=0;j<p;j++)
    {
        m[i]=j;
        sum+=j;
        if (sum<s)backtracking(i+1);
        sum-=j;
        m[i]=-1;
    }
}
long long int dp[256][256];
int main()
{
    scanf("%d%d%d",&p,&n,&s);
    int i,j,k;
    dp[0][0]=1;
    for (i=1;i<=n;i++)
    {
        for (j=0;j<s;j++)
        {
            for (k=0;k<p&&k<=j;k++)
            {
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    for (j=0;j<s;j++)ans+=dp[n][j];
    printf("%d",ans);printf("\n");
    return 0;
}
