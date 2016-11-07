#include<iostream>
using namespace std;
int main(){
    long long kupa[3],bonboni=0,byrka;
    bool otegchilaLiSeE=false;
    cin>>kupa[0]>>kupa[1]>>kupa[2];
    while(!otegchilaLiSeE){
        for(byrka=0;byrka<4 and !otegchilaLiSeE;byrka++){
            if(byrka==3 and !otegchilaLiSeE){
                if(kupa[1]>=1){
                    bonboni=bonboni+1;
                    kupa[1]=kupa[1]-1;
                }else{
                    otegchilaLiSeE=true;
                }
            }else if(!otegchilaLiSeE){
                if(kupa[byrka]>=1){
                    bonboni=bonboni+1;
                    kupa[byrka]=kupa[byrka]-1;
                }else{
                    otegchilaLiSeE=true;
                }
            }
        }
    }
    cout<<bonboni;
return 0;
}

