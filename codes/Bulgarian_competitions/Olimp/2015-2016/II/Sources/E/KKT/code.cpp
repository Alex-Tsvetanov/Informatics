#include<iostream>
using namespace std;
int main(){

char b,pb='8';
int bb=0,km2=0,f2=1,f=0,bk=0,kpp=0;
for(;;){
  cin.get(b);
  if(b=='.')break;
  else if(b==pb){
    if(f2==1) {
      bk-=2;
      km2++;
      }
    f2=0;
    }
  else {
  f2=1;
  }
  if(b!=pb && pb!='8')bk--;
  bb++;
  pb=b;
  }
for(;;){
  if(km2==0)break;
  bk+=4;
  km2--;
  }
bk+=bb;
if(bk>bb)swap(bk,bb);
if(b=='x' && pb=='x')cout<<"4"<<endl;
cout<<bb-bk<<endl;

return 0;
}
