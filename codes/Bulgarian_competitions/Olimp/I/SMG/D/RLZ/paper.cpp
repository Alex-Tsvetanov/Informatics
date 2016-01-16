#include <iostream>
using namespace std;
int main (){
    long long M, N, broi=0;
    cin>>M>>N;
    while (M>1 and N>1){
       if (M%2==0 and N%2==0 and M>1 and N>1){
            M=M/2;
            broi=broi+1;
            N=N/2;
            broi=broi+1;
       }else {
            if (M%2==1 and N%2==1 and M>1 and N>1){
                M=M/2+1;
                broi=broi+1;
                N=N/2+1;
                broi=broi+1;
            }else {
                if (M%2==0 and N%2==1 and M>1 and N>1){
                    M=M/2;
                    broi=broi+1;
                    N=N/2+1;
                    broi=broi+1;
                }else{
                    if (M%2==1 and N%2==0 and M>1 and N>1){
                        M=M/2+1;
                        broi=broi+1;
                        N=N/2;
                        broi=broi+1;
                    }
                }
            }
       }
    }
    while (M!=N){
        if (M>N){
            if (M%2==0){
                M=M/2;
                broi=broi+1;
            }else {
                M=M/2+1;
                broi=broi+1;
            }
        }
        if (M<N){
            if (N%2==0){
                N=N/2;
                broi=broi+1;
            }else {
                N=N/2+1;
                broi=broi+1;
            }
        }
    }
    cout<<broi<<" ";
    return 0;
}
