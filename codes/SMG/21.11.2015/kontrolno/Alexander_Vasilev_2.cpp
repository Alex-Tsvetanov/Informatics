#include<iostream>
using namespace std;
int main(){
char b[100],a[100],c[100];long long sbor[100],k=0;
bool f=true;
cin>>b;
long long n=strlen(b);
sort(b+0,b+n);
for(long long i=0;i<n;i++){
a[i]=b[i];
c[i]=b[n-i-1];
}
long long naum=0;
for(long long i=0;i<n;i++){
sbor[i]=(a[i]+c[i]-'0'-'0'+naum)%10;
naum=(a[i]+c[i]-'0'-'0'+naum)/10;
}
if(naum==1){
    sbor[n]=1;
}
for(long long i=(naum+n-1);i>=0;i=i-1){
cout<<sbor[i];
}
return 0;
}
