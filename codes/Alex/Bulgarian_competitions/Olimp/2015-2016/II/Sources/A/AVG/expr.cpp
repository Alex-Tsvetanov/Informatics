#include<iostream>
#include<string>
#include<stack>
using namespace std;
stack<int> k;
string s;
int a[32];
char x;
int main()
{
    ios::sync_with_stdio(0);
    cin.tie(NULL);
    cin>>s;
    int sz=s.size(),n=0,e,t,l;
    for(int i=0;i<sz;i++)
    {
        if(s[i]>='a'&&s[i]<='z')
        if(s[i]-'a'>n)n=s[i]-'a';
    }//cout<<n<<endl;
    while(1)
    {
        cin>>x;
        if(x=='2')break;
        a[0]=x-'0';
        for(int i=1;i<=n;i++)
        {
            cin>>x;
            a[i]=x-'0';
        }
        for(int i=0;i<sz;i++)
        {
            if(s[i]>='a'&&s[i]<='z')
            {
                if(k.empty())
                {
                    t=a[s[i]-'a'];
                    k.push(t);
                }
                else if(k.top()>=0&&k.top()<=1)
                {
                    t=a[s[i]-'a'];
                   // cout<<t<<" "<<k.top()<<'\n';
                    e=!(k.top()&t);
                   // cout<<e<<'\n';
                    k.pop();
                    k.push(e);
                }
                else
                {
                    t=a[s[i]-'a'];
                    k.push(t);
                }
            }
            else if(s[i]=='(')
            {
                k.push(2);
            }
            else
            {
                t=k.top();
                k.pop();
                k.pop();
                if(k.empty())k.push(t);
                else if(k.top()>=0&&k.top()<=1)
                {
                    e=!(k.top()&t);
                    k.pop();
                    k.push(e);
                    //cout<<s[i]<<" "<<e<<'\n';
                }
                else
                {
                    k.push(t);
                }
            }
        }
        cout<<k.top();
        while(!k.empty())k.pop();
    }
    cout<<'\n';
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
