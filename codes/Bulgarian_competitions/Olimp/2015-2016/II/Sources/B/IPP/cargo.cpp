#include <iostream>
using namespace std;
int main()
{
    int N,M,P;
    int r,t,y=0,z=0;
    int a[100000];
    cin>>N>>M>>P;
    for(int i=0;i<M*2;i++)
    {
        cin>>a[i];
    }
    for(int i=1;i<M*2;i++){r=a[0];if(a[i]==r)y=1;else y=0;}
    for(int i=1;i<M*2;i++){t=a[0];if(a[i]==t)z=1;else z=0;}
    if(y+z==2) {cout<<"IMPOSSIBLE"<<endl;return 0;}
    for(int i=0;i<M*2;i++)
    if(a[i]>N) {cout<<"IMPOSSIBLE"<<endl;return 0;}
    for(int i=0;i<M*2;i++)
    if(a[i]<=N && (a[i]==6 ||a[i]==7)) {cout<<"MIXED"<<endl;return 0;}
    for(int i=0;i<M*2;i++)
    if(a[i]<=N && (a[i]!=6 ||a[i]!=7)) {cout<<"OK"<<endl;return 0;}
    return 0;
}