#include<iostream>
using namespace std;
int dp[10001],ind[2][10001],len[2];
int main () {
    string a;
    int n,i,j,prev1,cur,min1,num;
    cin >> a ;
    n=a.size();
    a='0'+a;
    dp[0]=-1; dp[1]=0;
    for (i=2; i<=n; i++) {
        prev1=(i-1)%2; cur=i%2; min1=10000;
        len[cur]=0;
        for (j=0; j<len[prev1]; j++) {
            if (a[ind[prev1][j]-1]==a[i]) {
               ind[cur][len[cur]++]=ind[prev1][j]-1;
               num=dp[ind[prev1][j]-2]+1;
               if (min1>num) min1=num;
               }
            }
        min1=min(min1,dp[i-1]+1);
        ind[cur][len[cur]++]=i;
        if (a[i]==a[i-1]) {
           min1=min(min1,dp[i-2]+1);
           ind[cur][len[cur]++]=i-1;
           }
        dp[i]=min1;
        }
    cout << dp[n] ;
    cout << endl ;
    return 0;
}
