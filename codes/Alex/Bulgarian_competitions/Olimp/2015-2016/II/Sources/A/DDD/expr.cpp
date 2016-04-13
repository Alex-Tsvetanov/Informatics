#include<iostream>
#include<cstdio>
#include<stack>
using namespace std;
int aa,b,p,n,i,b1;
int v[32],e[1024];
char a;
bool ok;
stack<int> s,s1;
string ans;
int main()
{
    aa='a'-1;
    for(n=0;; n++)
    {
        scanf("%c",&a);
        if(a=='\n') break;
        if(a=='(' || a==')') e[n]=a;
        else
        {
            b=a-aa;
            e[n]=b;
            p=max(p,b);
        }
    }
    p++;
    for(;;)
    {
        for(i=1; i<p; i++)
        {
            scanf("%c",&a);
            if(a=='2')
            {
                ok=1;
                break;
            }
            v[i]=a-'0';
        }
        if(ok) break;
        scanf("\n");

        for(i=0; i<n; i++)
        {
            if(e[i]==')')
            {
                for(; !s.empty();)
                {
                    b=s.top();
                    s.pop();
                    if(b=='(') break;
                    s1.push(b);
                }
                if(!s1.empty())
                {
                    b=s1.top();
                    s1.pop();
                }
                for(; !s1.empty();)
                {
                    b1=s1.top();
                    s1.pop();
                    b=(b&b1)^1;
                }
                s.push(b);
            }
            else if(e[i]=='(') s.push(e[i]);
            else s.push(v[e[i]]);
        }
        for(; !s.empty();)
        {
            b=s.top();
            s.pop();
            s1.push(b);
        }
        if(!s1.empty())
        {
            b=s1.top();
            s1.pop();
        }
        for(; !s1.empty();)
        {
            b1=s1.top();
            s1.pop();
            b=(b&b1)^1;
        }
        //printf("%d",b);
        ans+=b+'0';
    }
    //printf("\n");
    cout<<ans<<endl;
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
