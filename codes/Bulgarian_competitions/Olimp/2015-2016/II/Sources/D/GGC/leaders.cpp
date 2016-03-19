#include <iostream>
using namespace std;
int main()
{
long long  n,a[100000],flag=0;
cin>>n;
for(int i=0;i<n;i++)
{
    cin>>a[i];
}
int b=n;
for(int i=0;i<n;i++)
{
    while(b>i)
    {
        if(a[i]<a[b])
        {
            flag=1;
            b=0;
        }
       b--;
    }
    b=n;
    if(flag==0)cout<<a[i]<<" ";
    flag=0;
}
cout<<endl;
return 0;
}
