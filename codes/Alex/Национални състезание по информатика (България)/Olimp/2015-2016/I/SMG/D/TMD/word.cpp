#include<iostream>
using namespace std;
long long i,i2,sr[26];
char izr[100000],pr;
int main(){
cin>>izr;
for(i=0;izr[i]!='#';i++){
if(izr[i]>64 and izr[i]<91){
sr[izr[i]-65]++;
}
if(izr[i]>96 and izr[i]<123){
sr[izr[i]-97]++;
}
}
for(i=100000;i>0;i--){
for(i2=0;i2<26;i2++){
if(sr[i2]==i){
pr=i2+65;
cout<<pr;
}
}
}
cout<<endl;
return 0;
}
