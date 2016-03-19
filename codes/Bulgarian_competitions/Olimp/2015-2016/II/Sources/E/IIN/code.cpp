#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    char a[1000000];
    long long b,c;
    cin.getline(a,1000000,'.');
    b=strlen(a);
    if(b==1) c=1;
    if(b<=9&&b>=2) c=2;
    if(b<=99&&b>=10) c=3;
    if(b<=999&&b>=100) c=4;
    if(b<=9999&&b>=1000) c=5;
    if(b<=99999&&b>=10000) c=6;
    if(b<=999999&&b>=100000) c=7;
    cout<<b-c<<endl;
    return 0;
}
