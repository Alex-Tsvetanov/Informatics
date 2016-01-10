#include<iostream>
#include<cstring>
using namespace std;
string s,s1,s2;
int d,d1,i;
char otg[61];
int main () {
cin>>s;
cin>>s1;
d=s.size();
d1=s1.size();
if(d1>d) {
 for(i=1;i<=d1-d;i++) {
  s2=s2+'0';
 }
 s2=s2+s;
 s=s2;
 d=d1;
}
if(d1<d) {
 for(i=1;i<=d-d1;i++) {
  s2=s2+'0';
 }
 s2=s2+s1;
 s1=s2;
 d1=d;
}
for(i=d;i>=1;i--) {
 if(otg[i]=='?' || s1[i]=='?' || s[i]=='?') {
  otg[i-1]='?';
 }
 else {
  otg[i-1]=(((s1[i]-2*'0'+s[i])%2+otg[i]-'0'))%2+'0';
  otg[i]=otg[i]%2;
 }
}
for(i=0;i<=d;i++) {
if(i==0 && otg[0]!=0) {
 cout<<otg[0];
}
 if(i!=0) {
  cout<<otg[i];
 }
}
return 0;
}

