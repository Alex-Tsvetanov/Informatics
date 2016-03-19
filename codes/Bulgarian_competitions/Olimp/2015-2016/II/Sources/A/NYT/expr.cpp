#include<iostream>
#include<cstdio>
#include<vector>
#include<stack>
#include<algorithm>
using namespace std;
struct izr
{
    int from,to,depth;
}temp;
bool sort1(izr a,izr b)
{
    return a.depth>b.depth;
}
int krai[1005],izrazSt[1005],bukvaSt[50];
vector<izr>skobi;
string s;
vector<char>kravi;
void calc()
{
    int i,j,lf,lt;
    bool f;
    for(i=0;i<skobi.size();i++)
    {
        lf=skobi[i].from+1;
        lt=skobi[i].to;
        if(s[lf]=='(')
        {
            f=izrazSt[lf];
            lf=krai[lf]+1;
        }
        else
        {
            f=bukvaSt[s[lf]-'a'];
            lf++;
        }
        //printf("na4alna st na f %d\n",f);
        while(lf<lt)
        {
            if(s[lf]=='(')
            {
                f=!(f&izrazSt[lf]);
                lf=krai[lf]+1;
            }
            else
            {//printf("bukvata e %c ,s[lf]=%d,bukvaSt=%d\n",s[lf],s[lf]-'a',bukvaSt[s[lf]-'a']);
                f=!(f&bukvaSt[s[lf]-'a']);
                //printf("f sl tova=%d\n",f);
                lf++;
                //printf("%d %d\n",lf,lt);
            }
        }
        //printf("%d\n",skobi[i].from);
        izrazSt[skobi[i].from]=f;
        //printf("%d a stoinostta stava\n",skobi[i].from);
    }
}
int used[100];
int main()
{
    int a,n,i,j;
    string s1;
    bool f;
    stack<int>sk;
    cin>>s;
    n=s.size();
    for(i=0;i<n;i++)
        if(s[i]!='('&&s[i]!=')')used[s[i]-'a']=1;
    for(i=0;i<n;i++)
    {
        if(s[i]=='(')sk.push(i);
        else if(s[i]==')')
        {
            temp.from=sk.top();
            temp.to=i;
            temp.depth=sk.size();
            skobi.push_back(temp);
            krai[sk.top()]=i;
            sk.pop();
        }
    }
    sort(skobi.begin(),skobi.end(),sort1);
    do
    {
        cin>>s1;
        if(s1[0]=='2')break;j=0;
        for(i=0;i<s1.size();i++)
        {
            for(j;j<27;j++)if(used[j]==1)break;
            bukvaSt[j]=s1[i]-'0';
        }
        calc();
        i=1;
        if(s[0]=='(')
        {
            f=izrazSt[0];
            i=krai[0];
        }
        else f=bukvaSt[s[0]-'a'];
        while(i<n)
        {
            if(s[i]=='(')
            {
                f=!(f&izrazSt[i]);
                i=krai[i]+1;
            }
            else
            {
                f=!(f&bukvaSt[s[i]-'a']);
                i++;
            }
        }
        printf("%d",f);


        //for(i=0;i<skobi.size();i++)printf("%d %d %d\n",skobi[i].from,skobi[i].to,izrazSt[skobi[i].from]);
    }
    while(s1[0]!='2');
    printf("\n");
}
//a(a)(ab(ca)bb)c
