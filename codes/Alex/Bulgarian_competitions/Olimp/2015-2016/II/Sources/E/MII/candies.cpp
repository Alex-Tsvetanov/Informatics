#include <iostream>
using namespace std;

int br,A,B,C;

int main(){
cin>>A>>B>>C;
 while(1){
  if(A>0) {A--;br++;}
   else break;
  if(B>0) {B--;br++;}
    else break;
  if(C>0) {C--;br++;}
   else break;
  if(B>0) {B--;br++;}
   else break;
 }
 cout<<br<<endl;
return 0;
}
