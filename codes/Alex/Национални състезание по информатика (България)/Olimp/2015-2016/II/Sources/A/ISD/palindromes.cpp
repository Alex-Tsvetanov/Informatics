#include<iostream>
#define base 27
#define MOD 1000000007
using namespace std;
long long hf[10002],hb[10002];
int dp[10002];
long long p[10002];
int n;
int main()
{
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin>>s;
    string crap=" ";
    crap=crap+s;
    s=crap;
    n=s.size();
    p[0]=1;
    p[1]=base;
    hf[0]=0;
    hf[1]=s[1]-'a'+1;
    for(int i=2;i<n;i++)
    {
        dp[i]=999999;
        hf[i]=(hf[i-1]*base+s[i]-'a'+1)%MOD;
        p[i]=(p[i-1]*base)%MOD;
    }
    hb[n-1]=s[n-1]-'a'+1;
    for(int i=n-2;i>=1;i--)
    {
        hb[i]=(hb[i+1]*base+s[i]-'a'+1)%MOD;
    }

    dp[0]=-1;
    dp[1]=0;
    for(int i=2;i<n;i++)
    {
        int mxl=i/2;
        long long nxt;
        if(i==n-1)nxt=0;
        else nxt=hb[i+1];
        for(int j=mxl;j>=1;j--)
        {
            long long prv=hf[i-2*j];
            int str=i-2*j;
            long long half1=(hf[str+j]-prv*p[j]+MOD*p[j])%MOD;
            long long half2=(hb[i-j+1]-nxt*p[j]+MOD*p[j])%MOD;
            //cout<<half1<<" "<<half2<<" "<<l<<endl;
            if(half1==half2)
            {
                dp[i]=min(dp[i],dp[str]+1);
            }
            str=i-2*j-1;
            prv=hf[str];
            half1=(hf[str+j]-prv*p[j]+MOD*p[j])%MOD;
            if(half1==half2)
            {
                dp[i]=min(dp[i],dp[str]+1);
            }
        }
        dp[i]=min(dp[i],dp[i-1]+1);
    }
   // for(int i=0;i<n;i++)cout<<p[i]<<" ";
    cout<<dp[n-1]<<endl;
    return 0;
}

