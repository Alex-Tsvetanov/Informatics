#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long long a,b,c,sum,iz=3;
    cin>>a>>b>>c;
    sum=a+b+c;
    a--;b--;c--;
    while(a!=0||b!=0||c!=0)
    {
        if(b==0) {cout<<iz<<endl;break;} b--;iz++;
        if(a==0) {cout<<iz<<endl;break;} a--;iz++;
        if(b==0) {cout<<iz<<endl;break;} b--;iz++;
        if(c==0) {cout<<iz<<endl;break;} c--;iz++;
    }
    return 0;
}
