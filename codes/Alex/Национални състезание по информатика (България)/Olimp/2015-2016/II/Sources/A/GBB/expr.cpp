#include<iostream>
#include<string>
#include<stack>
using namespace std;
int main()
{
    int sz, i, t1, t2;
    string s, ss;
    cin>>s;
    sz=s.size();
    stack<char>st;
    for(;;)
    {
        cin>>ss;
        if(ss[0]=='2') break;
        for(i=sz-1;i>=0;i--)
        {
            if(s[i]>='a' && s[i]<='z')
            {
                st.push(ss[s[i]-'a']-'0');
            }
            else if(s[i]==')')
            {
                st.push(s[i]);
            }
            else if(s[i]=='(')
            {
                t1=st.top();
                st.pop();
                while(st.top()!=')')
                {
                    t2=st.top();
                    if(t1==0 && t2==0)
                    {
                        t1=1;
                    }
                    else
                    {
                        t1^=t2;
                    }
                    st.pop();
                }
                st.pop();
                st.push(t1);
            }
            if(i==0)
            {
                t1=st.top();
                st.pop();
                while(!st.empty())
                {
                    t2=st.top();
                    if(t1==0 && t2==0)
                    {
                        t1=1;
                    }
                    else
                    {
                        t1^=t2;
                    }
                    st.pop();
                }
            }
        }
        cout<<t1;
    }
    cout<<endl;
    return 0;///a(a)(ab(ca)bb)c
}
/**string s;
    cin>>s;
    for(;;)
    {
        cin>>s;
        if(s[0]=='2') break;
        cout<<1;
    }
    cout<<endl;**/
