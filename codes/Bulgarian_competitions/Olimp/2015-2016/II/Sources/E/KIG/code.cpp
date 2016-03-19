#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
char a[10001];
char b[10001];
long long w[101];
int main()
{
long long x,y,z,s=1,br=0,e;
char mnb;
cin>>a;
y=strlen(a);
e=y-1;
for(x=0;x<e;x++)
{
    if(a[x]!=0)
    {z=x-1;
    if(a[x]==a[z]){s++;}
    else
    {if(s>0 && s<10){br=br+2;}
    else
    if (s>0 && s>=10){br=br+3;}
    else 
    {br++;}
    s=0;}}
}
mnb=a[0];
for(x=0;x<e;x++)
{
    if(a[x]!=mnb){mnb=a[x];}
}
z=y-br;
if(mnb==a[0] && y>3){z--;}
else
if(mnb==a[0] && y<=4 && y>2){z--;}
cout<<z<<endl;
return 0;}