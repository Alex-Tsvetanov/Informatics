#include <iostream>
using namespace std;
int main(){
    long int N,i=0,naimalkoch=1000001,naigolqmoch=-1,ngchi=0,nmchi=0;
    cin>>N;
    long int a[20000];
    for(i=0;i<N;i++){
        cin>>a[i];
    }
    for(i=0;i<N;i++){
        if(a[i]<naimalkoch){
            naimalkoch=a[i];
            nmchi=i;
        }
        if(a[i]>=naigolqmoch){
            naigolqmoch=a[i];
            ngchi=i;
        }
    }
    cout<<nmchi+1<<" "<<ngchi+1;
    return 0;
}
