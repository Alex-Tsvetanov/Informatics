#include<iostream>
using namespace std;
int main ()
{
    int n,a,b,mini;
    mini=n;
    cin>>n;
    a=1;
    while(a<n)
    {
        if(n%a==0)
        {
            b=n/a;
            if(a+b+b+a<mini)
            {
                mini=a+a+b+b;
            }
        }
        a++;
    }
    cout<<mini;
    cout<<endl;
    return 0;
}
