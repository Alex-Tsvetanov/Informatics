#include<iostream>
#include<algorithm>
#define MAXN 1000000
using namespace std;
long long int a[MAXN],c[MAXN];
int l;
void find_max(long long int k1,long long int k2)
{
l=1;
long long int i=0,j=0,m=0;
int bz=0;
m=a[k1];
for(i=k1+1;i<k2;i++)
if(a[i]>m){l=0;break;}
}
int main()
{
    long long int n,i,z,bm=0;
    cin>>n;
    for(i=0;i<n;i++)
    cin>>a[i];
    for(i=0;i<n-1;i++)
    {
    find_max(i,n);
    if(l==1){c[bm]=a[i];bm++;}
}
bm++;
c[bm]=a[n-1];
if(bm==1)cout<<c[0]<<endl;
else
{
    for(i=0;i<bm-1;i++)
    cout<<c[i]<<" ";
    cout<<c[bm]<<endl;
}
return 0;

}
