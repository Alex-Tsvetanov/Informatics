#include <iostream>
using namespace std;
long long n,d[1000001],c[1000001],ii;

int main()
{
    cin>>n;

    for(int i=0;i<n;i++)
    {
        cin>>d[i];
    }

    c[n-1]=d[n-1];

    for(int i=n-2;i>=0;i--)
    {
        c[i]=max(c[i+1],d[i]);
    }

    c[n]=(-1000000000);

    if(n>1)
    {
        for(ii=0;ii<n;ii++)
        {
            if(d[ii]>=c[ii+1]){cout<<d[ii];break;}
        }

        ii++;

        for(ii;ii<n;ii++)
        {
            //cout<<c[ii+1]<<" "<<d[ii]<<endl;
            if(d[ii]>=c[ii+1]){cout<<" "<<d[ii];}
        }

        cout<<endl;
    }
    else cout<<d[0]<<endl;


    return 0;

}
