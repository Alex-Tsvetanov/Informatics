#include<iostream>
using namespace std;
int main()
{   long long int n,a[100000],i,l,br=0,j;
    cin>>n;
    for(i=0;i<n;i++)
    {
     cin>>a[i];
    }
    l=a[0];
    for(i=1;i<n;i++)
    {
     if(a[i]<=l)br++;
    }
    if(br==n-1)cout<<l<<" ";
    i=1;
    while(l!=a[n-2])
    {
     br=0;
     l=a[i+1];
     for(j=i+1;j<n;j++)
     {
      if(a[j]<=l)br++;
     }
     if(br==n-(i+1))cout<<l<<" ";
     i++;
    }
    cout<<a[n-1]<<endl;





return 0;
}
