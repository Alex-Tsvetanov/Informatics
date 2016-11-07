#include <cstdio>
#include <iostream>
using namespace std;

#define letters 26

string s;
int a[letters],v;

int solve(int x,int y,int k)
{
    int j;
    k=a[s[x]-'a'];
    for(j=x+1;j<y;j++)
    {
        if(s[j]=='(')
        {
            k=!(k&(solve(j+1,y,0)));
            j=v;
        }
        else if(s[j]==')'){v=j;return k;}
        else k=!(k&a[s[j]-'a']);
    }
    return k;
}

int main()
{
    string sm,ans("");
    int i;
    cin>>s;
    cin>>sm;
    while(sm[0]!='2')
    {
        for(i=0;i<sm.size();i++)a[i]=sm[i]-'0';
        if(solve(0,s.size(),0)==1)ans=ans+'1';
        else ans=ans+'0';
        cin>>sm;
    }
    cout<<ans<<endl;
    return 0;
}
