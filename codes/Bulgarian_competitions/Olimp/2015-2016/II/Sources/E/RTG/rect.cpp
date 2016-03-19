#include <iostream>
#include <string.h>
using namespace std;
int main()
{
    long long n,br=0;
    cin>>n;
    for(int i=1;i<=n/2;i++)
    {
        if((n-i)%5==0)br++;
    }
    cout<<br<<endl;
    return 0;
}