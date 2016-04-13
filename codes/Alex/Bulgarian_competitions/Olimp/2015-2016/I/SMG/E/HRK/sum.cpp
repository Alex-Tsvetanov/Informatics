#include<iostream>
using namespace std;
int main(){
long long a,b,vzetoa,vzetob,greshno,verno,desa,desb;
char znak;
cin>>a;
cin>>znak;
cin>>b;
verno=a+b;
greshno=0;
greshno=a+b;
vzetoa=a%100;
vzetob=b%100;

    vzetoa=vzetoa%10;


    vzetob=vzetob%10;

if(vzetoa+vzetob>=10){
    greshno=greshno-10;
}
desa=(a%100)-vzetoa;
desb=(a%100)-vzetob;
vzetoa=vzetoa-desa;
vzetob=vzetob-desb;
if(desa+desb>=10){
    greshno=greshno-100;
}
cout<<greshno<<endl;
cout<<verno;
return 0;
}
