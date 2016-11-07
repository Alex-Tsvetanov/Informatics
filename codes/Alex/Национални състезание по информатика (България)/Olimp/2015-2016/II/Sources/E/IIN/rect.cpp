#include<iostream>
#include<cmath>
#include<cstring>
using namespace std;
int main()
{
    long long k,a=1,b,br=0;
    cin>>k;
    b=k/2-1;
    while(b!=0)
    {
    if((b*(a+1)+a*(b+1))==k) br++;
    a++;
    if(a>b){b--;a=1;}
    }
    cout<<br<<endl;
    return 0;
}
