#include<iostream>
using namespace std;
int main ()
{
long int a,b,c,x;
cin>>a>>b>>c;
if (a>b){x>a;x=a;a=b;}
if (b>c){x>b;x=b;b=c;}
if (c>a){x>c;x=c;c=a;}

return 0;
}
