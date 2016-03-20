#include <iostream>
using namespace std;

const int MAXN=32;
const int MAXS=32;

long long dp[MAXN][MAXS];
int p, n, s;

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL); cout.tie(NULL);

    cin>>p>>n>>s;
    dp[0][0]=1;
    for (int i=1; i<=n; i++)
    {
        for (int k=0; k<p; k++)
        {
            for (int j=k; j<s; j++)
            {
                dp[i][j]+=dp[i-1][j-k];
            }
        }
    }
    long long ans=0;
    for (int i=0; i<s; i++)
    {
        ans+=dp[n][i];
    }
    cout<<ans<<endl;
    return 0;
}
