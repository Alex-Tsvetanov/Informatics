#include<iostream>
using namespace std;
int n;
char a[10060];
int isitnow(int n,char a[1060])
{
    int q=0;
    if(n%2==0)
    {
        int br1=n/2-1,br2=n/2;
        while(br1>=0)
        {
            if(a[br1]!=a[br2])
            {
                q++;
            }
            br1--;
            br2++;
        }
    }
    if(n%2==1)
    {
        int br1=n/2-1,br2=n/2+1;
        while(br1>=0)
        {
            if(a[br1]!=a[br2])
            {
                q++;
            }
            br1--;
            br2++;
        }
    }
    if(q==0)
    {
        return 0;
    }
    else
    {
        return 1;
    }
}
int main ()
{
    int b,j=0;
    cin>>n;
    for(int br3=0; br3<n; br3++)
    {
        cin>>a[br3];
    }
    b=isitnow(n,a);
    if(b==0)
    {
        cout<<0;
    }
    else
    {
        for(int t=-128; t<127 and j==0; t++)
        {
            a[n]=t;
            b=isitnow(n+1,a);
            if(b==0)
            {
                j++;
                cout<<1<<endl<<a[n];
            }
        }
        if(j==0)
        {
            for(int t=-128; t<127; t++)
            {
                for(int t1=-128; t1<127; t1++)
                {
                    a[n]=t;
                    a[n+1]=t1;
                    b=isitnow(n+2,a);
                    if(b==0)
                    {
                        j++;
                        cout<<2<<endl<<a[n]<<a[n+1];
                    }
                }
            }
        }
        if(j==0)
        {
            for(int t=-128; t<127; t++)
            {
                for(int t1=-128; t1<127; t1++)
                {
                    for(int t2=-128; t2<127; t2++)
                    {
                        a[n]=t;
                        a[n+1]=t1;
                        a[n+2]=t2;
                        b=isitnow(n+3,a);
                        if(b==0)
                        {
                            j++;
                            cout<<3<<endl<<a[n]<<a[n+1]<<a[n+2];
                        }
                    }
                }
            }
        }
    }
    return 0;
}
