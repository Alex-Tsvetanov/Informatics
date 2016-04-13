#include <iostream>
#include <cstdio>

using namespace std;

const int MAXN= 10010;
const int inf= 9999999;

int n;
int dp[MAXN][MAXN];
int ans[MAXN];

int answer(string S) {
    int h, i, j;

    for(i=0; i<n; i++) {
        dp[i][i]= 1;
    }

    for(h=2; h<=n; h++) {
        for(i=0; i<n-h+1; i++) {
            j= i+h-1;

            if(h == 2) {
                if(S[i] == S[j]) dp[i][j]= 1;
                else dp[i][j]= 0;
            }

            else {
                if(S[i] == S[j] && dp[i+1][j-1]) dp[i][j]= 1;
                else dp[i][j]= 0;
            }
        }
    }

    for(i=0; i<n; i++) {
        if(dp[0][i]) {
            ans[i]= 0;
        }

        else {
            ans[i]= inf;

            for(j=0; j<i; j++) {

                if(dp[j+1][i] == 1 && (ans[j] + 1) < ans[i]) {
                    ans[i]= ans[j] + 1;
                }
            }
        }
    }

    return ans[n-1];
}

void read() {
    string s;
    cin>> s;
    n= s.size();

    printf("%d\n", answer(s));
}

int main() {

    read();

    return 0;
}
