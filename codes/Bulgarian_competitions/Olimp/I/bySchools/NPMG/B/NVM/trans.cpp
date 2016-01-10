#include <iostream>
#include <algorithm>
using namespace std;
void vuzelcheta (int gradove[10000][10000],int P,int M){
int masiv[M*2];
int k = 0;
for(int i = 0; i<M*2; i+2){
cin>>masiv[i]>>masiv[i+1];
}
for(int p = 0; p<M*2; p++){
    while(gradove[masiv[p]][k]!=0){
        k++;
    }
    gradove[masiv[p]][k] = masiv[p+1];
    k = 0;
    while(gradove[masiv[p+1]][k]!=0){
        k++;
    }
    gradove[masiv[p+1]][k] = masiv[p];
    k=0;
}
}
int tvuzli (int gradove[10000][10000],int P,int trans[10000],int K,int M){
int indOfTrans = 0,br;
for(int i = 1; i<P; i++){
br = 0;
for(int p = 0; p<M; p++){
    if(gradove[i][p]!=0){
        br++;
    }
}
if(br>=K){
    trans[indOfTrans] = i;
    indOfTrans++;
}
}
return indOfTrans;
}

void sorter(int vuzli[10000],int n){
int minsmal,swaper;
for(int i = 0; i<n; i++){
   minsmal = i;
    for(int p = i+1; p<n; p++){
        if(vuzli[p]<vuzli[minsmal]){
            swaper = vuzli[p];
            vuzli[p] = vuzli[minsmal];
            vuzli[minsmal] = swaper;
            minsmal = p;
        }
    }
}

}

int main(){
int gradove [10000][10000],vuzli[10000];
int P,M,K,br;
cin>>P>>M;
vuzelcheta(gradove,P,M);
cin>>K;
br = tvuzli(gradove,P,vuzli,K,M);
sorter(vuzli,br);
for(int i = 0; i<br; i++){
    cout<<vuzli[i]<<" ";
}

}
