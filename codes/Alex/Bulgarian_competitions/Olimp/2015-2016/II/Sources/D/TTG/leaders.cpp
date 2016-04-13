#include<iostream>
using namespace std;
long long t=0;
long long c=0;
int n;

int main ()
{
    cin>>n;
    cin>>c;
    for(int i=0;i<n-1;i++)
    {
        cin>>t;
        if(c>t)
        {
            cout<<c<<' ';
        };
        c=t;
    }
    cout<<c<<endl;
    return 0;
}
