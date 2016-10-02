#include<iostream>
using namespace std;

int table[1024][1024];
int dp[1024][1024];

int main(){
    int N, M, n, m;
    cin >> M >> N >> n >> m;
    for(int i = 0 ; i < M; i ++){
        for(int  j = 0; j < N; j ++){
            cin >> table[i][j];
        }
    }

    dp[0][0] = table[0][0];

    for(int i = 1 ; i < M; i ++){
        dp[i][0] = dp[i-1][0] + table[i][0];
    }
    for(int i = 1 ; i < N; i ++){
        dp[0][i] = dp[0][i-1] + table[0][i];
    }
    for(int i = 1; i < M; i ++){
        for(int j = 1; j < N; j ++){
            dp[i][j] = table[i][j] + dp[i-1][j] + dp[i][j - 1] - dp[i-1][j-1];
        }
    }

    int MAXX = -1;
    for(int i = m - 1; i < M; i ++){
        for(int j = n - 1; j < N; j ++){
            int tmp = dp[i][j];
            if(i - m >  -1){
                tmp -= dp[i - m][j];
            }
            if(j -  n > -1){
                tmp -= dp[i][j - n];
            }
            if(i - m > -1 && j - n > -1)tmp += dp[i-m][j-n];
            MAXX = max(MAXX, tmp);
        }
    }
    cout << MAXX << '\n';
    return 0;
}
