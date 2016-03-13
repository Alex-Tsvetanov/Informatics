#include<iostream>
using namespace std;
int main()
{
    int n,d1,d2,d3;
    cin>>n>>d1>>d2>>d3;
    if(n<=7)
    {
        cout<<3*n;
    }
    else
    {
        if(n<10)
        {
            cout<<5*n;
        }
        else
        {
            cout<<7*n;
        }
    }
    return 0;
}
