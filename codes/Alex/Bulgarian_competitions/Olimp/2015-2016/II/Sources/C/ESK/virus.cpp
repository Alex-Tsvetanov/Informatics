#include <iostream>
using namespace std;
int main ()
{
    long long n,power2=1,br=1,novbr=0,tekbr=0;
    cin>>n;
    while(power2<n)
    {
        power2*=2;
        br++;
    }
    br--;
    cout<<br<<endl;
    if(n<=500)
    {
        for(long long i=1;i<=br;i++)
        {
            novbr=0;
            tekbr=0;
            power2=1;
            for(long long j=1;j<=i;j++)power2*=2;
            for(long long j=1;j<=n;j++)if(j%power2>(power2/2)||j%power2==0)novbr++;
            cout<<novbr<<" ";
            for(long long j=1;j<=n;j++)
            {
                if(j%power2>(power2/2)||j%power2==0)
                {
                    tekbr++;
                    if(tekbr==novbr)cout<<j<<endl;
                    else cout<<j<<" ";
                }
            }
        }
    }
    return 0;
}
