#include<iostream>
using namespace std;
int main()
{
    long long ar[10000],n,br=0;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>ar[i];
    }
    for(int i=0; i<n; i++)
    {
        for(int i1=i+1; i1<n; i1++)
        {
            if(ar[i]>=ar[i1])br++;
        }
        if(br==n-i-1)cout<<ar[i]<<" ";
        br=0;
    }

    return 0;
}
