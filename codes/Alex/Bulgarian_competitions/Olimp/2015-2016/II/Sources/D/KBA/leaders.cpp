#include<iostream>
using namespace std;
long long brojChisla,chisla[1000001],lideri[1000001],maksChislo=-1000001,poz=0;
int main() {
    cin>>brojChisla;
    for(long long a=0; a<brojChisla; a++) {
        cin>>chisla[a];
    }
    for(long long a=brojChisla; a>=0; a--) {
        if(chisla[a]>maksChislo) {
            lideri[poz]=chisla[a];
            poz++;
            maksChislo=chisla[a];
        }
    }
    for(long long a=poz-1; a>0; a--) {
        cout<<lideri[a]<<" ";
    }
    return 0;
}
