#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main()
{
    char a[52],b[52],c[52];
    cin>>b;
    strcpy(a,b);
    sort(a,a+strlen(a));
    for(int i=0;i<strlen(b);i++)
    {
        c[i]=a[strlen(b)-i-1];
        cout<<a[strlen(b)-i-1]<<"\n";
    }
    c[strlen(b)]=0;
    return 0;
}
