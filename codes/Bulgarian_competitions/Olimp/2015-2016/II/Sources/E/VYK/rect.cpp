#include<iostream>
#include<iomanip>
#include<cmath>
using namespace std;
int main ()
{
    long long n,br=0;
    cin>>n;
    for (int i=1;i<=n;i++)
    {
        for (int j=1;j<=n-(i-1);j++)
        {
            if ((i+j*3)*i==n) {br++;}
        }
    }
    cout<<br<<"\n";
    return 0;
}
