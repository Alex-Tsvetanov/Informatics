#include<iostream>
#include<cstdio>
#include<string>
#include<cmath>
#include<algorithm>
using namespace std;
string s;int n;
int minans=10001;
bool dp[10001][10001];
void doet(int l,int ans){
    for(int i=n-1;i>=l;i--){
        if(dp[l][i]){
            if(i==n-1){
                minans=min(minans,ans);
                return;
            }
            else doet(i+1,ans+1);
        }
    }
}
int main(){
    int i,j;
    cin>>s;n=s.size();
    for(i=0;i<n;i++){
        for(j=0;j<=i;j++){
            dp[i][j]=1;
        }
    }
    for(i=n;i>=0;i--){
        for(j=i;j<n;j++){
            if(s[i]==s[j]&&dp[i+1][j-1])dp[i][j]=1;
        }
    }
    doet(0,0);
    printf("%d\n",minans);
    return 0;
}
/**
abba
**/
