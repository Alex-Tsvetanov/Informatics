#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
char niz[3000];
cin>>niz;
long long duljina=0,broyach=0,broyach2=1,broyach3=0,broyach4=0,granitsa=0;
duljina=strlen(niz);
long long prosti[3000];
for(broyach=0;broyach<duljina;broyach++){
    prosti[broyach]=0;
}
long long spets=0;
prosti[spets]=2;
spets++;

for(broyach=3;spets<=duljina;broyach++){

   for(broyach3=2;broyach3<=broyach/2+1;broyach3++){
    if(broyach%broyach3==0){
        goto krai;
    }else{
        broyach4++;
    }
   }
   if(broyach4==broyach/2){
    prosti[spets]=broyach;
    spets++;

   }
   krai:;
broyach4=0;
}
long long otg=0;
for(broyach=0;broyach<duljina;broyach++){
   otg+=(niz[broyach]-48)*prosti[broyach];

}
cout<<otg<<endl;
return 0;
}
