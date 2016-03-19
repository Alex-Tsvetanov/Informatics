#include<iostream>
using namespace std;
int main()
{  
    long long n,i=0,l=0,n1=0,br=0,br1=1;
    char a[1000000];
    
    cin>>a;
    i=strlen(a);
    if(i<=2)cout<<0;
    else for(int k=1;k<i;k++)
    if(a[k]!=a[k-1]&&l==0)br1++;
    else if(a[k]==a[k-1]&&l==0){l=1;br1++;}
    else if(a[k]==a[k-1]&&l==1)l=1;
    else  if(a[k]!=a[k-1]&&l==1)l=0; 
    cout<<i-br1-1;
    return 0;
}
