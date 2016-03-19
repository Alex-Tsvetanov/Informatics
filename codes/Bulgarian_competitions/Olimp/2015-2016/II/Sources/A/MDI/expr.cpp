#include<iostream>
#include<queue>
#define MAXR 2000000
#define MAXN 27
using namespace std;

string input;
bool res[MAXR];
int len_in, res_i;

bool fx(bool a, bool b)
{
    return (!(a)|!(b));
}

void solve(string s, int l)
{
    queue<bool> q;
    bool values[MAXN];

    for(int i=0; i<l; i++)
    {
        values[i] = bool(s[i]-'0');
    }

    int flag=0;
    bool a, b;

    for(int i=0; i<len_in; i++)
    {
        if(input[i]==' ') continue;

        if(isalpha(input[i]) && flag==0)
        {
            flag = 1;
            a = values[input[i]-'a'];
        }
        else if(isalpha(input[i]) && flag==1)
        {
            flag = 0;
            b = values[input[i]-'a'];
            q.push(fx(a,b));
        }
        else if(input[i]=='(')
        {
            i++;
            ///CASE OF (x) - only one value
            if (input[i+1] == ')') q.push(values[input[i++]-'a']);
            else
            {
                int cnt_brack=1;
                queue<bool> q1;

                while(cnt_brack!=0 || i<len_in)
                {
                    if(input[i+1] == ')')
                    {
                        cnt_brack--;
                        i++;
                        continue;
                    }
                    else if (input[i+1] == '(')
                    {
                        cnt_brack++;
                        i++;
                        continue;
                    }

                    a = values[input[i]-'a'];
                    b = values[input[i+1]-'a'];
                    q1.push(fx(a,b));
                    i++;
                }

                bool tmp;
                if(!q1.empty())
                {
                    tmp = q1.front();
                    q1.pop();
                }
                while(!q1.empty())
                {
                    tmp = fx(tmp, q1.front());
                    q1.pop();
                }
                q.push(tmp);
            }
        }
    }

    bool tmp1;
    if(!q.empty()) tmp1 = q.front();
    q.pop();
    while(!q.empty())
    {
        tmp1 = fx(tmp1, q.front());
        q.pop();
    }
    res[res_i++] = tmp1;
}

int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin>>input;
    len_in = input.size();

    while(1)
    {
        string bin;
        cin>>bin;
        if(bin == "2") break;
        solve(bin, bin.size());
    }

    for(int i=0; i<res_i; i++) cout<<res[i];
    cout<<endl;
}
