#include <iostream>
using namespace std;
long long NOD(long long a,long long b)
{
    long long t;
    while(a>0)
    {
        t=a;
        a=b%a;
        b=t;
    }
    return b;
}
int main ()
{
    long long X;
    long long div[2][100000];
    for(long long i=0;i<=100000;i++)
    {
        div[0][i]=0;
        div[1][i]=0;
    }
    cin>>X;
    long long k=2;
    long long index=0;
    bool f=false;
    while(X>1)
    {
        if(X%k==0)f=true;
        while(X%k==0)
        {
            X/=k;
            div[1][index]=k;
            div[0][index]++;
        }
        if(f==true)index++;
        f=false;
        k++;
    }
    long long i=0;
    long long nod=div[0][i];
    for(i=0;i<index;i++)
    {
        nod=NOD(nod,div[0][i]);
    }
    long long br=0;
    for(long long del=2;del<=nod;del++)
    {
        if(nod%del==0)br++;
    }
    cout<<br<<endl;
    long long p=1,puti;
    if(br!=0)
    {
        for(long long del=2;del<=nod;del++)
        {
            if(nod%del==0)
            {
                for(long long i=0;i<index;i++)
                {
                    puti=div[0][i]/del;
                    for(long long j=0;j<puti;j++)p*=div[1][i];
                }
                cout<<p<<" "<<del<<endl;
                p=1;
            }
        }
    }
    return 0;
}
