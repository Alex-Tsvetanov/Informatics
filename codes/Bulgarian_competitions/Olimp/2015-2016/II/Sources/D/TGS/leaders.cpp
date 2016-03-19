#include<iostream>
#define maxn 1000000
using namespace std;
int a[maxn]={0};
int n;
int maxa=0;
int main()
{
    cin>>n;
    for(int i=0;i<n;i++)
        cin>>a[i];
    for(int i=0;i<n;i++)
    {
        maxa=0;
        for(int j=i+1;j<n;j++)
            if(a[i]>=a[j])maxa=a[i];
        if(maxa == a[i])cout<<a[i]<<" ";
        maxa=0;
    }
    cout<<endl;
    return 0;
}
