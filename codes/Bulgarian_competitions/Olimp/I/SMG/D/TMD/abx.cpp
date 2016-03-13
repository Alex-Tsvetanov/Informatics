#include<iostream>
using namespace std;
long long a,b,c,i,r=3,p=0;
char uravnenie[20];
int main(){
cin>>uravnenie;
for(i=0;uravnenie[i]=='0' or uravnenie[i]=='1' or uravnenie[i]=='2' or uravnenie[i]=='3' or uravnenie[i]=='4' or uravnenie[i]=='5' or uravnenie[i]=='6' or uravnenie[i]=='7' or uravnenie[i]=='8' or uravnenie[i]=='9' or uravnenie[i]=='+' or uravnenie[i]=='=' or uravnenie[i]=='X';i++){
if(uravnenie[i]=='+'){
p=1;
}
if(uravnenie[i]=='='){
p=2;
}
if(uravnenie[i]=='X'){
p++;
r=p;
}
if(p==0 and uravnenie[i]!='X' and uravnenie[i]!='+' and uravnenie[i]!='='){
a=a*10+uravnenie[i]-'0';
cout<<uravnenie[i]<<"a";
}
if(p==1 and uravnenie[i]!='+' and uravnenie[i]!='=' and uravnenie[i]!='X'){
b=b*10+uravnenie[i]-'0';
cout<<uravnenie[i]<<"b";
}
if(p==2 and uravnenie[i]!='+' and uravnenie[i]!='=' and uravnenie[i]!='X'){
c=c*10+uravnenie[i]-'0';
cout<<uravnenie[i]<<"c";
}
}
if(r==0){
cout<<c-b;
}else{
cout<<c-a;
}
return 0;
}
