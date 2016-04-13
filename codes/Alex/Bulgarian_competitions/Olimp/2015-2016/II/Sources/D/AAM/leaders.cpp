#include<iostream>
using namespace std;
long long br[9],mas1[60001],mas2[60001],mas3[60001];
int main ()
{
long long n,a,b,key=1;

br[1]=0;
br[2]=0;
br[3]=0;
br[4]=0;
br[5]=0;
br[6]=0;
br[7]=0;
br[8]=0;
br[9]=0;
cin>>n;
for(int i=0;i<n;i++)
{
cin>>a;
if(i==80000)key=2;
if(i==160000)key=3;;

if(b>a && key==1){mas1[br[1]]=b;br[1]++;}
if(b>a && key==2){mas2[br[2]]=b;br[2]++;}
if(b>a && key==3){mas3[br[3]]=b;br[3]++;}


b=a;
}

for(int i=0;i<br[1];i++)
{
cout<<mas1[i]<<" ";
}
for(int i=0;i<br[2];i++)
{
cout<<mas2[i]<<" ";
}
for(int i=0;i<br[3];i++)
{
cout<<mas3[i]<<" ";
}

cout<<a<<endl;

return 0;

}

