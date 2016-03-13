#include<iostream>
using namespace std;
int main() {
    char v='a';
    string granici,poleNaKonq;
    long long x=0,y=0,koordinat1=0,koordinat2=0;
    char pole[26][26];
    cin>>granici>>poleNaKonq;
    x=granici[0]-'a'+1;
    koordinat1=poleNaKonq[0]-'a'+1;
    for(int a=1; a<granici.length(); a++) {
        y=y*10;
        y=y+(granici[a]-'0');
    }
    for(int a=1; a<poleNaKonq.length(); a++) {
        koordinat2=koordinat2*10;
        koordinat2=koordinat2+(poleNaKonq[a]-'0');
    }
    swap(x,y);
    swap(koordinat1,koordinat2);
    for(int a=0; a<x; a++) {
        for(int b=0; b<y; b++) {
                pole[a][b]='O';
        }
    }
    pole[koordinat1-1][koordinat2-1]='H';
    for(int a=0; a<x; a++) {
        for(int b=0; b<y; b++) {
            if((pole[a+1][b+2]=='H' && a+1<x && b+2<y) || (pole[a+2][b+1]=='H' && a+2<x && b+1<y) || (pole[a-1][b-2]=='H' && a-1>=0 && b-2>=0) || (pole[a-2][b-1]=='H' && a-2>=0 && b-1>=0) || (pole[a-1][b+2]=='H' && a-1>=0 && b+2<y) || (pole[a+1][b-2]=='H' && a+1<x && b-2>=0) || (pole[a+2][b-1]=='H' && a+2<x && b-1>=0) || (pole[a-2][b+1]=='H' && a-2>=0 && b+1<y)) {
                pole[a][b]='X';
            }
        }
    }
    cout<<"   ";
    for(int b=0; b<y; b++) {
        cout<<v;
        v++;
    }
    cout<<endl;
    for(int a=0; a<x; a++) {
        if(a+1<10) {
            cout<<" ";
        }
        cout<<a+1<<" ";
        for(int b=0; b<y; b++) {
            cout<<pole[a][b];
        }
        cout<<endl;
    }
    return 0;
}
