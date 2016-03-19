#include<iostream>
#include<string>
using namespace std;
string niz,st;
bool val[32];
bool f(bool a,bool b)
{
    if(a==b&&b==1){return 0;}
    return 1;
}
bool calc(int first,int last)
{
    bool a,b;
    int open=0,i=0;
    if(niz[first]=='(')
    {
        open++;
        i++;
        while(open>0)
        {
            if(niz[first+i]=='('){open++;}else{if(niz[first+i]==')'){open--;}}
            i++;
        }
        a=calc(first+1,first+i-2);
        first+=i;
        i=0;
    }else
    {
        a=val[niz[first]-'a'];
        first++;
    }
    for(;last>=first;)
    {
        if(niz[first]=='(')
        {
            open++;
            i++;
            while(open>0)
            {
                if(niz[first+i]=='('){open++;}else{if(niz[first+i]==')'){open--;}}
                i++;
            }
            b=calc(first+1,first+i-2);
            first+=i;
            i=0;
        }else
        {
            b=val[niz[first]-'a'];
            first++;
        }
        a=f(a,b);
    }
    return a;
}
int main()
{
    cin>>niz;
    while(1)
    {
        cin>>st;
        if(st[0]=='2'){break;}else
        {
            for(int i=0;i<st.size();i++)
            {
                val[i]=st[i]-'0';
            }
        }
        cout<<calc(0,niz.size()-1);
    }
    cout<<"\n";
    return 0;
}
/*
a(a)(ab(ca)bb)c
011 100 010 111 001 2
*/
