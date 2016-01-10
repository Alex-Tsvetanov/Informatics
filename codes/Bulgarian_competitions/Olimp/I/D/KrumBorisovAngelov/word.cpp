#include<iostream>
using namespace std;
int main() {
    long long brojBukwi[26]={0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0,0};
    char bukwi[26]={'A','B','C','D','E','F','G','H','I','J','K','L','M','N','O','P','Q','R','S','T','U','V','W','X','Y','Z'};
    string text;
    cin>>text;
    for(int a=0; a<text.length(); a++) {
        if(text[a]>='a' && text[a]<='z') {
            brojBukwi[(text[a]-'a')]++;
        } else {
            if(text[a]>='A' && text[a]<='Z') {
                brojBukwi[(text[a]-'A')]++;
            }
        }
    }
    for(int a=0; a<25; a++) {
        for(int b=a+1; b<26; b++) {
            if(brojBukwi[a]<brojBukwi[b]) {
                swap(brojBukwi[a],brojBukwi[b]);
                swap(bukwi[a],bukwi[b]);
            }
        }
    }
    for(int a=0; a<26; a++) {
        cout<<brojBukwi[a]<<" "<<bukwi[a]<<endl;}
    for(int a=0; a<6; a++) {
        if(brojBukwi[a]==0) {
            break;
        } else {
            cout<<bukwi[a];
        }
    }
    return 0;
}
