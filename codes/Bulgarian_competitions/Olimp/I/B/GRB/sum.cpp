#include<iostream>
using namespace std;

int main()
{
    unsigned int n, otg;
    1<=n<=3000;

    cin>>n;

    if(n%2==0)
        otg=n;
     else
        otg=n-1;

     cout<<otg;
}
