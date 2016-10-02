#include<iostream>
using namespace std;
int main() {
    long long chislo1,chislo2,chislo3,brojChisla,sbor=0;
    cin>>chislo1>>chislo2>>chislo3>>brojChisla;
    sbor=chislo1+chislo2+chislo3;
    if(brojChisla>3) {
        while(brojChisla>3) {
            sbor=chislo1+chislo2+chislo3;
            chislo1=chislo2;
            chislo2=chislo3;
            chislo3=sbor;
            brojChisla--;
        }
        cout<<sbor;
    } else {
        if(brojChisla==1) {
            cout<<chislo1;
        } else {
            if(brojChisla==2) {
                cout<<chislo2;
            } else {
                cout<<chislo3;
            }
        }
    }
    return 0;
}
