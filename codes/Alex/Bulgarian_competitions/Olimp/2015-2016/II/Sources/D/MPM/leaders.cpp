#include<iostream>
using namespace std;
int main()
{
    long long n,numbers[1000000],max=-10000000000,i,leaders[1000000],brl=0;
    cin>>n;
    for(i=0;i<n;i++)cin>>numbers[i];
    for(i=n-1;i>=0;i--)if(numbers[i]>=max){max=numbers[i];leaders[brl]=numbers[i];brl++;}
    for(i=brl-1;i>0;i--)cout<<leaders[i]<<' ';
    cout<<leaders[0]<<endl;
    return 0;
}