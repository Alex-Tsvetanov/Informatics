#include <iostream>
using namespace std;
int main () {
long long s1, s2, s3,st1,st2,st3,lv1,lv2,lv3,a,b,d;
cin>>s1>>s2>>s3>>st1>>st2>>st3>>lv1>>lv2>>lv3>>a>>b;
d=a*b;
if((d*4/s1+1)*(lv1*100+st1)>(d*4/s2+1)*(lv2*100+st2) and (d*4/s1+1)*(lv1*100+st1)>(d*4/s3+1)*(lv3*100+st3)){
cout<<(d*4/s1+1)*st1-(d*4/s1)*st1/100*100<<" "<<(d*4/s1+1)*lv1+(d*4/s1)*st1/100;
}
if((d*4/s2+1)*(lv2*100+st2)>(d*4/s1+1)*(lv1*100+st1) and (d*4/s2+1)*(lv2*100+st2)>(d*4/s3)*(lv3*100+st3)){
cout<<(d*4/s2+1)*st2-(d*4/s2)*st2/100*100<<" "<<(d*4/s2+1)*lv2+(d*4/s2)*st2/100;
}
if((d*4/s3+1)*(lv3*100+st3)>(d*4/s2)*(lv2*100+st2) and (d*4/s3+1)*(lv3*100+st3)>(d*4/s1)*(lv1*100+st1)){
cout<<(d*4/s3+1)*st3-(d*4/s3)*st3/100*100<<" "<<(d*4/s3+1)*lv3+(d*4/s3)*st3/100;
}
return 0;
}
