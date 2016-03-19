#include <iostream>
#include <cstdlib>
#define endl '\n'
#define NMax 20
#define SMax 30

using namespace std;

long long p,n,s,memo[NMax+5][SMax+5];
long long ans;

long long solve(long long curs,long long curn)
{
    if(curn==0&&curs==0)
        return 1;
    else if(curn==0)return 0;

    long long curans=0;
    for(long long i=0;i<p;i++)
        if(curs>=i)
        {
            if(memo[curn-1][curs-i]!=0)
                curans+=memo[curn-1][curs-i];
            else
            {
                long long x=solve(curs-i,curn-1);
                memo[curn-1][curs-i]=x;
                curans+=x;
            }
        }
    return curans;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>p>>n>>s;

    memo[0][0]=1;

    for(long long i=0;i<s;i++)
        ans+=solve(i,n);

    cout<<ans<<endl;

    return 0;
}
