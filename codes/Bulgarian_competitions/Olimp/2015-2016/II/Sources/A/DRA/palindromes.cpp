#include<iostream>
#include<cstring>
using namespace std;
char a[10100];
int dp[10100],n;
int s[10100],m,k;
int main()
{
    int i,j;dp[0]=1;
    cin>>a;
    n=strlen(a);
    for(i=0;i<n;++i)
    {
        //cout<<i<<":\n";for(j=0;j<m;++j){cout<<s[j]<<" ";}cout<<endl;
        if(i>0){dp[i]=dp[i-1]+1;}
        k=0;
        for(j=0;j<m;++j)
        {
            if(s[j]-1>=0&&a[s[j]-1]==a[i])
            {
                if(s[j]-1==0){dp[i]=1;}
                else if(dp[s[j]-2]+1<dp[i]){dp[i]=dp[s[j]-2]+1;}
                s[k]=s[j]-1;
                ++k;
            }
        }
        if(i>0&&a[i]==a[i-1])
        {
            if(i==1){dp[i]=1;}
            else if(dp[i-2]+1<dp[i]){dp[i]=dp[i-2]+1;}
            s[k]=i-1;
            ++k;
        }
        s[k]=i;
        ++k;
        m=k;
        //cout<<dp[i]<<endl;
    }
    cout<<(dp[n-1]-1)<<endl;
    return 0;
}
