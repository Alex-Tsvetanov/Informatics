#include<iostream>
using namespace std;
void vRedica(int redica[20000],int N){
for(int i = 0; i<N; i++){
cin>>redica[i];
if(redica[i]<0 || redica[i]>1000000){
    cout<<"error";
}
}
}
void maxRed(int redica[20000],int N){
int maxNachalo=0,maxKraj=0,razlika=1;
for(int nachalo = 0; nachalo<N-1; nachalo++){
    for(int kraj = nachalo+1; kraj<N-1; kraj++){
        if(redica[kraj]>redica[nachalo]){
        if(razlika<=(redica[kraj]-redica[nachalo])){
                if((kraj-nachalo)>=(maxKraj-maxNachalo)){
                   razlika = redica[kraj]-redica[nachalo];
                   maxNachalo = nachalo;
                   maxKraj = kraj;
                }
        }}



        if(redica[kraj]<redica[nachalo]){
                    if(razlika<=(redica[nachalo]-redica[kraj])){

                    if((kraj-nachalo)>=(maxKraj-maxNachalo)){
                     razlika = redica[nachalo]-redica[kraj];
                     maxNachalo = nachalo;
                     maxKraj = kraj;
                }
        }
        }


    }

}
cout<<maxNachalo+1<<" "<<maxKraj;
}
int main(){
int redica[20000],N;
cin>>N;
if(N<=0 || N>20000){
    cout<<"too big N";
}
vRedica(redica,N);
maxRed(redica,N);


}
