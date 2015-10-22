#include<iostream>
#include <stdio.h>
using namespace std;
long long vhod[5500],n;
bool IsSorted(int s,int e)
{
    for(int i=s; i<e-1; i++)
    {
        if(vhod[i]>vhod[i+1])
        {
            return false;
        }
    }
    return true;
}
void Merge(int istart,int iend)
{
    //cout<<"istart="<<istart<<"iend="<<iend<<"\n";
    for(int i=0; i<n-1; i++)
    {
        //cout<<vhod[i]<<" ";
    }
    //cout<<vhod[n-1]<<"\n";
    int i=vhod[istart];
    int vhod2[100];
    for(int j=istart; j<iend; j++)
    {
        vhod2[j]=vhod[j];
    }
    int c;
    int p=istart;
    for(int g=istart; g<iend; g++)
    {
        if(vhod2[g]<i)
        {
            vhod[p]=vhod2[g];
            p++;
        }
    }
    for(int g=istart; g<iend; g++)
    {
        if(vhod2[g]==i)
        {
            vhod[p]=vhod2[g];
            p++;
            c=p;
        }
    }
    for(int g=istart; g<iend; g++)
    {
        if(vhod2[g]>i)
        {
            vhod[p]=vhod2[g];
            p++;
        }
    }
//    for(int i=0; i<n-1; i++)
    {
        //cout<<vhod[i]<<" ";
    }
    //cout<<vhod[n-1]<<"\n";
    if(!IsSorted(istart,iend))
    {
        //cout<<"istart="<<istart<<" c="<<c<<" p="<<p<<" iend="<<iend<<"\n";
        Merge(istart,c-1);
        Merge(c,iend);
    }
}

int main()
{
    scanf("%lld",&n);
    for(int i=0; i<n; i++)
    {
       scanf("%lld",&vhod[i]);
    }
    Merge(0,n);
    for(int i=0; i<n; i++)
    {
        printf ("%lld ",vhod[i]);
    }
    return 0;
}
/*9
3 8 5 2 7 6 1 4 9*/
