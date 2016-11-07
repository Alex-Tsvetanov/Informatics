#include<iostream>
using namespace std;
long long nums[1000001];
long long leaders[1000001];
int main()
{
    int n;
    cin>>n;
    for(int i=0; i<n; i++)
    {
        cin>>nums[i];
    }
    long long cMax=0;
    int ans=0;
    for(int i=n-1; i>=0; i--)
    {
        if(nums[i]>=cMax)
        {
            leaders[ans]=nums[i];
            ans++;
            cMax=nums[i];
        }
    }
    for(int i=ans-1;i>=0;i--){
        cout<<leaders[i];
        if(i!=0){
            cout<<" ";
        }
    }
    cout<<endl;
    return 0;
}
