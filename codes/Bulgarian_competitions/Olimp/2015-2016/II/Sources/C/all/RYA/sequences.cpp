#include <iostream>
using namespace std;
int p,s,n;
long long br=0;
void find_seq(int a[],int sum,int i)
{
    if(sum==s)return;
    int k;
    //for(int k=0;k<n;k++)cout<<a[k]<<" ";
    //cout<<endl;
    br++;
    for(k=i;k<n;k++)
    {
        if(a[k]<p-1)
        {
            a[k]++;
            sum++;
            find_seq(a,sum,k);
            a[k]--;
            sum--;
        }
    }
}
int main( )
{
    cin>>p>>n>>s;
    int a[20]={0};
    find_seq(a,0,0);
    cout<<br<<endl;
}
