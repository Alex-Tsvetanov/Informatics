#include<iostream>
using namespace std;
int main ()

{
    long long n,br=0,a,b;
    cin>>n;
    if (n-4!=0&&(n-4)%3==0) br=br+1;
    if (n%4==0) br=br+1;
    a=5;
    b=9;
    while (a<n);
    {
    if ((n-16)%a==0) br=br+1;
    a=a+2;
    }
    while (a<n);
    {
    if ((n-16)%b==0) br=br+1;
    b=b+2;
    }
    cout<<br<<endl;
    return 0;
}