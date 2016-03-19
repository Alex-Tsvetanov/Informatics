#include<iostream>
#include<cstring>
using namespace std;
int used[100000000];
long long a[1000000],b[1000000];
int ans=3,lamp=0;
long long mn=999999999;
long long mx=0;
long long n,m,p;
void ppp (long long d)
{
    if (ans==1) {return;}
    if (d==m)
    {
        lamp=0;
        if (mn%6!=0) {mn=(mn/6+1)*6;}
        for (int i=mn; i<=mx; i=i+6)
        {
            if (used[i]!=0 || used[i+1]!=0) {ans=2; lamp=1; break;}
        }
        if (lamp==0) {ans=1;}
    }
    for (int i=a[d]; i<=b[d]; i++)
    {
        if (used[i]<p/2) {used[i]++; ppp(d+1); used[i]--;}
    }
}

int main ()
{

    cin>>n>>m>>p;
    //memset (used, 0, sizeof(used));
    for (int i=0; i<m; i++)
    {
        cin>>a[i]>>b[i];
        if (a[i]>mx) {mx=a[i];}
        if (a[i]<mn) {mn=a[i];}
        if (b[i]>mx) {mx=b[i];}
        if (b[i]<mn) {mn=b[i];}
    }
    ppp(0);
    if (ans==3) {cout<<"IMPOSSIBLE"<<endl;}
    if (ans==2) {cout<<"MIXED"<<endl;}
    if (ans==1) {cout<<"OK"<<endl;}
    return 0;
}
