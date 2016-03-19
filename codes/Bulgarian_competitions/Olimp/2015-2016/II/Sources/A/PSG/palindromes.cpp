#include<iostream>
#include<cstdio>
#include<cstring>
using namespace std;

const int MAXN = 10257;
char s[MAXN];
int N;
int dp[MAXN][MAXN];

bool Check (int left, int right){
    int n = (right-left)+1;

    int it1 = left+n/2, it2 = left+n/2;
    if (n%2 == 0) it1--;

    for (; it1 >=left && it2 <= right; it1--, it2++)
        if (s[it1] != s[it2]) return 0;

    return 1;
}

int solve (int left, int right){
    if (dp[left][right] != -1) return dp[left][right];

    if (left == right) return 0;
    if (Check (left, right)) return 0;

    int min = -1;
    for (int i=left; i <= right-1; i++){
        int curr = solve (left, i) + solve (i+1, right) + 1;
        if (curr < min || min == -1) min = curr;
    }

    dp[left][right] = min;
    return min;
}

int main (){
    memset (dp, -1, sizeof(dp));
    scanf ("%s",s);

    N = strlen (s);

    printf ("%d\n",solve (0, N-1));
    return 0;
}
