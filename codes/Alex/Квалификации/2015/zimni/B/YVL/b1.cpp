#include<iostream>
using namespace std;
int pole[1010][1010];
int dp[1010][1010];
int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    int gred, gstulb, mred, mstulb;
    cin>>gred>>gstulb>>mred>>mstulb;
    for(int i=0;i<gred;i++){
        for(int j=0;j<gstulb;j++){
            cin>>pole[i][j];
        }
    }
    dp[0][0]=pole[0][0];
    for(int i=1;i<gstulb;i++){
        dp[0][i]=dp[0][i-1]+pole[0][i];
    }
    for(int i=1;i<gred;i++){
        dp[i][0]=dp[i-1][0]+pole[i][0];
    }
    for(int i=1;i<gred;i++){
        for(int j=1;j<gstulb;j++){
            dp[i][j]=dp[i][j-1]+dp[i-1][j]-dp[i-1][j-1]+pole[i][j];
        }
    }
    int res=dp[mred-1][mstulb-1];
    for(int i=mred;i<gred;i++){
        if(res<dp[i][mstulb-1]-dp[i-mred][mstulb-1]){
            res=dp[i][mstulb-1]-dp[i-mred][mstulb-1];
        }
    }
    for(int i=mstulb;i<gstulb;i++){
        if(res<dp[mred-1][i]-dp[mred-1][i-mstulb]){
            res=dp[mred-1][i]-dp[mred-1][i-mstulb];
        }
    }
    for(int i=mred;i<gred;i++){
        for(int j=mstulb;j<gstulb;j++){
            if(dp[i][j]-dp[i][j-mstulb]-dp[i-mred][j]+dp[i-mred][j-mstulb]>res){
                res=dp[i][j]-dp[i][j-mstulb]-dp[i-mred][j]+dp[i-mred][j-mstulb];
            }
        }
    }
    cout<<res<<"\n";
    return 0;
}
/**
5 3 1 1
1 3 2
4 5 1
3 2 4
10 14 14
25 13 24
*/
