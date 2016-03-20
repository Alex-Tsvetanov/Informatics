#include <iostream>
#include <algorithm>
#define endl "\n"
using namespace std;
int main ()
{
    int n,p=1,h=0,k,i;
    cin>>n;
    for (i=2,k=1;i<n;i+=k,k++,i+=k) ;
    cout<<i-2<<endl;
    if (n>500) return 1;
}
