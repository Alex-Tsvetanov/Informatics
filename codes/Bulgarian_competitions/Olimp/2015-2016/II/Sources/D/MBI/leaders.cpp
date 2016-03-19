#include<iostream>
using namespace std;
long long a[1000000],b[1000000];
int main ()
{
    long long n,key=0,key1=0,p=0;
    long long i,j;
    cin>>n;
    for ( i=0;i<n;i++)
    {
        cin>>a[i];
    }
    for (i=0;i<n;i++)
    {
        for (j=i;j<n;j++)
        {
        if (a[j]<=a[i]) key=0;
        else key1++;
        }
        if (key1!=0) key1=0;
        else
        {
            b[p]=a[i];
            p++;
        }
    }
    cout<<b[0];
    for (i=1;i<p;i++)
    {
        cout<<" "<<b[i];
    }
    cout<<endl;
    return 0;
}