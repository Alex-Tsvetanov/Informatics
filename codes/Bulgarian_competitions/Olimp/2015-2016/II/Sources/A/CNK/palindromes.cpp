#include<iostream>
#include<string>
using namespace std;
string niz;
int siz,memo[10240];
bool pal=1;
bool ispal(int f,int s)
{
    bool p=1;
    for(int i=0;f+i<s-i;i++)
    {
        if(niz[f+i]!=niz[s-i])
        {
            p=0;
            break;
        }
    }
    return p;
}
int findpal(int x)
{
    int minx;
    minx=memo[x-1]+1;
    for(int i=0;i<x;i++)
    {
        if(niz[x]==niz[i])
        {
            if(ispal(i ,x)==1)
            {
                if(i==0)
                {
                    minx=0;
                }else
                {
                    if(memo[i-1]+1<minx){minx=memo[i-1]+1;}
                }
            }
        }
    }
    return minx;
}
int main()
{
    cin>>niz;
    siz=niz.size();
    for(int i=0;i<siz-1-i;i++)
    {
        if(niz[i]!=niz[siz-1-i])
        {
            pal=0;
            break;
        }
    }
    if(pal==1)
    {cout<<0<<"\n";}else{
        memo[0]=0;
        for(int i=1;i<siz;i++)
        {
            memo[i]=findpal(i);
        }
    cout<<memo[siz-1]<<"\n";
    }
    return 0;
}
