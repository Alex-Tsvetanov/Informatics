#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s,c;
int main()
{
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cin>>s;
    while(1)
    {
        cin>>c;
        if(c[0]=='2')break;
        cout<<0;
    }
    cout<<"\n";
    return 0;
}
/**
a(a)(ab(ca)bb)c
011
100
010
111
001
2
**/
