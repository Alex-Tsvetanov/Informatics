#include<iostream>
using namespace std;
short kak(int dni, int zayavki, int ekipaji, int nach[], int kr[], short gotovi[]){
    ///0-> IMPOSSIBLE, 2-> MIXED, 1->OK
    for(int i=1;i<=dni;i++){
        if(i%7==6 || i%7==0){
            int zaetiEkipaji=0;
            for(int j=0;j<zayavki&&zaetiEkipaji<ekipaji;j++){
                if(nach[j]<=i&&i<=kr[j]&&(!gotovi[j])){
                    zaetiEkipaji++;
                    gotovi[j]=2;
                }
            }
        }else{
            int zaetiEkipaji=0;
            for(int j=0;j<zayavki&&zaetiEkipaji<ekipaji;j++){
               // if(i==4) cout<<nach[j]<<" "<<i<<" "<<kr[j]<<" "<<gotovi[j]<<"\n";
                if(nach[j]<=i&&i<=kr[j]&&(!gotovi[j])){
                    zaetiEkipaji++;
                    gotovi[j]=1;
                }
            }
        }
    }
    int res=1;
    for(int i=0;i<zayavki;i++){
            //if(gotovi[i]==0) cout<<i<<" ";
        if(gotovi[i]==0) return 0;
        if(gotovi[i]==2) res=2;
    }
    return res;
}
int nach[1000000], kr[1000000];
short gotovi[1000000];
int main(){
    ios::sync_with_stdio(false);
    cin.tie(NULL);
    int dni, zayavki, ekipaji;
    cin>>dni>>zayavki>>ekipaji;
    ekipaji/=2;
    for(int g=0;g<zayavki;g++){
        cin>>nach[g]>>kr[g];
    }
    short blq=kak(dni, zayavki, ekipaji, nach, kr, gotovi);
    if(blq==0){
        cout<<"IMPOSSIBLE\n";
        return 0;
    }
    if(blq==1) cout<<"OK\n";
    else cout<<"MIXED\n";
    return 0;
}
