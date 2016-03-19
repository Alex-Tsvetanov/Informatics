#include<iostream>
#include<stdio.h>
#include<cmath>
using namespace std;
int chisla[100][100];
int main(){
    bool nech=0;
int broi,kraen=0,zam=0;

scanf("%d",&broi);
kraen=sqrt(broi*2);
zam=kraen*(kraen+1)/2;
if(zam+1<broi){
    kraen++;
    nech=true;
}
if(broi==2){
        kraen--;
printf("%d\n",kraen);

}else{
printf("%d\n",kraen);
}
int segashen=1,stupki=0,haide=0;

int br=0;
if(broi<=500){


if(nech==false){
  for(int i=0;i<broi;i++){
    for(int j=0;j<kraen;j++){
     chisla[j][i]=segashen;
     br++;
     if(kraen-stupki==br){
            haide++;
     if(haide-1==stupki){
            haide=0;
        stupki++;
     }
        br=0;
        segashen++;
        if(segashen>broi){
            goto krai;
        }
     }
    }
  }
}else{
  for(int i=0;i<broi;i++){
    for(int j=0;j<kraen;j++){
     chisla[j][i]=segashen;
     br++;
     if(kraen-stupki==br){
               haide++;
     if(haide-1==stupki){
            haide=0;
        stupki++;
     }
        br=0;
        segashen++;
        if(segashen>broi){
            goto krai;
        }
     }
    }
  }
}
krai:;
for(int i=0;i<kraen;i++){
    for(int j=0;j<broi;j++){
if(chisla[i][j]!=0){
        cout<<chisla[i][j]<<" ";
}
    }
    cout<<endl;
}
}

return 0;
}
