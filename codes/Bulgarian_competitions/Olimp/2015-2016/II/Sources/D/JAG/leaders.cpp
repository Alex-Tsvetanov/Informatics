#include <iostream>
using namespace std;
int main()
{
int nqkbr,zam,drzam,segch,i=0,n,k=0,dvbr,br=0;
int dvch[1000];
int vuvch[1000];
int drdvch[1000];
cin>>n;
do
{
i++;
cin>>vuvch[i];
}
while(i<n);
drzam=i;
i=0;
k=0;
do
{
k=i;
zam=0;
dvbr=0;
do
{
k++;
if(vuvch[i]>dvch[k]) dvbr++;
else break;
}
while(k<(n-1));
k=i+1;
do
{
if(vuvch[i]>=dvch[k]) zam++;
k++;
}
while(k<(n-1));
i++;
if(dvbr==zam) cout<<vuvch[i]<<" ";
}
while(i<n);
return 0;
}
