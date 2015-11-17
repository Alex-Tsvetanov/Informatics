#include<iostream>
using namespace std;
int main ( )
{
    char ogranich[6],pole[4],d;
    cin >> ogranich >> pole;
    int x,y,pox,poy;
    x=1+ogranich[0]-'a';
    if(ogranich[2]!='\0')
        y=1+((ogranich[1]-'0')*10+ogranich[2]-'0');
    else{
        y=1+(ogranich[1]-'0');
    }


    pox=pole[0]-'a';
    if(pole[2]!='\0')
        poy=((pole[1]-'0')*10+pole[2]-'0');
    else{
        poy=(pole[1]-'0');
    }
    int n[x][y];
    //cout << x << endl << y << pox << endl << poy;
    if(y>10)
    cout << ' ';
    cout << "  ";
    for(int brx=0;brx<x;++brx){
        d=brx+'a';
        cout << d;
    }
    cout << endl;
    for(int bry=1;bry<y;++bry){
        if(y>9&&bry<10)
            cout << ' ';
        cout << bry << ' ';
        for(int brx=0;brx<x;++brx){
            if(brx==pox&&bry==poy)
                cout << 'H';
            else if((pox>1&&poy>1&&brx==pox-1&&bry==poy-2)||(pox<x-1&&poy>1&&brx==pox+1&&bry==poy-2)||(pox>1&&poy>0&&brx==pox-2&&bry==poy-1)||(pox<x-1&&poy>0&&brx==pox+2&&bry==poy-1)||(pox>1&&poy<y-1&&brx==pox+1&&bry==poy-2)
                ||(pox>1&&poy<y-1&&brx==pox-1&&bry==poy+2)||(pox>1&&poy<y&&brx==pox-2&&bry==poy+1)||(pox<x-1&&poy<y&&brx==pox+2&&bry==poy+1)||(pox<x&&poy<y-1&&brx==pox+1&&bry==poy+2))
                cout << 'X';
            else
                cout << 'O';
        }
        cout << endl;
    }
    return 0;
}
