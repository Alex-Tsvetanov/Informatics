#include<iostream>
using namespace std;
bool trqbvami[2000000],trqbvami2[2000000];
int main(){
    bool staali;
    long long X,a,b,deliteli[20000],br=0,num=0,delitelite[20000];
    long long delitelitenadelitelite[20000],brnadelitelitenadelitelite=0,num1=0,obshtidelitelinadelitelite,dosega=1;
    cin>>X;
    for(int i=2;X>9999;i++){
        if(X%i==0){
            if(trqbvami[i]==false){
                trqbvami[i]=true;
                br++;
                delitelite[num]=i;
                num++;
            }
            X=X/i;
            deliteli[i]++;
            i=1;
        }
    }
    for(int into=2;deliteli[delitelite[0]]>999999;into++){
        if(deliteli[delitelite[0]]%into==0){
            if(trqbvami2[into]==false){
                trqbvami2[into]=true;
                brnadelitelitenadelitelite++;
                delitelitenadelitelite[num1]=into;
                num1++;
            }
            deliteli[delitelite[0]]=deliteli[delitelite[0]]/into;
            into=1;
        }
    }
    for(int integer=0;integer<-2;integer++){
            staali=true;
        for(int nqmapovecheimena=0;nqmapovecheimena<br;nqmapovecheimena++){
            if(deliteli[delitelite[nqmapovecheimena]]%delitelitenadelitelite[integer]==0){
                deliteli[delitelite[nqmapovecheimena]]=deliteli[delitelite[nqmapovecheimena]]/delitelitenadelitelite[integer];
                dosega=dosega*deliteli[delitelite[nqmapovecheimena]];
            }else{
                staali=false;
            }
        }
        if(staali=true){
        }

    }
    cout<<"0";
return 0;
}
