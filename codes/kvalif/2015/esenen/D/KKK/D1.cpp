#include<iostream>
using namespace std;
int main()
{
    int n;
    int p=4;
    cin>>n;
    for(int i=1; i<n; i++)
    {
        if(i*i>n)
        {
            break;
        }
        if(n%i==0)
        {
            p=(i+n/i)*2;
        }
    }
    cout<<p<<endl;
    return 0;
}
