#include<iostream>
using namespace std;
int main(){
    char simvol='\0',spr;
    long long vhod,subrani=0,izhod=0;
    for(vhod=0;simvol!='.' and vhod<=1000000;vhod++){
        spr=simvol;
        cin>>simvol;
        if(simvol==spr){
            subrani++;
            if(subrani==10){
                izhod++;
            }
            if(subrani==100){
                izhod++;
            }
            if(subrani==1000){
                izhod++;
            }
            if(subrani==10000){
                izhod++;
            }
            if(subrani==100000){
                izhod++;
            }
            if(subrani==1000000){
                izhod++;
            }
        }else{
            if(subrani>0){
                izhod++;
            }
            izhod=izhod+1;
            subrani=0;
        }
    }
    cout<<vhod-izhod;
return 0;
}
