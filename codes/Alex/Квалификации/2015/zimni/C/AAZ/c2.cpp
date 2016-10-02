#include<iostream>
using namespace std;
long long A[100001][101];
long long B[100001][101];
long long ADD[100001],BDD[100001];
long long ADX[100001],ADY[101];
long long BDX[100001],BDY[101];
int main() {

    long long na,ma,nb,mb;
    cin>>na>>ma;
    for(long long y=0; y<ma; y++) {
        for(long long x=0; x<na; x++) {
            cin>>A[x][y];
        }
    }
    cin>>nb>>mb;
    for(long long y=0; y<mb; y++) {
        for(long long x=0; x<nb; x++) {
            cin>>B[x][y];
        }
    }
    for(long long y=0; y<ma; y++) {
        for(long long x=0; x<na; x++) {
            ADY[y] = ADY[y] + A[x][y];
        }
        if(y==ma-1) {
            for(long long k=1; k<=ADY[0]/2+1; k++) {
                long long s = 0;
                for(long long j=0;j<ma;j++){
                    if(!(ADY[j]%k==0)){
                        j = ma + 1;
                    } else {
                        s = s + 1;
                        if(s==ma-1){
                            ADD[0] = k;
                            j = ma + 1;
                            //k = ADY[0]/2 + 1;
                            y = ma + 1;
                        }
                    }
                }
            }
        }
    }
    for(long long x=0; x<na; x++) {
        for(long long y=0; y<ma; y++) {
            ADX[x] = ADX[x] + A[x][y];
        }
        if(x==na-1) {

            for(long long k=1; k<=ADX[0]/2+1; k++) {
                long long s = 0;
                for(long long i=0;i<na;i++){
                    if(!(ADX[i]%k==0)){
                        i = na + 1;
                    } else {
                        s = s + 1;
                        if(s==na-1){
                            ADD[1] = k;
                            i = na + 1;
                            //k = ADX[0]/2 + 1;
                            x = na + 1;
                        }
                    }
                }
            }
        }
    }
    ///
     for(long long y=0; y<mb; y++) {
        for(long long x=0; x<nb; x++) {
            BDY[y] = BDY[y] + B[x][y];
        }
        if(y==mb-1) {
            for(long long k=1; k<=BDY[0]/2+1; k++) {
                long long s = 0;
                for(long long j=0;j<mb;j++){
                    if(!(BDY[j]%k==0)){
                        j = mb + 1;
                    } else {
                        s = s + 1;
                        if(s==mb-1){
                            BDD[0] = k;
                            j = mb + 1;
                            //k = BDY[0]/2 + 1;
                            y = mb + 1;
                        }
                    }
                }
            }
        }
    }
    for(long long x=0; x<nb; x++) {
        for(long long y=0; y<mb; y++) {
            BDX[x] = BDX[x] + B[x][y];
        }
        if(x==nb-1) {
            for(long long k=1; k<=BDX[0]/2+1; k++) {
                long long s = 0;
                for(long long i=0;i<nb;i++){
                    if(!(BDX[i]%k==0)){
                        i = nb + 1;
                    } else {
                        s = s + 1;
                        if(s==nb-1){
                            BDD[1] = k;
                            i = nb + 1;
                            //k = BDX[0]/2 + 1;
                            x = nb + 1;
                        }
                    }
                }
            }
        }
    }
    long long p,q;
    if(ADD[0]>ADD[1]){
        cout<<ADD[0]<<" ";
        p = ADD[0];
    } else {
        cout<<ADD[1]<<" ";
        p = ADD[1];
    }
    if(BDD[0]>BDD[1]){
        cout<<BDD[0];
        q = BDD[0];
    } else {
        cout<<BDD[1];
        q = BDD[1];
    }
    cout<<endl;
    if((p%q==0) or (q%p==0)){
        cout<<"Y";
    } else {
        cout<<"N";
    }
    cout<<endl;

    return 0;
}

