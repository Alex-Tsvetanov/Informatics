#include<iostream>
using namespace std;
long long n[1000000];
int main()
{
    long long int p,m=0;
    cin>>p;
    for(int i=1; i<=p; i++)
    {
        cin>>n[i];
    }
    for(int i=1; i<p; i++)
    {

        if(n[i]>=n[i+1])
        {
            m=n[i];
            if(m!=n[i-1])
            {

                cout<<n[i]<<" ";
            }

        }
    }cout<<n[p];

}
