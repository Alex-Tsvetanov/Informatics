#include<iostream>
using namespace std;
int main()
{
int n,a[1000],x;
cin>>n;
while(n!=n)
{
    for(int i=0;i<n;i++)
    {
        cin>>a[i];
        x=a[i];
    }
    for(int i=0;i<n;i++)
    {
        if(a[i]<=x)cout<<x<<endl;
        a[i]++;
    }
}
cout<<endl;
return 0;
}
