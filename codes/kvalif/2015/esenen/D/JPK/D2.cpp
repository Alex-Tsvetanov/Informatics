#include<iostream>
using namespace std;
int pole[35][35];
int main(){
int red, kolona, konY, konX;
char bukvaNaKolona, konXBukva;
cin>>bukvaNaKolona>>red;
cin>>konXBukva>>konY;
kolona=bukvaNaKolona-'a'+1;
konX=konXBukva-'a'+1;
konX+=2; konY+=2;
pole[konX][konY]=2;
pole[konX-2][konY-1]=1;
pole[konX-1][konY-2]=1;
pole[konX+2][konY-1]=1;
pole[konX+1][konY-2]=1;
pole[konX-2][konY+1]=1;
pole[konX-1][konY+2]=1;
pole[konX+2][konY+1]=1;
pole[konX+1][konY+2]=1;

if(red>10){
    cout<<"   ";
}else{
    cout<<"  ";
}
for(int i=0;i<kolona;i++){
    cout<<(char)(i+'a');
}
cout<<endl;
for(int j=3;j<red+3;j++){
    if(red>10 and j-2<10){
            cout<<" ";
    }
    cout<<j-2<<" ";
    for(int i=3;i<kolona+3;i++){
        if(pole[i][j]==0){
            cout<<"O";
        }else{
            if(pole[i][j]==1){
                cout<<"X";
            }else{
                if(pole[i][j]==2){
                    cout<<"H";
                }
            }
        }
    }
    cout<<endl;
}
return 0;
}
