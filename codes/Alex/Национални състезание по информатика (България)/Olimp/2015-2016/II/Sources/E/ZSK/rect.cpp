#include <iostream>
using namespace std;
int main()
{
    long long n;
    long long br=0;
    long long i=0,j=1,k=0;
    long long sqr=4,sqr1=3;
    cin>>n;
    while(k<=n)
    {
        if((n-(sqr*j)-i)%(sqr1*j)-i==0)
    {
        br++;
        i++;
        j++;
    }
    k++;
    }
    cout<<br<<endl;
    return 0;
}
