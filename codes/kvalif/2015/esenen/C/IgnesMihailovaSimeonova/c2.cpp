#include<iostream>
using namespace std;

long long chislaZapo4va6tiS[10][100],kolkoChisla[10],otg=0,n;
long long bla[100];
bool used[1000];

long long re6enie(long long kolko,long long index){
    bla[index]=kolko;
    if(index==n-1){
        otg++;
        return 0;
    }
    for(long long br=0;br<kolkoChisla[kolko];br++){
        long long c=chislaZapo4va6tiS[kolko][br]%10;
        if(index==n-2){
            re6enie(c,index+1);
        }else{
            if(kolkoChisla[c]>0){
                re6enie(c,index+1);
            }
        }
    }
}

int main(){
    long long vhod[4],br,i,c;
    cin>>n>>vhod[0]>>vhod[1]>>vhod[2];
    for(i=0;i<3;i++){
        for(br=vhod[i];br<=99;br+=vhod[i]){
            if(!used[br]){
                used[br]=true;
                c=br/10;
                chislaZapo4va6tiS[c][kolkoChisla[c]]=br;
                kolkoChisla[c]++;
            }
        }
    }
    for(br=0;br<10;br++){
        re6enie(br,0);
    }
    cout<<otg<<endl;
    return 0;
}
