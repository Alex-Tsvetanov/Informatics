#include<iostream>
using namespace std;
long long f(long long n){
     long long answ = 1;
     for(long long i = 1;i<=n;i++){
       answ = answ * i;
     }
     return answ;
}
int main(){
long long a,b,c,answ=1;
cin>>a>>b>>c;
answ = ((a-1)*b)*(b-1);
long long koef=0;
if(a>=b and c>b){
  if(a<c){
    koef = a;
  }else{
      koef = c;
  }
  answ = answ + (f(b)*koef);
}
for(int i = 0;i < a;i++){
    if(i*b<c){
      answ++;
    }
}
cout<<answ<<endl;
return 0;
}
