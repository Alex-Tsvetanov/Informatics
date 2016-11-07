#include<iostream>
#include<algorithm>
#include<cmath>
#include<string>
using namespace std;
string s1,s2,s3,s4;
int main()
{
    int i,sz,l=0;
    string s;
    cin>>s;
    sz=s.size();
    if(sz%2==0)
    {
    for(i=0;i<sz/2;i++)
    {
        s1+=s[i];
    }
    for(i=sz-1;i>=sz/2;i--)
    {
        s2+=s[i];
    }

    for(i=0;i<sz/2;i++)
        if(s1[i]!=s2[i]){l=1;break;}
    if(l==0){cout<<"0"<<endl;return 0;}
    }
    else
    {
        l=0;
        for(i=0;i<sz/2;i++)
    {
        s3+=s[i];
    }
    for(i=sz-1;i>sz/2;i--)
    {
        s4+=s[i];
    }
    for(i=0;i<sz/2;i++)
        if(s3[i]!=s4[i]){l=1;break;}
    if(l==0){cout<<"0"<<endl;return 0;}
    }
    cout<<sz<<endl;
    return 0;
}
