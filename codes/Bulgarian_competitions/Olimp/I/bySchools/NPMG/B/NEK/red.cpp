#include <stdio.h>
#include <iostream>
using namespace std;


int main()
{
    int n,maxs=0,mins=1000000,maxnm=0,minnm=0;
    scanf("%d",&n);
    int a[20000];
    for(int i=0; i<n; i++)
    {
        cin>>a[i];
        if(a[i]>maxs)
        {
            maxs=a[i];

        }
        if(a[i]<mins)
        {
            mins=a[i];
            minnm=i+1;
        }
    }
    for(int i=n; i>=0; i--)
    {
        if(a[i]==maxs)
        {
            maxnm=i+1;
            break;
        }
    }
    int maximum=maxnm-minnm;

    int maxd,mind;
    for(int i=0; i<n; i++)
    {
        if(a[i]==maxs)
        {
            maxd=i+1;
            break;
        }
    }
    for(int i=n; i>=0; i--)
    {
        if(a[i]==mins)
        {
            mind=i+1;
            break;
        }
    }
    if((mind-maxd>maximum)){
        printf("%d %d\n",maxd,mind);
    }
    else printf("%d %d\n",minnm,maxnm);

}
