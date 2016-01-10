#include <iostream>
using namespace std;
int main(){
    long int P,M,K,i=0,vuzeli=0;
    cin>>P>>M;
    long int m,n,q[P+1],r[P+1];
    for(i=0;i<P;i++){
        q[i+1]=0;
    }
    for(i=0;i<M;i++){
        cin>>m>>n;
        q[m]++;
        q[n]++;
    }
    cin>>K;
    for(i=0;i<P;i++){
        if(q[i+1]>=K){
            vuzeli++;
            r[i]=i+1;
            r[i+1]='\0';
        }
    }
    if(vuzeli>0){
        cout<<vuzeli<<"\n";
        for(i=0;i<P;i++){
            if(r[i]>0 and r[i]<P+1){
                cout<<r[i]<<" ";
            }
        }
    }

    return 0;
}

