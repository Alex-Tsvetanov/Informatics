#include <iostream>
#include <iomanip>
#include <cmath>
#include <cstdlib>
#include <cstring>
#include <stack>

using namespace std;

string l;
bool m[26];

char f(char a, char b)
{
    return (~(l[a-'a'] - '0', b - '0')) + '0';
}

char f1(char a, char b)
{
    return (~(a - '0', b - '0')) + '0';
}

int main()
{
    string s;
    cin>>s;
    int a;
    while(l != "2")
    {
        cin>>l;
        stack<char> st;
        st.push(l[s[0]]);
        int i = 0;
        while(!st.empty() && i < s.size())
        {
            int k;
            ++i;
            if(s[i] >= 'a' && s[i] <= 'z')
            {
                k = st.top();
                if(k >= '0' && k <= '1')
                {
                    st.pop();
                    st.push(f(s[i], k));
                }
                else
                {
                    st.push(l[s[i]]);
                }
            }
            else if(s[i] == '(')
            {
                st.push(s[i]);
            }
            else if(s[i] == ')')
            {
                k = st.top();
                st.pop();
                st.pop();
                if(!st.empty())
                {
                    int x = st.top();
                    if(x >= '0' && x <= '1')
                    {
                        st.pop();
                        st.push(f1(x, k));
                    }
                    else
                    {
                        st.push(k);
                    }
                }
                else
                {
                    st.push(k);
                }
            }
        }
            cout<<st.top();
            st.pop();
            cout<<st.top();
    }
    return 0;
}
