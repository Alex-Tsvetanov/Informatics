#include<iostream>
using namespace std;
int main(){
long long a[3000];
long long p[3000];
long long broqch=0,broqchbu=0,chislo,chislobu,chislopr=3,chislodel=2,suma=0;
bool prostolieto=true;
while(broqch<3000){
    a[broqch]=0;
    broqch++;
    //cout<<chislopr;
}
broqch=0;
while(broqch<3000){
    p[broqch]=0;
    broqch++;
}
broqch=0;
cin>>chislo;
chislobu=chislo;
while(chislobu>10){
    chislobu=chislobu/10;
    broqchbu++;
    //cout<<chislopr;
}
broqch=broqchbu;
while(broqchbu>=0){
    a[broqchbu]=chislo%10;
    broqchbu--;
    //cout<<chislopr;
}
broqchbu=broqch;
broqch=1;
p[0]=2;
while(broqch<3000){
        cout<<chislopr;
    while(p[broqch]==0){
            prostolieto=true;
    chislodel=2;
    cout<<chislopr;
    while(chislopr!=chislodel){
            cout<<chislopr;
    if(chislopr%chislodel==0){
        chislodel=chislopr;
        prostolieto=false;
    }else{
    chislodel++;
    }
    if(prostolieto==true){
        p[broqch]=chislopr;
        broqch++;
    }
    }
    chislopr++;
    }
    broqch++;
}
broqch=0;
while(broqch<3000){
        cout<<chislopr;
    if(a[broqch==1]){
        suma=suma+p[broqch];
    }
   broqch++;
}
cout<<suma;
return 0;
}
