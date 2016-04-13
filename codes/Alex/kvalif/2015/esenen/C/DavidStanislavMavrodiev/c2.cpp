#include<iostream>
using namespace std;
long long chisla[20][10000],razmerNaCifrite[10000];
bool maxGenerirani=false,neMojeOtTovaChislo[10000],neMojeSega=false;
int main (){
long long n,d1,d2,d3,brGeneriraniChisla=0,i,koef=1,segashnoChislo=0,j,f;
cin>>n>>d1>>d2>>d3;
for(koef=1;d1*koef<100;koef++){
  segashnoChislo=d1*koef;
  chisla[1][brGeneriraniChisla]=segashnoChislo%10;
  segashnoChislo=segashnoChislo/10;
  chisla[0][brGeneriraniChisla]=segashnoChislo%10;
  razmerNaCifrite[brGeneriraniChisla]=2;
  brGeneriraniChisla++;
}
for(koef=1;d2*koef<100;koef++){
  segashnoChislo=d2*koef;
  chisla[1][brGeneriraniChisla]=segashnoChislo%10;
  segashnoChislo=segashnoChislo/10;
  chisla[0][brGeneriraniChisla]=segashnoChislo%10;
  razmerNaCifrite[brGeneriraniChisla]=2;
  brGeneriraniChisla++;
}
for(koef=1;d3*koef<100;koef++){
  segashnoChislo=d3*koef;
  chisla[1][brGeneriraniChisla]=segashnoChislo%10;
  segashnoChislo=segashnoChislo/10;
  chisla[0][brGeneriraniChisla]=segashnoChislo%10;
  razmerNaCifrite[brGeneriraniChisla]=2;
  brGeneriraniChisla++;
}
     for(i=0;i<brGeneriraniChisla;i++){
       neMojeSega=neMojeOtTovaChislo[i];
       for(j=1;j<=9 and razmerNaCifrite[i]!=n and !neMojeSega;j++){
         segashnoChislo=chisla[razmerNaCifrite[i]-1][i]*10+j;
         if(segashnoChislo%d1==0 or segashnoChislo%d2==0 or segashnoChislo%d3==0){
           for(f=0;f<razmerNaCifrite[i];f++){
             chisla[f][brGeneriraniChisla]=chisla[f][i];
             razmerNaCifrite[brGeneriraniChisla]++;
           }
           chisla[razmerNaCifrite[brGeneriraniChisla]][brGeneriraniChisla]=j;
           razmerNaCifrite[brGeneriraniChisla]++;
           brGeneriraniChisla++;
         }else{
             neMojeOtTovaChislo[i]=true;
         }
       }
     }
     long long answ=0;
for(i=0;i<brGeneriraniChisla;i++){
   if(razmerNaCifrite[i]==n and !neMojeOtTovaChislo[i]){
     answ++;
   }
   if(razmerNaCifrite[i]==n-1 and chisla[razmerNaCifrite[i]-1][i]!=0){
     if((chisla[razmerNaCifrite[i]-1][i]*10)%d1==0 or (chisla[razmerNaCifrite[i]-1][i]*10)%d2==0 or (chisla[razmerNaCifrite[i]-1][i]*10)%d3==0){
       answ++;
     }
   }
}
cout<<answ<<endl;
return 0;
}
