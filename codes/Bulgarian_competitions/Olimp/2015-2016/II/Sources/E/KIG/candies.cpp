#include<iostream>
#include<string.h>
#include<math.h>
using namespace std;
int main()
{
long long a,b,c,s=0,br=0,i=1;
cin>>a>>b>>c;
while(s==0)
{
    if(i==1){if(a==0)s++;
    else {a--;br++;i=2;}}
    else
    if(i==2){if(b==0)s++;
    else {b--;br++;i=3;}}
    else
    if(i==3){if(c==0)s++;
    else {c--;br++;i=4;}}
    else
    if(i==4){if(b==0){s++;}
    else {b--;br++;i=1;}}
}
cout<<br<<endl;
return 0;}