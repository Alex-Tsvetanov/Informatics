#include<iostream>
#include<string>
using namespace std;

string s1,s[200002];
int n;

pair <string,int> rec(int pos, string str)
{
    for(;;)
    {
        if(s1[pos]=='(')
        {
            pair<string,int> p=rec(pos+1, "");
            string ans;
            int x,y,z;
            if(str==""){str=p.first;pos=p.second+1;}
            else
            {
                for(int i=0;i<n;i++)
                {
                    x=(char)str[i]-'0';
                    y=(char)p.first[i]-'0';
                    z=((x&y)^1);
                    ans=ans+(char)(z+'0');
                }
                pos=p.second+1;
                str=ans;
            }
            continue;
        }
        if(s1[pos]==')'){pair<string,int> p;p.first=str;p.second=pos;return p;}
        string ans;
        int m=(char)s1[pos]-'a';
        int x,y,z;
        for(int i=0;i<n;i++)
        {
            if(str==""){ans=ans+s[i][m];continue;}
            x=(char)str[i]-'0';
            y=(char)s[i][m]-'0';
            z=((x&y)^1);
            ans=ans+(char)(z+'0');
        }
        str=ans;
        pos++;
    }
}

int main()
{
    cin>>s1;
    for(int i=0;;i++)
    {
        cin>>s[i];
        if(s[i]=="2"){n=i;break;}
    }
    s1=s1+")";
    cout<<rec(0,"").first<<endl;
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

