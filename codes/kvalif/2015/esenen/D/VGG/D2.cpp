#include<iostream>
using namespace std;
int main(){
    int a,b1,b2,konX,konY;
    char kraino[4],i,pole[26][26],kon[4];
    cin>>kraino>>kon;
    cout<<"  ";
    for(i='a';i<kraino[0];i++){
        cout<<i;
    }
    if(kraino[2]>'0'&&kraino[2]<'9'){
        a=(kraino[1]-'0')+2*(kraino[2]-'0');
    }else{
        a=kraino[1]-'0';
    }if(kon[2]>'0'&&kon[2]<'9'){
        konX=(kon[1]-'0')+2*(kon[2]-'0');
    }else{
        konX=kon[1]-'0';
    }


    for(b1=0;b1<a,b1++){
        for(b2=0;b2<i-'a';b2++){
            pole[b1][b2]='O';
        }
    }
    pole[konX][konY]='H'
    if(konX-2>=0){
        if(konY-1>=0){
            pole[konX-2][konY-1]='X'
        }
        if(konY+1<=b2){
            pole[konX-2][konY+1]='X'
        }
    }
    if(konY-2>=0){
        if(konX-1>=0){
            pole[konX-1][konY-2]='X'
        }
        if(konX+1<=b1){
            pole[konX+1][konY-2]='X'
        }
    }
    if(konX+2<=b1){
        if(konY-1>=0){
            pole[konX+2][konY-1]='X'
        }
        if(konY+1<=b2){
            pole[konX+2][konY+1]='X'
        }
    }
    if(konY+2<=b2){
        if(konX-1>=0){
            pole[konX-1][konY+2]='X'
        }
        if(konX+1<=b1){
            pole[konX+1][konY+2]='X'
        }
    }
    for(b1=0;b1<a,b1++){
        cout<<b1<<" ";
        for(b2=0;b2<i-'a';b2++){
            cout<<pole[b1][b2];
        }cout<<endl;
    }
    return 0;
}
