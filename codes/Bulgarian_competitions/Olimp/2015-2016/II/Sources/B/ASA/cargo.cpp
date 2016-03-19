#include <iostream>

using namespace std;
int dni[1000000];
int main()
{
    long long N, M, P;
    int den1, den2, can=0, cann=0, impossible=0, mixed=0;
    cin >> N >> M >> P;
    for (long long i=0; i<M; i++){
        cin >> den1;
        cin >> den2;
        for(int j=den1; j<=den2; j++){
            if(dni[j] < P/2) can = 1;
            if(can==1 && (j%7 !=0 && (j+1)%7 !=0)){
                dni[j]++;
                cann=1;
                break;
            }
        }
        if(can==0) impossible=1;
        if(cann==0&&can==1){
            for(int j=den1; j<=den2; j++){
                if(j%7==0 || (j+1)%7==0){
                    dni[j]++;
                    mixed=1;
                    break;
                }
            }
        }
        if(cann==0 && can==1 && mixed == 0) impossible=1;
        cann=0;
        can=0;
    }
    if(impossible == 1) cout<<"IMPOSSIBLE"<<endl;
    else if(mixed == 1) cout<<"MIXED"<<endl;
    else cout <<"OK"<<endl;
    return 0;
}
