#include<iostream>
#include<algorithm>
using namespace std;
int main (){
long long broi=0,purvo=0,vtoro=0,treto=0,broyach=0,otgovor=0;
long long tsifra=0,broyach2=0;
cin>>broi>>purvo>>vtoro>>treto;
broi=broi-1;
long long deliteli[100];
for(broyach=0;broyach<100;broyach++){
    deliteli[broyach]=0;
}
for(broyach=purvo;broyach<100;broyach++){
        if(broyach%purvo==0){
    deliteli[broyach]=broyach;
        }
}
for(broyach=vtoro;broyach<100;broyach++){
        if(broyach%vtoro==0){
    deliteli[broyach]=broyach;
        }
}
for(broyach=treto;broyach<100;broyach++){
        if(broyach%treto==0){
    deliteli[broyach]=broyach;
        }
}
if(broi==1){
  for(broyach=10;broyach<100;broyach++){
    if(deliteli[broyach]==broyach){
     otgovor++;
    }
  }
  cout<<otgovor;
}else{
if(broi==2){
   for(broyach=10;broyach<100;broyach++){
 if(deliteli[broyach]==broyach){
        tsifra=broyach%10;

       for(broyach2=10;broyach2<100;broyach2++){
        if(deliteli[broyach2]/10==tsifra){
       otgovor++;
        }
       }
 }
   }
   cout<<otgovor;
}else{
if(broi==2){
   for(broyach=10;broyach<100;broyach++){
 if(deliteli[broyach]==broyach){
        tsifra=broyach%10;

       for(broyach2=10;broyach2<100;broyach2++){
        if(deliteli[broyach2]/10==tsifra){
       otgovor++;
        }
       }
 }
   }
   cout<<otgovor<<endl;
}
}
}
return 0;
}
