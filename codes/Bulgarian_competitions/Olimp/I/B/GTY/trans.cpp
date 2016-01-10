#include<iostream>
#include<algorithm>

using namespace std;
int nums[20016];
int main()
{
    int N,P,K;
    cin>>P>>N;
    for(int i=0;i<N*2;i+=2){cin>>nums[i]>>nums[i+1];}
    cin>>K;
    vector<int> res;
    sort(nums,nums+N*2);
    int br=0;
    for(int i=1;i<N*2+1;i++)
    {
        int b=0;
        while(i<N*2+1){if(nums[i]==nums[i-1]){i++;b++;}else break;}
        if(b+1>=K)res.push_back(nums[i-1]);
    }
    cout<<res.size()<<endl;
    for(int i=0;i<res.size()-1;i++)cout<<res[i]<<" ";
    cout<<res[res.size()-1];
    return 0;
}
