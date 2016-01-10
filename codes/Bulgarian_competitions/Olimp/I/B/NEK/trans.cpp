#include <iostream>
#include <stdio.h>
#include <list>
using namespace std;

int br;

int main()
{
    int p,m;
    scanf("%d%d",&p,&m);
    int a[p];
    list<int>b;
    for(int i=0; i<m; i++)
    {
        int asd,bsd;
        scanf("%d%d",&asd,&bsd);
        a[asd]++;
        a[bsd]++;
    }
    int k;
    scanf("%d",k);
    for(int i=0; i<p; i++)
    {
        if(a[i]>=k)
        {
            b.push_back(i);
            br++;
        }
    }
    if(br==0)printf("0\n");
    else
    {
        printf("%d\n",br);
        for(int i=0;i<br;i++){
            printf("%d ",b.front());
            b.pop_front();
        }
    }

    printf("\n");

    }
