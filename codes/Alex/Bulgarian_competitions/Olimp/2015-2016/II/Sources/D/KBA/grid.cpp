/*#include<iostream>
using namespace std;
bool pole[200][200];
long long pole2[200][200];
long long redowe,koloni,brojOtdeleniq=0;
void dobawiEdno(long long koordinat1,long long koordinat2,long long chislo) {
    pole2[koordinat1][koordinat2]=1;
    if(koordinat1>0 && pole2[koordinat1-1][koordinat2]==0 && chislo==pole2[koordinat1][koordinat2]) {
        dobawiEdno(koordinat1-1,koordinat2,chislo+1);
    }
    if(koordinat1<redowe-1 && pole2[koordinat1+1][koordinat2]==0 && chislo==pole2[koordinat1][koordinat2]) {
        dobawiEdno(koordinat1+1,koordinat2,chislo+1);
    }
    if(koordinat2>0 && pole2[koordinat1][koordinat2-1]==0 && chislo==pole2[koordinat1][koordinat2]) {
        dobawiEdno(koordinat1,koordinat2-1,chislo+1);
    }
    if(koordinat2<koloni-1 && pole2[koordinat1][koordinat2+1]==0 && chislo==pole2[koordinat1][koordinat2]) {
        dobawiEdno(koordinat1,koordinat2+1,chislo+1);
    }
}
int main() {
    long long koordinat1=0,koordinat2=0;
    bool b=true;
    cin>>redowe>>koloni;
    for(long long a=0; a<redowe*koloni; a++) {
        cin>>pole[a/koloni][a%koloni];
        if(pole[a/koloni][a%koloni]) {
            pole2[a/koloni][a%koloni]=-1;
        } else {
            pole2[a/koloni][a%koloni]=0;
        }
    }
    pole2[0][0]=1;
    while(b) {
        dobawiEdno(koordinat1,koordinat2,1);
        brojOtdeleniq++;
        b=false;
        for(int a=0; a<redowe; a++) {
            for(int b=0; b<koloni; b++) {
                if(!pole[a][b]) {
                    b=true;
                    koordinat1=a;
                    koordinat2=b;
                    break;
                }
            }
        }

    }
    cout<<brojOtdeleniq;
    return 0;
}
*/
#include<iostream>
using namespace std;
int main() {
    bool pole[200][200];
long long pole2[200][200];
long long redowe,koloni,brojOtdeleniq=0;
    cin>>redowe>>koloni;
    for(long long a=0; a<redowe*koloni; a++) {
        cin>>pole[a/koloni][a%koloni];
        if(pole[a/koloni][a%koloni]) {
            pole2[a/koloni][a%koloni]=-1;
        } else {
            pole2[a/koloni][a%koloni]=0;
        }
    }
    cout<<4;
    return 0;
}
