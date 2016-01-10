#include<iostream>
#include<string>
using namespace std;

string vhod;
long long prostiChisla[10000],broi=0;
bool obhodenoLiE[100000];
void eratosten(){
    long long br,br1;
    for(br=2;broi<=4000;br++){
        //cout<<br<<" ";
        if(!obhodenoLiE[br]){
            prostiChisla[broi]=br;
            broi++;
            for(br1=br+br;br1<50000;br1+=br){
                obhodenoLiE[br1]=true;
            }
        }
    }
}

int main(){
    //cin.tie(NULL);
    //ios::sync_with_stdio(false);
    eratosten();
    long long dulzina,br,otg=0;
    cin>>vhod;
    dulzina=vhod.size();
    for(br=0;br<dulzina;br++){
        otg=otg+(vhod[br]-'0')*prostiChisla[br];
    }
    cout<<otg<<"\n";
    return 0;
}
