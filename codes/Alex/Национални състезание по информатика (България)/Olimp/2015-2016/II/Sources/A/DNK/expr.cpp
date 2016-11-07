//Expr - Dimitar Karev
#include<iostream>
#include<cmath>
#include<iomanip>
#include<climits>
#include<cstring>
#include<string>
#include<vector>
#include<algorithm>
#include<map>
#include<set>

#define lli long long
using namespace std;

int a[600],cnt[1000];

int main()
{
    ios::sync_with_stdio(false);
    cin.tie(NULL);

    string s,s1;
    cin>>s;

    int n=s.size(),lvl;

    cin>>s1;
    while(s1!="2")
    {
        for(int i=0;i<s1.size();i++)a[i+'a']=s1[i]-'0';

        lvl=0; cnt[0]=-1;
        for(int i=0;i<n;i++)
        {
            if(s[i]=='('){lvl++;cnt[lvl]=-1;continue;}
            if(s[i]==')')
            {
                if(cnt[lvl-1]==-1){cnt[lvl-1]=cnt[lvl];lvl--;continue;}
                if(cnt[lvl-1]==1 && cnt[lvl]==1)cnt[lvl-1]=0;
                else cnt[lvl-1]=1;

                lvl--;
                continue;
            }
            if(cnt[lvl]==-1){cnt[lvl]=a[s[i]];continue;}
            if(a[s[i]]==1 && cnt[lvl]==1)cnt[lvl]=0;
            else cnt[lvl]=1;
        }

        cout<<cnt[0];
        cin>>s1;
    }
    cout<<"\n";
    return 0;
}
/*
a(a)(ab(ca)bb)c
011
100
010
111
001
2
*/
