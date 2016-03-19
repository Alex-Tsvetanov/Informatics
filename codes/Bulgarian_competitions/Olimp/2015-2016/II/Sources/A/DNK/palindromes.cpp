//Palindromes - Dimitar Karev
#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<string>
#include<vector>
#include<map>
#include<set>

#define lli unsigned long long
using namespace std;

unsigned int MOD=1000000009,B=29,B1=31, dp[12000],n;
lli Base[12000],Base1[12000],Hash[12000],Hash1[12000];
lli RevHash[12000],RevHash1[12000];

bool Check(int p,int q)
{

    long long H,H1,r;
    if(p==0)r=0;
    else r=Hash[p-1];
    if((Hash[q]-r)*Base[n-q-1]!=(RevHash[p]-RevHash[q+1])*Base[p])return 0;


    if(p==0)r=0;
    else r=Hash1[p-1];

    H=(Hash1[q]-r);
    if(H<0)H+=MOD;

    H*=Base1[n-q-1];
    if(H>=MOD)H%=MOD;

    H1=RevHash1[p]-RevHash1[q+1];
    if(H1<0)H1+=MOD;
    H1*=Base1[p];
    if(H1>=MOD)H1%=MOD;

    if(H!=H1)return 0;

    return 1;
}

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s;
    cin>>s;

    n=s.size();

    Base[0]=1; Base1[0]=1;
    for(int i=1;i<=n;i++)
    {
        Base[i]=Base[i-1]*B;
        Base1[i]=Base1[i-1]*B1;


        if(Base1[i]>=MOD)Base1[i]%=MOD;
    }

    Hash[0]=s[0]-'a'+1;
    Hash1[0]=s[0]-'a'+1;
    for(int i=1;i<n;i++)
    {
        Hash[i]=Hash[i-1]+(s[i]-'a'+1)*Base[i];
        Hash1[i]=Hash1[i-1]+(s[i]-'a'+1)*Base1[i];

        if(Hash1[i]>=MOD)Hash1[i]%=MOD;
    }

    RevHash[n-1]=s[n-1]-'a'+1;
    RevHash1[n-1]=s[n-1]-'a'+1;
    for(int i=n-2;i>=0;i--)
    {
        RevHash[i]=RevHash[i+1]+(s[i]-'a'+1)*Base[n-i-1];
        RevHash1[i]=RevHash1[i+1]+(s[i]-'a'+1)*Base1[n-i-1];

        if(RevHash1[i]>=MOD)RevHash1[i]%=MOD;
    }


    dp[0]=0;
    if(s[0]==s[1])dp[1]=0;
    else dp[1]=1;

    for(int i=2;i<n;i++)
    {
        dp[i]=dp[i-1]+1;
        if(Check(0,i)){dp[i]=0;continue;}

        for(int j=i-2;j>=0;j--)
        {
            if(Check(j+1,i))
            {
                if(dp[j]+1<dp[i])dp[i]=dp[j]+1;
            }

        }
    }

    cout<<dp[n-1]<<"\n";

    return 0;
}
