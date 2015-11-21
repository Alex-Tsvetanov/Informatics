#include<iostream>
#include<cstring>
#include<algorithm>
#include<cmath>
#include<cstdlib>
#include<time.h>
#include<stdio.h>
using namespace std;
char b[50];
int a[51],c[51],rez[51];
long long l,naum;
int cmp1(int x,int y)
{
    return x<y;
}
int cmp2(int x,int y)
{
    return x>y;
}
int main()
{
    cin>>b;
    l=strlen(b);
    for(int i=0; i<l; i++)
    {
        a[i+1]=b[i]-'0';
        c[i+1]=b[i]-'0';
        //cout<<b[i]-'0';
    }
    sort(a+1,a+l+1,cmp1);
    sort(c+1,c+l+1,cmp2);
    int d=1;
    while(a[d]==0)
        d++;
    swap(a[1],a[d]);
    /**for(int i=1;i<=l;i++)
        cout<<a[i];
        cout<<endl;
        for(int i=1;i<=l;i++)
        cout<<c[i];
        cout<<endl;*/
    for(int i=l; i>0; i--)
    {
        rez[i]=(a[i]+c[i]+naum)%10;
        naum=(a[i]+c[i]+naum)/10;
    }
    int i;
    if(naum)
    {
        i=0;
        rez[0]=naum;
    }
    else
        i=1;
    for( ; i<=l; i++)
        cout<<rez[i];
    return 0;
}
