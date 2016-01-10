#include <iostream>
using namespace std;
int a[3000],n[12],buf;

int check(){
    return n[1]*2+n[2]*4+n[3]*8+n[4]*16+n[5]*32+n[6]*64+n[7]*128+n[8]*256+n[9]*512+n[10]*1024+n[11]*2048;
}

void ruk(){
    for(int i=11;i>1;i--){
        cout<<n[i]<<" ";
    }
    cout<<buf<<endl;
}

int rek(int stepen){
    if(stepen==0){
        for(int i=check()+1;i<=3000;i++){
            a[i]++;
        }
    }
    else{
        while(1){
            if(stepen>0)rek(stepen-1);
            n[stepen]++;
            buf=check();
            if(stepen>5)ruk();
            if(buf>3000){
                n[stepen]=0;
                break;
            }
            a[buf-1]++;
        }
    }
}

int main(){
rek(11);
for(int i=0;i<3000;i++)cout<<a[i]<<",";
return 0;
}
