#include<iostream>
#include<algorithm>
#include<cmath>
#include<cstdio>
using namespace std;
string s, ans[1024];
int dp[1024], n, par[1024];

bool Compare(string a, string b)
{
    int na=a.size();
    int nb=b.size();
    if (na>nb) return true;
    if (na<nb) return false;
    return a>=b;
}

void Print(int k)
{
    if (k==-1) return;
    Print(par[k]);
    if (k!=n-1) cout<<ans[k]<<" ";
    else cout<<ans[k];
}

int main()
{
    cin>>s;
    if(s[0]=='0') {cout<<-1<<endl; return 0;}
    n=s.size();
    dp[0]=1;
    ans[0]=s.substr(0,1);
    par[0]=-1;
    for (int i=1; i<n; i++)
    {
        string number=s.substr(i,1);
        int max1=0, p=-1;
        for (int j=i-1; j>=0; j--)
        {
            if (dp[j]<dp[i-1]-1) {break;}
            if ((number[0]!='0' && Compare(number, ans[j])))
            {

                max1=dp[j];
                p=j;
                break;
            }
            number=s[j]+number;
        }
        dp[i]=max1+1;
        ans[i]=number;
        par[i]=p;
    }

    cout<<dp[n-1]<<endl;
    Print(n-1);
    cout<<endl;
    return 0;
}
