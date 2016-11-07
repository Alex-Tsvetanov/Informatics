#include<iostream>
using namespace std;
long long b[400];
int main ()
{
    int l,h,n;
    cin>>l>>h>>n;
    int s1,a[n];
    s1=l*h;
    int k=n*4;
    for (int i=0;i<k;i++)
    {
        cin>>b[i];
    }
    int m;
    m=b[k-1]*b[k-2];
    m=m*b[3];
    cout<<s1-m<<endl;
    return 0;    
}