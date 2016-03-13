#include<iostream>
using namespace std;
int main(){
     long long N=20,T[N],k;
     cin>>T[1];
     cin>>T[2];
     cin>>T[3];
     cin>>N;
     for(k=4;k<N+1;k++){
        T[k]=T[k-1]+T[k-2]+T[k-3];
     }
    cout<<T[N];
    return 0;
}
