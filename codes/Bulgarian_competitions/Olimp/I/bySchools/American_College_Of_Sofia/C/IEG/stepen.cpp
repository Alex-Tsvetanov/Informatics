#include<iostream>
#include<cmath>
using namespace std;
int cifri[10000][2];
int main() {
    long long x,k=0,dokudedabroq=1,y;
    int kolkopredstavqniq=0;
    int base=0;
    cin>>x;
    y=x;
    while(x!=0) {
        k++;
        x=x/10;
    }
    k--;
    for(int j=1; j<k; j++) {
        dokudedabroq*=10;
    }
    for(int i=y/dokudedabroq; i>1; i--) {
        for(int a=2; a<y/dokudedabroq; a++) {
            if(pow(i,a)==y) {
                kolkopredstavqniq++;
               // cout<<kolkopredstavqniq<<"\n";
                cifri[base][0]=i;
                cifri[base][1]=a;
             // cout<<cifri[base][0]<<" "<<cifri[base][1]<<"\n";
                base++;
            }
        }

    }
    cout<<kolkopredstavqniq<<"\n";
    for(int chocho=0; chocho<base; chocho++) {
        if(cifri[chocho][0]==0) {
            break;
        }
        cout<<cifri[chocho][0]<<" "<<cifri[chocho][1]<<"\n";
    }
    return 0;
}
