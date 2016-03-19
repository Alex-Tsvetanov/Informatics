#include<cstdio>
#include<iostream>
#include<cstring>
using namespace std;
const int MAXN=1111;
int n;
int seq[MAXN],cnt;
char s[MAXN],t[30];
void read()
{
    scanf("%s",s);
    n=strlen(s);
}
void solve()
{
    int i;
    bool a;
    cnt=0;
    seq[cnt]=2;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')
        {
            seq[++cnt]=2;
        }
        else
        if(s[i]==')')
        {
            seq[cnt-1]=seq[cnt];
            cnt--;
            if(seq[cnt-1]<2)
            {
                seq[cnt-1]=!(seq[cnt-1]&seq[cnt]);
                cnt--;
            }
        }
        else
        {
            a=t[s[i]-'a']-'0';
            if(seq[cnt]<2)
                seq[cnt]=!(seq[cnt]&a);
            else seq[++cnt]=a;
        }
    }
    printf("%d",seq[1]);
}
int main()
{
    read();
    while(1)
    {
        scanf("%s",t);
        if(t[0]=='2')break;
        solve();
    }
    printf("\n");
}
/*
a(a)(ab(ca)bb)c
011
100
010
111
001
2
*/
