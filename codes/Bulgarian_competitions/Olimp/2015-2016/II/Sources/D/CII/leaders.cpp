#include<iostream>
using namespace std;
long long numbers[999999],n,maxn,found[999999],k;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>numbers[i];
    maxn=numbers[n-1];
    for(int i=n-2;i>=0;i--)
        if(numbers[i]>maxn)
        {
            found[k]=numbers[i];
            maxn=numbers[i];
            k++;
        }
    k--;
    for( ;k>=0;k--)
        cout<<found[k]<<" ";
    cout<<numbers[n-1]<<endl;
    return 0;
}

