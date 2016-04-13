#include<iostream>
using namespace std;

long long nums[1000005];
long long leaders[1000005];

int main()
{
    long long n;
    cin>>n;

    for(long long i=n-1;i>=0;i--)
    {
        cin>>nums[i];
    }

    long long maxn=nums[0];
    leaders[0]=nums[0];
    long long j=1;

    for(long long i=1;i<n;i++)
    {
        //cout<<nums[i]<<endl;
        if(nums[i]>maxn)
        {
            leaders[j]=nums[i];
            j++;
            maxn=nums[i];
        }
    }

    cout<<leaders[j-1];
    for(long long i=j-2;i>=0;i--)
    {
        cout<<" "<<leaders[i];
    }
    cout<<endl;
    return 0;
}
// 7 50 1 40 2 3 4 30
// 15 100 99 26 1 23 73 48 37 23 23 21 10 11 7 3
