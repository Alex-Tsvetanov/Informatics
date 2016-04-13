#include<iostream>
using namespace std;
int main(){
    int N,naimal=1000000,segashna,i;
    cin>>N;
    for(i=1;i<N/2;i++){
        if(N%i==0){
            segashna=(i+N/i)*2;
            if(naimal>segashna){
                naimal=segashna;
            }
        }
    }

    cout<<naimal<<endl;
return 0;
}
