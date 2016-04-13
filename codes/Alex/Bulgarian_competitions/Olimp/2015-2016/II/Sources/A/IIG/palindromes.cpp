#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
const int MAX_LEN=10007;
bool dp[MAX_LEN][MAX_LEN];
int ans[MAX_LEN];
string s;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    int sz=s.size();
    for(int i=0;i<sz;++i)
    {
        dp[i][i]=1;
        if(s[i]==s[i+1])dp[i][i+1]=1;
        else dp[i][i+1]=0;
    }
    for(int i=2;i<sz;++i)
    {
        for(int j=0;j<sz;++j)
        {
            if(j+i>sz-1)break;
            if(dp[j+1][j+i-1]&&s[j]==s[j+i])dp[j][j+i]=1;
        }
    }
    if(dp[0][sz-1])
    {
        cout<<0<<"\n";
        return 0;
    }
    if(s[0]!=s[1])ans[1]=1;
    for(int i=2;i<sz;++i)
    {
        ans[i]=ans[i-1]+1;
        if(dp[0][i])
        {
            ans[i]=0;
            continue;
        }
        for(int j=1;j<=i;++j)
        {
            if(dp[j][i])
            {
                ans[i]=min(ans[i],ans[j-1]+1);
            }
        }
    }
    cout<<ans[sz-1]<<"\n";
    return 0;
}
