#include <iostream>
using namespace std;
int main()
{
    long long n,i,k,j;
    cin>>n;
    if(n>500)
    {
      cout<<n-2<<endl;
      return 0;
    }
    if(n==2)
    {
        cout<<1<<endl;
        cout<<1<<" "<<1<<endl;
        return 0;
    }
    if(n==3 || n==4)
    {
        cout<<2<<endl;
        cout<<2<<" "<<1<<" "<<2<<endl;
        cout<<2<<" "<<2<<" "<<3<<endl;
        return 0;
    }
    if(n==5)
    {
        cout<<3<<endl;
        cout<<2<<" "<<1<<" "<<2<<endl;
        cout<<2<<" "<<2<<" "<<3<<endl;
        cout<<2<<" "<<3<<" "<<4<<endl;
        return 0;
    }
    k=n/2;
    if(n%2!=0)
     cout<<n-k<<endl;
    else
     cout<<n-k<<endl;
    for(i=1;i<n-k+1;i++)
    {
        cout<<k<<" ";
        for(j=i;j<i+k-1;j++)
        {
            cout<<j<<" ";
        }
        cout<<i+k-1<<endl;
    }
    return 0;
}
