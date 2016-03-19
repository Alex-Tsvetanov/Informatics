#include <iostream>
#define MAXN 30
using namespace std;
int p,n,s;
long long br=1;

void prm (int k[])
{
    int ch[p];
    long long fac=1,rr;

    for (int i=0; i<=p; i++) ch[i]=0;

    for (int i=0; i<n; i++)
    {
        ch[k[i]]++;
    }


    for (int i=2; i<=n; i++)
    {
        fac=fac*i;
    }
    rr=fac;

    for (int i=0; i<p; i++)
    {
        fac=1;
        for (int j=2; j<=ch[i]; j++)
        {
            fac=fac*j;
        }
        rr=rr/fac;
    }
    br=br+rr;

}

void dd(int k[],int ts, int wh)
{
    if (ts<s-1)
    {
        if (wh==0)
        {
            k[0]=k[0]+1;
            if (k[0]<p)
            {
                prm(k);
                dd(k,ts+1,wh);
            }
            k[0]=k[0]-1;
            wh++;
        }

        for (int i=wh; i<n; i++)
        {
            if (k[i]<k[i-1])
            {
                k[i]=k[i]+1;
                if (k[i]<p)
                {
                    prm(k);
                    dd(k,ts+1,wh);
                }
                k[i]=k[i]-1;
            }
        }
    }
}

int main ()
{
    cin>>p>>n>>s;
    int k[n];
    for (int i=0; i<n; i++)
    {
        k[i]=0;
    }

    dd (k,0,0);
    cout<<br<<endl;
    return 0;
}
