#include <iostream>
#include <string>
#include <list>
#include <vector>
using namespace std;
list <bool> l;
list <bool> ::iterator it;
vector<int>beg,bac;
int main()
{
    string s,supd,abc;
    cin>>s;
    int br=0;
    for(int i=0;i<s.size();i++)
    {
        if(s[i]!='('&&s[i]!=')')supd+=s[i];
        if(s[i]=='(')beg.push_back(supd.size());
        if(s[i]==')')bac.push_back(supd.size()-1);
    }
    while(abc!="2")
    {
        cin>>abc;
        l.clear();
        for(int i=0;i<supd.size();i++)
        {
            l.push_back(abc[supd[i]-'a']-'0');
        }
        for(it=l.begin();it!=l.end();it++)
        {
            cout<<*it;
        }

    }
}
/*
a(a)(ab(ca)bb)c
*/
