#include<iostream>
using namespace std;
int main () {
int s1,lv1,st1,a,b,s2,lv2,st2,s3,lv3,st3,plosht,mys,mylv,myst,kolko;
long long cena1,cena2,cena3;
cin>>s1>>lv1>>st1;
cin>>s2>>lv2>>st2;
cin>>s3>>lv3>>st3;
cin>>a>>b;
plosht=a*b*4;
cena1=(lv1*100+st1)/s1;
cena2=(lv2*100+st2)/s2;
cena2=(lv3*100+st3)/s3;
if(cena1<cena2 and cena1<cena3){
    mys=s1;
    mylv=lv1;
    myst=st1;
}
if(cena3<cena2 and cena3<cena1){
    mys=s3;
    mylv=lv3;
    myst=st3;
}
if(cena2<cena1 and cena2<cena3){
    mys=s2;
    mylv=lv2;
    myst=st2;
}
while(0>plosht-mys){
    plosht=plosht-mys;
    kolko=kolko+1;
}
mylv=mylv*kolko;
myst=myst*kolko;
if(plosht-s1<plosht-s2 and plosht-s1<plosht-s3){
    mylv=mylv+lv1;
    myst=myst+st1;
}
if(plosht-s2<plosht-s1 and plosht-s2<plosht-s3){
    mylv=mylv+lv2;
    myst=myst+st2;
}
if(plosht-s3<plosht-s2 and plosht-s3<plosht-s1){
    mylv=mylv+lv3;
    myst=myst+st3;
}
mylv=mylv+myst/100;
myst=myst%100;
cout<<mylv<<" "<<myst;
cout<<endl;
return 0;
}
