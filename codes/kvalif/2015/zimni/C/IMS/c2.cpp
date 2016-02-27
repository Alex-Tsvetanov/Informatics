#include<iostream>
#include<set>
using namespace std;

long long redoveA,koloniA,redoveB,koloniB,A[124][124],B[124][124];
set<long long> sborA,sborB;
long long suma[1024],dA,dB;

long long ngod(long long a,long long b){
    while(a!=0 and b!=0){
        if(a>b){
            a=a%b;
        }else{
            b=b%a;
        }
    }
    if(a!=0)
        return a;
    return b;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long x,y,purvo,vtoro;
    cin>>redoveA>>koloniA;
    for(x=0;x<redoveA;x++){
        for(y=0;y<koloniA;y++){
            cin>>A[x][y];
            suma[x]=suma[x]+A[x][y];
            suma[y+redoveA]=suma[y+redoveA]+A[x][y];
        }
    }
    for(y=0;y<redoveA+koloniA;y++){
        if(suma[y]<0){
            suma[y]*=(-1);
        }
        sborA.insert(suma[y]);
        suma[y]=0;
    }

    set<long long>::iterator it=sborA.begin();
    purvo=(*it);
    for(it++;it!=sborA.end();it++){
        vtoro=(*it);
        purvo=ngod(purvo,vtoro);
    }
    dA=purvo;

    cin>>redoveB>>koloniB;
    for(x=0;x<redoveB;x++){
        for(y=0;y<koloniB;y++){
            cin>>B[x][y];
            suma[x]=suma[x]+B[x][y];
            suma[y+redoveB]=suma[y+redoveB]+B[x][y];
        }
    }
    for(y=0;y<redoveB+koloniB;y++){
        if(suma[y]<0){
            suma[y]*=(-1);
        }
        sborB.insert(suma[y]);
    }


    it=sborB.begin();
    purvo=(*it);
    for(it++;it!=sborB.end();it++){
        vtoro=(*it);
        purvo=ngod(purvo,vtoro);
    }
    dB=purvo;

    cout<<dA<<" "<<dB<<"\n";
    if(dA%dB==0 or dB%dA==0){
        cout<<"Y\n";
    }else{
        cout<<"N\n";
    }
    return 0;
}
