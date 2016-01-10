#include<iostream>
using namespace std;
int main(){
long long sf,lvf,stf,f,s,t,a,b,plosht,putif,putis,putit,broif,brois,broit,ksf,kss,kst;
broif=0;
brois=0;
broit=0;
long long ss,lvs,sts;
long long st,lvt,stt;
f=0;
s=0;
t=0;
cin>>sf>>lvf>>stf;
cin>>ss>>lvs>>sts;
cin>>st>>lvt>>stt;
cin>>a>>b;
plosht=a*b;
f=lvf*100+stf;
s=lvs*100+sts;
t=lvt*100+stt;
broif=plosht/sf;
brois=plosht/ss;
broit=plosht/st;
if(plosht%sf!=0){
   broif=broif+1;
}
if(plosht%ss!=0){
    brois=brois+1;

if(plosht%st!=0){
    broit=broit+1;
}
}
f=f*broif;
s=s*brois;
t=t*broit;
if(f<s && f<t){

    cout<<f;

}
if(s<f && s<t){
     cout<<s;

}
if(t<s && t<f){
  cout<<t;

}

return 0;
}
