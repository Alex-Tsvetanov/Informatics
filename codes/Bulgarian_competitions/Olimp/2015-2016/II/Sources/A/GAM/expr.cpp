#include<iostream>
#include<cstdio>
#include<cstdlib>
#include<algorithm>
#include<set>
#include<vector>
#include<cmath>
#include<stack>
#include<cstring>

using namespace std;

#define MAXN 10000

string s;
string t;


struct expz
{
    string e;
    int level;
    int time;
};

bool cmp (expz x, expz y)
{
    if(x.level==y.level) return x.time<y.time;
    return x.level>y.level;
}

bool f(int a, int b)
{
    if(a&&b) return 0;
    return 1;
}

vector<expz> a;

int main()
{
    cin>>s;
    int level=0;
    expz temp;
    temp.e="";
    temp.level=0;
    temp.time=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]=='(')
        {
               temp.time=i;
               if(temp.e.size())
               a.push_back(temp);
               temp.level++;
               temp.e="";
        }

        else if(s[i]==')')
        {
            if(temp.e.size()==1){
                temp.time=i;
                temp.level--;
                if(temp.e.size())
                a.push_back(temp);
                temp.e="";
            }
            else
            {
                temp.time=i;
                if(temp.e.size())
                a.push_back(temp);
                temp.level--;
                temp.e="";
            }
        }
        else temp.e+=s[i];
    }
    sort(a.begin(),a.end(),cmp);

    while(1)
    {
        cin>>t;
        if(t[0]=='2') break;
        stack<int>res;
        int tmmp=-1;
        for(int i=0;i<s.size();i++)
        {
            if(s[i]=='(')
            {
                //cout<<"pusing"<<tmmp<<endl;
                res.push(tmmp);
                tmmp=-1;
            }
            else if(s[i]==')')
            {
                //cout<<"popping, got "<<res.top()<<" and tmmp="<<tmmp<<endl;
                if(tmmp==-1) tmmp=res.top();
                else  tmmp=f(tmmp,res.top());
                res.pop();
            }
            else
            {

                if(tmmp==-1) tmmp=t[s[i]-'a']-'0';
                else tmmp=f(tmmp,t[s[i]-'a']-'0');
                //cout<<"tmmp="<<tmmp<<endl;
            }
        }
        cout<<tmmp;
    }
    cout<<endl;
    return 0;
}
