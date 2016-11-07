#include <iostream>
#include <cstdio>
#include <vector>
#include <string.h>
#include <algorithm>
#include <climits>
using namespace std;
typedef long long lld;

int N;
char seq[10002], rev[10002];
int hsh_1N[10002], hsh_N1[10002];

const lld MOD = 1000000007, base = 29;
int pwto[10002];

int Gethsh(int from, int to)
{
    if (from <= to)
    {
        int tosub = ((lld)hsh_1N[from-1]*(lld)pwto[max(0, to-1-(from-2))])%MOD;

        int all = hsh_1N[to] - tosub;
        if (all < 0) all += MOD;
        return all;
    }
    else
    {
        from = N-from+1;
        to = N-to+1;

        int tosub = ((lld)hsh_N1[from-1]*(lld)pwto[max(0, to-1-(from-2))])%MOD;
        int all = hsh_N1[to] - tosub;
        if (all < 0) all += MOD;
        return all;
    }
}
bool IsPalindrome(int from, int to)
{
    if (from == to) return true;

    int len = (to-from+1);
    int beg1, tar1, beg2, tar2;

    beg1=from; tar2=to;
    tar1=(from+to)>>1;
    beg2=tar1+1;

    if (len&1) tar1--;
    int hsh1=Gethsh(beg1, tar1), hsh2=Gethsh(tar2, beg2);

    return  hsh1==hsh2 ;
}
int GI(char c)
{
    return (c-'a'+1);
}

int memo[10002];
int firstafter[27][10002];

int Iterative()
{
    for (int ind=N; ind>=1; ind--)
    {
        int ret = INT_MAX;

        for (int i=ind; i!=-1; i=firstafter[GI(seq[i])][i])
        {
            if (!IsPalindrome(ind, i)) continue;
            ret = min(ret, 1+memo[i+1]);
        }
        memo[ind] = ret;
    }

    return memo[1];
}

int main ()
{
    //freopen("input.txt", "r", stdin);

    do
    {
        scanf("%c", &seq[++N]);
    }
    while (seq[N]>='a' && seq[N]<='z');
    N--;

    for (int i=1; i<=N; i++)
    {
        rev[i] = seq[N-i+1];
    }

    pwto[0] = 1;
    for (int i=1; i<=N; i++)
    {
        pwto[i] = ((lld)pwto[i-1] * (lld)base)%MOD;
    }

    int hsh=0;
    for (int i=1; i<=N; i++)
    {
        hsh = ((lld)hsh*(lld)base + (lld)GI(seq[i]))%MOD;
        hsh_1N[i] = hsh;
    }

    hsh = 0;
    for (int i=1; i<=N; i++)
    {
        hsh = ((lld)hsh*(lld)base + (lld)GI(rev[i]))%MOD;
        hsh_N1[i] = hsh;
    }
    hsh_1N[0] = hsh_N1[0] = 0;

    int lastocc[27];
    memset(lastocc, -1, sizeof(lastocc));
    for (int i=N; i>=1; i--)
    {
        for (int j=1; j<=26; j++)
        {
            firstafter[j][i] = lastocc[j];
        }
        lastocc[GI(seq[i])] = i;
    }

    int ans = Iterative()-1;
    printf("%d\n", ans);
}

