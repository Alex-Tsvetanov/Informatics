#include<iostream>
using namespace std;
int key=0,j,i,n,a[1000000],mas[1000000],sn;
int main ()
{
cin>>n;
for(i=0;i<n;i++) cin>>a[i];
for(i=0;i<n-1;i++)
{
for(j=i+1;j<n;j++)
{
if(a[i]>=a[j]) key=1;
else {key=0;break;}
}
if(key==1) {mas[sn]=a[i];sn++;key=0;}
}
mas[sn]=a[n-1];
sn++;
for(i=0;i<sn;i++) cout<<mas[i]<<" ";
cout<<endl;
return 0;
}
/*

7
50 1 40 2 3 4 30
*/
