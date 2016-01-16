#include<iostream>
using namespace std;
long long x,t=999999999999999,p,prosti4isla[10000000][2],f=0,nmo=1,daizveda[100000000][2],l=0;
bool a,b=true;
int main(){
cin>>x;
for(long long i=2;i<=x;i=i+2){
   // cout<<i<<"\n";
        a=false;
p=0;
if(x%i==0){
        //cout<<"vlizam";
  prosti4isla[f][0]=i;
  f++;
}
while(x%i==0){
prosti4isla[f-1][1]++;
//cout<<prosti4isla[f-1][1]<<" "<<f<<" ";
x=x/i;
p=p+1;
a=true;
}
if(p!=0 and t<999999999999999){
        long long o;
        if(p<t){
    for(long long i=1;i<=p;i++){
        if(p%i==0 and t%i==0){
           o=i;
        }
    }
        }else{
          for(long long i=1;i<=t;i++){
        if(p%i==0 and t%i==0){
           o=i;
        }
    }

        }
t=o;
//cout<<t<<"\n";
}else{
if(t==999999999999999 and p!=0){
       // cout<<t<<" ";
        b=false;
    t=p;
//cout<<t<<"\n";
}
}
/*if(t>p and a){
t=p;
b=false;
}*/
if(i==2){
    i=1;
}
}
//cout<<t;
if(t==1){
    cout<<"0\n";
}else{
//cout<<t<<" ";
//cout<<prosti4isla[0][1];
for(long long i=0;i<f;i++){
  //  cout<<"ZA : "<<prosti4isla[r][1]<<" ";
        for(long long r=0;r<prosti4isla[i][1]/t;r++){
nmo=nmo*prosti4isla[i][0];
//cout<<nmo<<"\n";
        }
}
if(b==false){
for(long long i=2;i<=t;i++){
    if(t%i==0){
            daizveda[l][1]=i;
            daizveda[l][0]=1;
    for(long long r=0;r<t/i;r++){
        daizveda[l][0]=daizveda[l][0]*nmo;
    }
            l++;
    }
}
}
//cout<<l<<"\n";
cout<<l<<"\n";
if(l!=0){
    for(long long i=0;i<l;i++){
        cout<<daizveda[i][0]<<" "<<daizveda[i][1];
    cout<<"\n";
}
}
}
return 0;
}
