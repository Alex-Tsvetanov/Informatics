#include<cstdio>
#include<cstring>
#include<iostream>
using namespace std;
const int MAXN=10100;
int n;
int dp[MAXN];
unsigned long long h1[2][MAXN],h2[2][MAXN],p[2],pw[2][MAXN];
char s[MAXN];
void read()
{
    scanf("%s",s);
    n=strlen(s);
}
void initHash()
{
    int i;
    p[0]=37;
    p[1]=39;
    pw[0][0]=1;
    pw[1][0]=1;
    for(i=1;i<=n;i++)
    {
        pw[0][i]=pw[0][i-1]*p[0];
        pw[1][i]=pw[1][i-1]*p[1];
    }
    for(i=1;i<=n;i++)
    {
        h1[0][i]=h1[0][i-1]*p[0]+(s[i-1]-'a'+1);
        h1[1][i]=h1[1][i-1]*p[1]+(s[i-1]-'a'+1);
    }
    for(i=n;i>=1;i--)
    {
        h2[0][i]=h2[0][i+1]*p[0]+(s[i-1]-'a'+1);
        h2[1][i]=h2[1][i+1]*p[1]+(s[i-1]-'a'+1);
    }
}
inline unsigned long long check01(int x,int y)
{
    return h1[0][y]-h1[0][x-1]*pw[0][y-x+1];
}
inline unsigned long long check02(int x,int y)
{
    return h2[0][x]-h2[0][y+1]*pw[0][y-x+1];
}
inline unsigned long long check11(int x,int y)
{
    return h1[1][y]-h1[1][x-1]*pw[1][y-x+1];
}
inline unsigned long long check12(int x,int y)
{
    return h2[1][x]-h2[1][y+1]*pw[1][y-x+1];
}
void solve()
{
    int i,j;
    int best;
    for(i=1;i<=n;i++)
    {
        if(check01(1,i)==check02(1,i)&&check11(1,i)==check12(1,i))
        {
            dp[i]=0;
            continue;
        }
        best=i-1;
        for(j=1;j<i;j++)
            if(check01(j+1,i)==check02(j+1,i)&&check11(j+1,i)==check12(j+1,i))
                if(best>dp[j]+1)
                    best=dp[j]+1;
        dp[i]=best;
    }
    printf("%d\n",dp[n]);
}
int main()
{
    read();
    initHash();
    solve();
}
