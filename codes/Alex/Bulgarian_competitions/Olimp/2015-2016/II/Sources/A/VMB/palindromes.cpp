#include<iostream>
using namespace std;
long long hl1[10024],hl2[10024],hr1[10024],hr2[10024],s1=101,s2=103,fs1[10024],fs2[10024],mod1=1234567,mod2=(int)(1e9)+7;
int o[10024];
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    string s;
    int n,i,j;
    cin>>s;
    s='0'+s;
    n=s.size();
    fs1[0]=fs2[0]=1;
    for(i=1;i<n;++i)
    {
        fs1[i]=(fs1[i-1]*s1)%mod1;
        fs2[i]=(fs2[i-1]*s2)%mod2;
        hl1[i]=(hl1[i-1]*s1+(s[i]-'a'+1))%mod1;
        hl2[i]=(hl2[i-1]*s2+(s[i]-'a'+1))%mod2;
    }
    for(i=n-1;i>0;--i)
    {
        hr1[i]=(hr1[i+1]*s1+(s[i]-'a'+1))%mod1;
        hr2[i]=(hr2[i+1]*s2+(s[i]-'a'+1))%mod2;
    }
    o[0]=0;
    for(i=1;i<n;++i)
    {
        o[i]=o[i-1]+1;
        for(j=0;j*2<=i-2;j++)
        {
            if((hl1[i]-(hl1[i-j-1]*fs1[j+1])%mod1+mod1)%mod1==
               (hr1[i-j*2-1]-(hr1[i-j]*fs1[j+1])%mod1+mod1)%mod1 &&
               (hl2[i]-(hl2[i-j-1]*fs2[j+1])%mod2+mod2)%mod2==
               (hr2[i-j*2-1]-(hr2[i-j]*fs2[j+1])%mod2+mod2)%mod2)
                    o[i]=min(o[i],o[i-j*2-2]+1);
            if(j*2<i-2)
                if((hl1[i]-(hl1[i-j-1]*fs1[j+1])%mod1+mod1)%mod1==
               (hr1[i-j*2-2]-(hr1[i-j-1]*fs1[j+1])%mod1+mod1)%mod1 &&
               (hl2[i]-(hl2[i-j-1]*fs2[j+1])%mod2+mod2)%mod2==
               (hr2[i-j*2-2]-(hr2[i-j-1]*fs2[j+1])%mod2+mod2)%mod2)
                    o[i]=min(o[i],o[i-j*2-3]+1);
        }
    }
    cout<<o[n-1]-1<<'\n';
}
