#include<iostream>
#include<algorithm>
#include<cmath>
using namespace std;

long long osnova[1000000],stepen[1000000];

long long stepenuvane(long long k,long long turseno){
    long long chislo=k,otg;
    for(otg=2;chislo<turseno;otg++){
        chislo*=k;
    }
    otg--;
    if(turseno!=chislo){
        otg=-1;
    }
    return otg;
}

int main(){
    cin.tie(NULL);
    ios::sync_with_stdio(false);
    long long x,a,b,koren,broi=0;
    cin>>x;
    koren=sqrt(x)+1;
    //cout<<koren*koren<<"\n";
    for(a=2;a<=koren;a++){
        if(x%a==0){
            //cout<<a<<"\n";
            b=stepenuvane(a,x);
            if(b>1){
                osnova[broi]=a;
                stepen[broi]=b;
                broi++;
            }
        }
    }
    cout<<broi<<"\n";
    if(broi!=0){
        for(a=broi-1;a>=0;a--){
            cout<<osnova[a]<<" "<<stepen[a]<<"\n";
        }
    }
    return 0;
}
