#include <iostream>
#include <cstdio>
#include <stack>
using namespace std;
string s;
char s1[200002][3];
int n;
int exp[2000],end1[2000],place[2008];
bool value[2002];
stack <int> toclose;
bool used[100];
int br1=0,word[100];
int main()
{
    cin>>s;
    int br=0;
    n=s.length();
    for(int i=0;i<n;i++)
    {
        if(!used[s[i]])
        {
            used[i]=1;
        }
    }
    for(int i=0;i<26;i++)
    {
        if(used[i]==1)
        {
            word[i]=br1;
            br1++;
        }
    }
    int i1=0;

    for(int i=0; i<n; i++)
    {
        if(s[i]=='(')
        {
            exp[br++]=i;
            place[i]=br-1;
            toclose.push(br-1);
        }
        else if(s[i]==')')
        {
            end1[toclose.top()]=i;
            toclose.pop();
        }
    }
    while(1!=2)
    {
        scanf("%s",&s1[i1]);
        if(s1[i1][0]=='2')
            break;
        i1++;
    }
    for(int k=0; k<i1; k++)
    {
        for(int i=br-1; i>=0; i--)
        {
            bool val=s1[k][word[s[exp[i]+1]-'a']]-'0';
            for(int j=exp[i]+2; j<end1[i]; j++)
            {
                if(s[j]!='('&&s[j]!=')')
                {

                    val&=s1[k][word[s[j]-'a']];
                    val=!val;
                }
                else
                {
                    val&=value[place[j]];
                    val=!val;
                    j=end1[place[j]];
                }
            }
            value[i]=val;
        }
        bool ans;
        int start;
        if(s[0]!='('&&s[0]!=')')
            ans=s1[k][s[0]-'a']-'0',start=1;
        else
            ans=value[place[0]],start=end1[place[0]];
        for(int i=start; i<n; i++)
        {
            if(s[i]!='('&&s[i]!=')')
            {
                ans&=s1[k][word[s[i]-'a']];
                ans=!ans;
            }
            else if(s[i]=='(')
            {
                ans&=value[place[i]];
                ans=!ans;
                i=end1[place[i]];
            }
        }
        cout<<ans;
    }
}

/*
a(a)(ab(ca)bb)c
011
100
010
111
001
2

(aaa)(aaa)
1
2
aa(ab(aa)(ba)((ab)ba)aa)
11
*/
