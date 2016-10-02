#include <iostream>
using namespace std;
int main(){

   unsigned  short  N, M, T , gn1, gn2, gn3, gn4;
int gnili=0;
   cin>>N>>M>>T;
   int chislata[N][M];
   for(int nqnq=0; nqnq<N; nqnq++){
    for(int mqmq=0; mqmq<<M; mqmq++){
        chislata[nqnq][mqmq]=0;
    }
   }
   cin>>gn1>>gn2>>gn3>>gn4;
   chislata[gn1][gn2]=T;
    chislata[gn3][gn4]=T;
    int I=T+2;
    for(int i=0; i<T; i++){
            I=I-1;
        for(int n=0; n<N; n++){
            for(int m=0; m<M; m++){
                if (chislata[n][m-1]==I||chislata [n][m+1]==I){}
                gnili++;
            }
        }

    }
    int neshto=(N*M)- gnili;
    cout<<neshto;
    return 0;
}
