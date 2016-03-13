#include<iostream>
using namespace std;
int dp[200005], len[205];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int n, m;
    cin>>n>>m;
    for(int i=0;i<m;i++){
        cin>>len[i];
    }
    int bestN=0;
    cin>>dp[0];
    for(int i=1;i<=n;i++){
        int crnt;
        cin>>crnt;
        dp[i]=-1;
        for(int j=0;j<m;j++){
            if(i-len[j]>=0){
                if((dp[i-len[j]]>(-1))&&(dp[i-len[j]]+crnt>dp[i])){;
                    dp[i]=dp[i-len[j]]+crnt;
                }
            }
        }
        if(dp[bestN]<dp[i]) bestN=i;
    }
    cout<<dp[bestN]<<" "<<bestN<<"\n";
    return 0;
}
