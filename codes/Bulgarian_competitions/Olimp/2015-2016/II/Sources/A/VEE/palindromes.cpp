#include<iostream>
#include<string>
using namespace std;

string s;
bool dp[5][10004];
int dpop[10004];
int ans,temp,n,p;


int main()
{
    cin>>s;
    n=s.size();
    dpop[0]=-1;
    dpop[1]=0;

    p=1;
    dp[0][0]=dp[0][1]=1;
    for(int i=1;i<n;i++)
    {
        dpop[i+1]=dpop[i]+1;
        dp[p][i]=dp[p][i+1]=1;
        for(int j=0;j<i;j++)
            if(dp[p^1][j+1]==1 && s[i]==s[j])
            {
                dp[p][j]=1;
                dpop[i+1]=min(dpop[i+1],dpop[j]+1);
            }
            else dp[p][j]=0;
        p=p^1;
    }



    cout<<dpop[n]<<endl;
    return 0;
}
