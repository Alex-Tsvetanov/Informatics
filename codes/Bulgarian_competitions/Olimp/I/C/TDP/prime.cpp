#include<iostream>
using namespace std;
int main ()
{
    int n,a,p[3000],i=0,pred=1,posl=10;
    cin>>n;
    for(int k;n!=0;k++)
    {
        p[i]=n%posl;
        n=n%posl;
        i++;
        posl=posl*10;
        }
        cout<<i<<p[i];
    return 0;
}
