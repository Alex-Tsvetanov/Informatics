#include<iostream>
using namespace std;
int n,M=0,d1,d2,d3,stepenuvasht,chbr,stepen,chislo;
bool broken=false;
unsigned long long nachalo=1,krai,segashno;
unsigned long long pow1(int a){
    unsigned long long rez=1;
for(int k=0;k<a;k++){
    rez*=10;
}
return rez;
}
int main(){
cin>>n;
for(stepenuvasht=0;stepenuvasht<n-1;stepenuvasht++){
    nachalo*=10;
}
krai=10*nachalo-1;
cin>>d1>>d2>>d3;
for(segashno=nachalo;segashno<=krai;segashno++){
    broken=false;
    for(chbr=1;chbr<n && broken==false;chbr++){
            stepen=pow1(chbr);
            chislo=(segashno/(stepen/10))%10+10*((segashno/stepen)%10);if(chislo<10){broken=true;}
    if(chislo%d1==0 or chislo%d2==0 or chislo%d3==0){}else{
        broken=true;
    }
    }
    if(broken==false){
        M++;
    }
}
cout<<M<<"\n";
return 0;
}
