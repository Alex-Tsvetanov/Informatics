#include<iostream>
using namespace std;
int main(){
int t , t1 , t2 , t3,n,p;
t=0;
char str[7];
cin >> str;
t1=str[0]-'0';
t2=str[2]-'0';
t3=str[4]-'0';
n=str[6]-'0';
p=0;
if(t==0){
 t=t1+t2+t3;
 for(int i=3;i<=n;i++){
   p=t2;
   t1=t2;
   t2=t3;
   t3=t;
  t=t1+t2+t3;
 }
cout << t;
}

return 0;
}
