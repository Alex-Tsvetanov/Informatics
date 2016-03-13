#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char h[3], pole[3];
    cin>>pole>>h;
    int H[2], Pole[2];
    H[0]=h[0]-'a';
    H[1]=(strlen(h)==2)?h[1]-'0'-1:(h[1]-'0')*10+h[2]-'0'-1;
    Pole[1]=pole[0]-'a'+1;
    Pole[0]=(strlen(pole)==2)?pole[1]-'0':(pole[1]-'0')*10+pole[2]-'0';
    char POLE[Pole[0]][Pole[1]];
    for(int x=0;x<Pole[0];x++){
        for(int y=0;y<Pole[1];y++){
            POLE[x][y]='O';
        }
    }

    POLE[H[1]][H[0]]='H';
    POLE[H[1]+1][H[0]+2]='X';
    POLE[H[1]-1][H[0]+2]='X';
    POLE[H[1]+1][H[0]-2]='X';
    POLE[H[1]-1][H[0]-2]='X';
    POLE[H[0]+3][H[1]]='X';
    POLE[H[0]+2][H[1]+6]='X';
    POLE[H[0]-1][H[1]-2]='X';
    POLE[H[0]-1][H[1]]='X';
    if(Pole[0]>9)cout<<" ";
    cout<<"  ";
    for(int i=0;i<Pole[1];i++){
        char a='a'+i;
        cout<<a;
    }
    cout<<endl;
    for(int x=0;x<Pole[0];x++){
        if(x<9 and Pole[0]>9)cout<<" ";
        cout<<x+1<<" ";
        for(int y=0;y<Pole[1];y++){
            cout<<POLE[x][y];
        }
        cout<<endl;
    }
    return 0;
}
