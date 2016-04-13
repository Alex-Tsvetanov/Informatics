#include<iostream>
using namespace std;
int main(){
char a[100],b[100];
long long c=0,d=(24*60);
cin>>a>>b;
c=((a[0]-'0')*10+(a[1]-'0'))*60+(a[3]-'0')*10+(a[4]-'0');
d=d+((b[0]-'0')*10+(b[1]-'0'))*60+(b[3]-'0')*10+(b[4]-'0');
if(d-c>1440){
    d=d-(24*60);
}
if(d-c==1440){
    cout<<"00:00";
}else{
long long kolko=(d-c);
if(kolko/60<=9){
    cout<<0<<kolko/60<<":";
}else{
cout<<kolko/60<<":";
}
if(kolko%60<=9){
    cout<<0<<kolko%60;
}else{
cout<<kolko%60;
}
}
return 0;
}
