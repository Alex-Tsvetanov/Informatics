#include <iostream>
#include <cstdio>
#include <cstring>
#define MINI 99999999
using namespace std;
string s;
int n,ans=101010,tans;
int memo[10101][10101];

bool pal(int x, int y)
{
    while (1)
    {
        if (x==y)  return 1;
        if (x==y-1)
        {
            if (s[x]==s[y]) return 1;
            else return 0;
        }
        if (s[x]!=s[y]) return 0;
        x++;
        y--;
    }
    return 1;
}

int sol(int l, int r)
{

    if (pal(l,r))
    {
        //cout<<s.substr(l,r-l+1)<<endl;
        return 1;
    }
    for (int i=l; i<r; i++)
    {
        if (memo[l][i]==MINI) memo[l][i]=sol(l,i);
        if (memo[i+1][r]==MINI) memo[i+1][r]=sol(i+1,r);
        tans=memo[l][i]+memo[i+1][r];

        if (memo[l][r]>tans) memo[l][r]=tans;

    }
    /*if (l==1 && r==6)
    {
            for (int i=0; i<n; i++)
                for (int j=0; j<n; j++)
                    cout<<i<<" "<<j<<" "<<memo[i][j]<<endl;
    }*/
    /*cout<<l<<" "<<r<<": ";
    cout<<mini<<" "<<p<<endl;*/

    return memo[l][r];
}

int main ()
{
    cin>>s;
    n=s.size();
    for (int i=0; i<n;  i++)
        for (int j=0; j<n; j++)
            memo[i][j]=MINI;

    ans=sol(0,n-1);
    printf("%d\n",ans-1);
    return 0;
}
