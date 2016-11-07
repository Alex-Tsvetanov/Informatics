#include <iostream>
#include <cstdio>
#include <cstring>
#include <stack>
using namespace std;
string s,t,ans;
int ss[1010],n;
int a[30];
stack<int>st;
int tans,x,y;

int fun(int p, int q)
{
    if (p==1 && q==1) return 0;
    return 1;
}

void sol()
{
    //cout<<"----------------"<<endl;
    memset(a,0,sizeof(a));
    for (int i=0; i<t.size(); i++)
        if (t[i]=='1') a[i]=1;
    //for(int i=0; i<t.size(); i++) cout<<a[i]<<endl;
    if (ss[0]==-100)st.push(-100);
    else st.push(a[ss[0]]);
    for (int i=1; i<n; i++)
    {
        //cout<<st.top()<<" ";
        if (ss[i]>=0 && ss[i]<=25)
        {
            x=st.top();
            if (x==-100) tans=a[ss[i]];
            else
            {
                st.pop();
                tans=fun(x,a[ss[i]]);
                //cout<<endl<<i<<" "<<tans<<" "<<a[ss[i]]<<" "<<x<<endl;
            }
            st.push(tans);
        }
        if (ss[i]==-100) st.push(-100);
        if (ss[i]==100)
        {
            x=st.top();
            st.pop();
            st.pop();
            tans=fun(x,st.top());
            st.pop();
            st.push(tans);
        }

    }
    tans=st.top();
    //cout<<tans<<endl;
    st.pop();
    ans+=(tans+48);
}

void read()
{
    cin>>s;
    n=s.size();
    for (int i=0; i<n; i++)
    {
        if (s[i]=='(') ss[i]=-100;
        else if (s[i]==')') ss[i]=100;
        else ss[i]=s[i]-'a';
    }
    while (1)
    {
       cin>>t;
       if (t=="2") break;
       else sol();
    }
    cout<<ans<<endl;
}

int main ()
{
    read();
    return 0;
}
