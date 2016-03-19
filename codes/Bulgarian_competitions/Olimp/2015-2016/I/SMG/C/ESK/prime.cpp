#include <iostream>
#include <string>
using namespace std;
bool primes[30000];
int main ()
{
    for(long long i=0;i<=30000;i++)primes[i]=0;
    long long i;
    long long sum=0,sizes;
    for(i=2;i<=30000;i++)
    {
        if(primes[i]==0)
        {
            for(long long j=2*i;j<=30000;j+=i)primes[j]=1;
        }
    }
    string s;
    cin>>s;
    sizes=s.size();
    long long index=2;
    for(i=0;i<sizes;i++)
    {
        while(primes[index]==1)index++;
        if(s[i]=='1')sum+=index;
        index++;
    }
    cout<<sum<<endl;
    return 0;
}
