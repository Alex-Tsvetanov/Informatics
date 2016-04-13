#include<iostream>
using namespace std;
int main(){
    long long N,k,p,r=1,q=525,t[q],proizvedenie=1,M,non=0;
    cin>>N;
    char simvol[N],dobavqne[525];
    p=N;
    for(k=1;k<N+1;k++){
        cin>>simvol[k];
    }
    while(p>0 and non==0){
        while(r<p-r+1){
            if(simvol[p-r+1]/simvol[r]==1){
                t[r]=1;
            }else{
                t[r]=0;
            }
            r=r+1;
        }
        for(r=1;r<p-r;r++){
            proizvedenie=proizvedenie*t[r];
        }
        if(proizvedenie==1){
            non=1;
            p=p+1;
        }
        p=p-1;
    }
    M=N-p;
    cout<<M;
    cout<<"\n";
    for(k=1;k<M+1;k++){
        dobavqne[k]=simvol[N-p-k+2];
        cout<<dobavqne[k];
    }
    return 0;
}
