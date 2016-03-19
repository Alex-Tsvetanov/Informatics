# include <iostream>
using namespace std;
long long n,a[1000000],b[1000000],maxs=0,p=1;
int main()
{

cin>>n;
long long i;
for(i=1;i<=n;i++)
cin>>a[i];
maxs=a[n];
b[0]=a[n];
for(i=n-1;i>0;i--)
{
    if(a[i]>=maxs)
    {
        maxs=a[i];
        b[p]=a[i];
        p++;
    }

}
for(i=p-1;i>0;i--)
    cout<<b[i]<<" ";
cout<<b[0]<<endl;

return 0;
}
