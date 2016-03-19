#include<iostream>
#include<string>
#include<algorithm>
using namespace std;
int t[32],t1,t2,r=200;
bool f(bool x,bool y)
{
    if(x==y==1) return false;
    return true;
}
int main()
{
    int x,y,i=0,j,sz;
    char c;
    string s,st,so;
    cin>>s;
    so=s;
    while(1)
    {
        cin>>st;
        if(st=="2") break;
        sz=st.size();
        for(i=0;i<sz;i++)
        {
            t[i]=st[i]-'0';
        }
        sz=s.size();
        for(i=0;i<sz;i++)
        {
            if(s[i]!='('&&s[i]!=')')
                s[i]=t[s[i]-'a'];
        }
        while(r--)
        {
            if(s.size()==1)
            {
                cout<<t[s[0]-'a']<<endl;
                break;
            }
            for(j=0;j<sz;j++)
            {
                if(s[j]=='(')
                {
                    st="";
                    t1=j;
                }
                if(s[j]!=')')
                {
                    st+=s[j];
                }
                if(s[j]==')')
                {
                    t2=j;
                    s[t2]=t[s[t2]];
                    s.erase(t1,t2);
                    break;
                }
            }
        }
        r=200;
    }
    cout<<endl;
    return 0;
}
