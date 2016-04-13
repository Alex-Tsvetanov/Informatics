#include<iostream>
using namespace std;
int n, m;
int a[40000];
int k=1;
int main()
{
    cin>>n>>m;
    for(int i=0;i<n*m;i++)
        cin>>a[i];
    for(int i=1;i<n*m;i++)
        if(a[i]==0&&a[i-1]==1)k++;
    cout<<k<<endl;
    return 0;
}
