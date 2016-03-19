#include<iostream>
using namespace std;
int main(){

int p2=0,s3,p1=0,s2,s1=1,z,n,kp=0;
cin>>n;
s2=n;
s3=s2;
for(;;){
    for(;;){
      if(s2==0 || s2==-1)break;
      s2--;
      if(s1>=2)p1=s2*(s1-1);
      if(s2>=2)p2=s1*(s2-1);
      z=(p1+p2)+((s1+s2)*2);
      if(z==n && s1<s2)kp++;
      }
  if(s1==n+1)break;
  s2=s3-1;
  s1++;
  s3--;
  p1=0;
  p2=0;
  }
cout<<kp<<endl;

return 0;
}
