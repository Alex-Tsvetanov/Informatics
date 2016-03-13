#include<iostream>
#include<vector>
using namespace std;
int main(){
int N ,M;
int I, J, W, oldI, oldJ, result;
int i=0, j=0;
int street[100][100];

do{
cin>>N;
}while(N<2 || N>10000);

do{
cin>>M;
}while(M<1 || M>100000);

for(i=0;i<M;i++){
    for(j=0;j<M-1;j++){
        street[i][j]=0;
    }
}
oldI=0;
for(i=0;i<M;i++){
    cin>>I>>J;

            do{
                cin>>W;
            }while(W<1 || W>65000);

    street[I][J]=W;
    street[J][I]=W;
    if(oldI>I){
        result=0;
    }/*else if(oldI==I){
        result=street[I][J];
    }else{
        result=street[I][J];
    }
    */
    oldI=I;
    oldJ=J;
}

 if(result!=0){
    result=street[oldI][oldJ];
}

cout<<result;

/*
for(i=0;i<M;i++){
    for(j=0;j<M;j++){
        cout<<street[i][j]<<" ";
    }
    cout<<endl;
}
*/



return 0;
}
