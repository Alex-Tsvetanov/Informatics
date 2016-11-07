#include <iostream>
#include <string>
using namespace std;

string s;
int br,k,p,br2,br1,i;

int main(){
cin>>s;
 while(s[i]!='.'){
 i++;
 br++;
   }
   k=br;
   i=0;
  while(s[i]!='.'){
      if(s[i]==s[i+1]) br1++;
       else{
    if(br1>0){
     br1++;
     p=br1;
       while(br1!=0){br2++;br1/=10;}
       br=(br-p)+(br2+1);

    }
       }
       i++;
     }
 cout<<k-br<<endl;
return 0;
 }
