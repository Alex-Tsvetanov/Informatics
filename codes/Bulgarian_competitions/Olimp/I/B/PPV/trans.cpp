#include <iostream>
using namespace std;
int main(){
    long int P,M,K,i=0,r=0;
    cin>>P>>M;
    long int p,a,v[P+1],d[P+1];
    for(i=0;i<P;i++){
        v[i+1]=0;
    }
    for(i=0;i<M;i++){
        cin>>p>>a;
        v[p]++;
        v[a]++;
    }
    cin>>K;
    for(i=0;i<P;i++){
        if(v[i+1]>=K){
            r++;
            d[i]=i+1;
           d[i+1]='\0';
        }
    }
    if(r>0){
        cout<<r<<"\n";
        for(i=0;i<P;i++){
            if(d[i]>0 and d[i]<P+1){
                cout<<d[i]<<" ";
            }
        }
    }

    return 0;
}
