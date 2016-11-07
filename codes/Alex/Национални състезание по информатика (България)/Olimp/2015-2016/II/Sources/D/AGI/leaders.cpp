#include<iostream>
using namespace std;
long long a[1000000], b[1000000];
int main()
{
    long long n, i, j, br=0, k=0, z=0;
    cin>>n;
    for(i=0; i<n; i++)cin>>a[i];
    for(i=0; i<n; i++)
    {
        for(j=i+1; j<n; j++)
        {
            if(a[2]<=a[i])br++;
            else break;
        }
        if(br==n-i-1){k++; b[z]=a[i]; z++;}
        br=0;
    }
    for(z=0; z<k; z++)
    {
        if(z!=k-1)cout<<b[z]<<" ";
        else cout<<b[z];
    }
    cout<<endl;
return 0;
}
