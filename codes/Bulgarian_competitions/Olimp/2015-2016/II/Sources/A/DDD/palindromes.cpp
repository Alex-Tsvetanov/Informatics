#include<iostream>
#include<cstdio>
#include<string>
using namespace std;
string s;
short mem[10000][10000];
int isPal(string s)
{
    int i,j,n=s.size();
    for(i=0,j=n-1;i<=j;i++,j--)
    {
        if(s[i]!=s[j]) return 0;
    }
    return 1;
}
int rec(int b,int l)
{
    if(mem[b][l]!=0) return mem[b][l];
    if(isPal(s.substr(b,l))) return 0;
    int ans=199999;
    for(int i=1;i<l;i++)
    {
        ans=min(ans,rec(b,i)+rec(b+i,l-i));
    }
    mem[b][l]=ans+1;
    return mem[b][l];
}
int main()
{
    cin>>s;
    printf("%d\n",rec(0,s.size()));
    return 0;
}
