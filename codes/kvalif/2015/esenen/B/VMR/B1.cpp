#include<iostream>
#include<cmath>
using namespace std;
int br=0;
long nms = 0;
int nmbr = 0;
struct matr{
short int vr;
int x[100];
int y[100];
int S=0;


};


int main (){
matr T[100];
for(int i=1;i>=0;i++){
    cin>>T[i].vr;
    if(T[i].vr==0){
            br=i-1;
        break;
    }
    else{

    for(int q=1;q<=T[i].vr;q++){
        cin>>T[i].x[q];
        cin>>T[i].y[q];
    }
    }
}

for(int i=1;i<=br;i++){
    for(int q=3;q<=T[i].vr;q++){

        T[i].S = T[i].S + (abs(T[i].y[1]-T[i].y[q-1])*abs(T[i].x[q]-T[i].x[1])) - (  (abs(T[i].x[1]-T[i].x[q-1])*abs(T[i].y[q-1]-T[i].y[1]))/2 + (abs(T[i].x[q]-T[i].x[q-1])*abs(T[i].y[q-1]-T[i].y[q]))/2 + (abs(T[i].x[q]-T[i].x[1])*abs(T[i].y[q]-T[i].y[1]))/2 );

    }
}
nms=T[1].S;
nmbr=1;
for(int i=2;i<=br;i++){
    if(T[i].S < nms){
        nmbr = i;
    }
}
cout<<nmbr<<endl;

    return 0;
}
