#include<iostream>
#include<stdio.h>
using namespace std;
int pow(int,int,int);
int main(){
int p=0,n=0,s=0;
cin>>p>>n>>s;
cout<<pow(p,n,s);
return 0;
}
int pow(int a,int b,int e){
    int c=1;
    int d=a;
    int g=0;
for(int i=0;i<b;i++){
c*=d;
}
if((a-1)*b>=e){
        g=(a-1)*b-e+1;
if(g!=1){
c-=g*b+g/2+g*(g+1)/8;
}else{
c--;
}
}
return c;
}
