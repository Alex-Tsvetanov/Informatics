#include<iostream>
using namespace std;
int main()
{
    string s;
    long long brs=0,brc=0,i,p,k,mx,mn;
    getline(cin,s,'.');
    for(i=0; i<s.size()-1; i++)
    {
        brs++;
        if(i>=2)
        {
        if(s[i-1]==s[i] && s[i-1]!=s[i-2])
        {
            brc=brc+2;
        }
        else if(s[i-1]==s[i] && s[i-1]==s[i-2])
        {
            brc=brc+2;
        }
        if(s[i-1]==s[i])
        {
            brc++;
        }
        }
    }
    mn=min(brs,brc);
    mx=max(brs,brc);
    cout<<mx-mn<<endl;
    return 0;
}
