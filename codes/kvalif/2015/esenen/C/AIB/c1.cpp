#include<iostream>
#include<cstdio>
using namespace std;
int N,M,a,s,br,tzifri=0,br1,sreshti;
int prov[500];
bool zap[500][500];
int main(){
    scanf("%d%d",&N,&M);
    for(br=0;br<M;br++){
        scanf("%d%d",&a,&s);
        zap[a-1][s-1]=false;
        zap[s-1][a-1]=false;
    }
    for(int k=0;k<N;k++){
    for(br=0;br<N;br++){
        if(prov[br]==0){
            tzifri++;
            prov[br]=tzifri;
        }
        for(br1=0;br1<N;br1++){
            if(zap[br][br1]==false){
                if(prov[br1]==0){
                    prov[br1]=prov[br];
                }
                if(prov[br1]!=0 && prov[br1]!=prov[br]){
                    sreshti++;
                }
            }
        }
    }
    }
    printf("%d\n",tzifri-sreshti);
return 0;
}
