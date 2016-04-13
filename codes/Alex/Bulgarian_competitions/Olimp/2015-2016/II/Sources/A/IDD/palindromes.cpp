#include <iostream>
#include <string.h>
using namespace std;
char in[10200];
bool calc[10200];
int dp[10200], n;

int f(int from, int moves){
    if (from >= n){return -1;}
    if (moves < 0){return n+10;}
    if(calc[from]){return dp[from];}
    //calc[from] = 1;
    dp[from] = n;
    for (int i = n; i>from; --i){
        bool pal = 1;
        for (int j=from; j<(from+i)/2; ++j){
            if (in[j]!=in[i-1-(j-from)]){pal=0;break;}
        }
        if (pal){
            int curr = f(i,moves-1);
            if (curr+1 < dp[from]){
                dp[from] = curr+1;
                moves = min(moves, dp[from]);
            }
            if (dp[from]==0){return dp[from];}
            if (i<n && dp[from]==1){return dp[from];}
        }
    }
    if (dp[from]<n){calc[from]=1;}
    return dp[from];
}

int main(){
    cin>>in;
    n = strlen(in);
    cout<<f(0,n-1)<<endl;
    return 0;
}
/*
alabalanica
*/
