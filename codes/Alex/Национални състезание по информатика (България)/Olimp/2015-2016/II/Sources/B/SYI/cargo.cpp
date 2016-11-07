#include<cstdio>
#include<algorithm>
#include<iostream>
using namespace std;

int piloti[1000000];

struct day
{
    int from,to;
}dni[1000000];

bool sort1(day a,day b)
{
    if(a.from==b.from)return a.to<b.to;
    return a.from<b.from;
}

int main()
{
        int n,m,p,i;

        scanf("%d %d %d",&n,&m,&p);

        p/=2;
        for(i=1;i<=m;i++)scanf("%d %d",&dni[i].from,&dni[i].to);
        sort(dni,dni+m+1,sort1);
        int f=0,q=0,sum;
        for(i=1;i<=m;i++)
        {
            if(piloti[dni[i].from]<p and dni[i].from%6!=0 and dni[i].from%7!=0)piloti[dni[i].from]+=1;
            else
            {
                sum= dni[i].from +1;
                while(sum<=dni[i].to and f==0)
                {
                    if(piloti[sum]<p and sum%6!=0 and sum%7!=0)piloti[sum]++,f=1;
                    sum++;
                }
                if(f==0)
                {
                    sum= dni[i].from +1;
                    while(sum<=dni[i].to and f==0)
                    {
                        if(piloti[sum]<p)piloti[sum]++,f=1;
                        sum++;
                    }
                }
                if(piloti[dni[i].from]<p and f==0)piloti[dni[i].from]++,f=1;
                if(f==0)printf("IMPOISIBLE\n"),q=1;
                f=0;
            }
        }
        if(q==0)
        for(i=1;i<=n;i++)
        {
            if((i%6==0 or i%7==0) and piloti[i]!=0)printf("MIXED\n"),q=2;

        }
        if(q==0)printf("OK\n");

}

