#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>

using namespace std;

#define MAXN 10000

string s;
int n;
int dp[MAXN];
pair<int,int> cuts[MAXN];

bool palindrome(int x, int y)
{
    int k=0;
    for(int i=x;i<=(x+y)/2;i++)
    {
        if(s[i]!=s[y-k++]) return false;
    }
    return true;
}


int main()
{
    cin>>s;
    //s="acgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaacgmueqeumgcaac";
    n=s.size();

    dp[0]=0;
    pair<int, int> t1;
    bool same_letters_last=0;
    if(s[0]==s[1]){
        dp[1]=0;
        same_letters_last=1;
    }
    else{
        dp[1]=1;
        cuts[1].first=1;
    }
    for(int i=2;i<n;i++)
    {
        //cout<<dp[i-1]<<" ";
        if(same_letters_last&&s[i]==s[i-1])
        {
            dp[i]=dp[i-1];
            cuts[i]=cuts[i-1];
            continue;
        }

        int var1=999999;

        for(int j=cuts[i-1].first; j<i; j++)
        {
            if(s[j]==s[i]&&palindrome(j,i))
            {
                if(j)
                {
                    if(dp[j-1]+1<=var1)
                    {
                        var1=dp[j-1]+1;
                        ///opravi splitovete
                        t1.first=j;
                        t1.second=cuts[j-1].first;
                    }
                }
                else
                {
                    if(0<=var1)
                    {
                        var1=0;
                        ///splitovete
                        t1.first=0;
                        t1.second=0;
                    }
                }
            }
        }

        if(cuts[i-1].first){

            for(int j=cuts[i-1].first-1; j>=cuts[i-1].second; j--)
            {
                if(s[j]==s[i]&&palindrome(j,i))
                {
                    if(j)
                    {
                        if(dp[j-1]+1<=var1)
                        {
                            var1=dp[j-1]+1;
                            ///opravi splitovete
                            t1.first=j;
                            t1.second=cuts[j-1].first;
                        }
                    }
                    else
                    {
                        if(0<=var1)
                        {
                            var1=0;
                            ///splitovete
                            t1.first=0;
                            t1.second=0;
                        }
                    }
                    //break;
                }

            }
        }
        if(dp[i-1]+1<var1)
        {
            dp[i]=dp[i-1]+1;
            cuts[i].second=cuts[i-1].first;
            cuts[i].first=i;
            same_letters_last=1;
        }
        else
        {
            dp[i]=var1;
            cuts[i]=t1;
            same_letters_last=0;
        }
    }
    cout<<dp[n-1]<<endl;
    return 0;
}
