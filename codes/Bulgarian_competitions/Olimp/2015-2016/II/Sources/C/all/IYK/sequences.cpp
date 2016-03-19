#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

const int maxN = 25, maxS = 35;

bool used_state[maxN][maxS];
long long p, n, s, dp[maxN][maxS];

long long solve(long long ind, long long current_sum)
{
    if(ind == n && current_sum < s) return 1;
    else if(ind == n) return 0;
    else if(current_sum >= s) return 0;
    else if(used_state[ind][current_sum]) return dp[ind][current_sum];

    long long current_ans = 0;
    for(long long i = 0; i < p; i++)
    {
        current_ans += solve(ind + 1, current_sum + i);
    }

    dp[ind][current_sum] = current_ans;
    used_state[ind][current_sum] = true;
    return current_ans;
}

int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);

    cin>>p>>n>>s;

    cout<<solve(0, 0)<<endl;
    return 0;
}

