#include<iostream>
using namespace std;

int main(){
    int n,d1,d2,d3,broi=0;
    cin>>n>>d1>>d2>>d3;
    long long cif=10;
    for (int i=0;i<n-2;i++){
        cif=cif*10;
    }
    bool yes=false;
    long long mn=100;
    int del1,del2,del3,delit,delit1;
    int i=0;
    for (long long j=cif;j<cif*10;j++){
        i=2;
        for(mn=100;i<=n;mn=mn*10,i++){
            delit=(j%mn)/(mn/100);
            del1=delit/d1;
            del2=delit/d2;
            del3=delit/d3;
            if(delit>=d1&&d1*del1==delit&&(j%mn)/(mn/10)!=0){
                yes=true;
            }else if(delit>=d2&&d2*del2==delit&&(j%mn)/(mn/10)!=0){
                yes=true;
            }else if(delit>=d3&&d3*del3==delit&&(j%mn)/(mn/10)!=0){
                yes=true;
            }else{
                yes=false;
                break;
            }
        }

        if(yes==true){
            broi++;
        }

        yes=false;
    }

    cout<<broi<<endl;
return 0;
}
