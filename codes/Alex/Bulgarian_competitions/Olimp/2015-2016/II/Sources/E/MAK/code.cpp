#include<iostream>
using namespace std;
int main ()
{
char b[1000000];
long long br=0,br1=0,i=0,rez;
for(i=0;i<1000000;i++)
{
cin>>b[i];
if(b[i]=='.')break;
br++;
}
for(i=0;i<br;i++)
{
if(b[i]=='.')break;
if(b[i]!=b[i+1])br1++;
  else
  {
   for(i=i+1;i<br;i++)
   {
    if(b[i]!=b[i+1])break;
   }
   br1=br1+2;
  }
}
rez=br-br1;
cout<<rez<<endl;
return 0;
}