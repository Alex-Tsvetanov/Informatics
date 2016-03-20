#include<iostream>
using namespace std;

long long p,n,s,otg[1000],asd;

void sumi(long long tekusto,long long index){
    //cout<<tekusto<<" "<<index;
    //cout<<"a\n";
    if(index+1==n){
    asd++;
        otg[index]=s-tekusto;
        for(int i=0;i<n;i++){
            cout<<otg[i]<<" ";
        }cout<<endl;
        return;
    }
    for(long long br=s-tekusto;br>=0;br--){
        otg[index]=br;
        sumi(tekusto+br,index+1);
        //cout<<tekusto<<" "<<br<<"b"<<"\n";
    }
}

int main(){
    cin>>p>>n>>s;
    sumi(0,0);
    for(suma=0;suma<s;suma++){
        for(dokolko=0;dokolko<p;dokolko++){
            for(broi=0;br<n;br++){

            }
        }
    }
    cout<<asd;
}
