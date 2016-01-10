#include<iostream>
#include<algorithm>
#include<cstring>
using namespace std;
int main(){
    char n[100000], mb[100000], mn[100000];
    long long i=0, br=0, j;
    bool mglb[26];
    for(i=0;i<26;i++){
        mglb[i]=false;
    }
    cin>>n[0];
    for(i=1;;i++){
        cin>>n[i];
        if(n[i]=='#'){
            break;
        }
        if(n[i]<='z' and n[i]>='a'){
            mb[i]=n[i];
            if(mb[i]=='a' or mb[i]=='A'){
            mglb[0]=true;
        }
        if(mb[i]=='b' or mb[i]=='B'){
            mglb[1]=true;
        }
        if(mb[i]=='c' or mb[i]=='C'){
            mglb[2]=true;
        }
        if(mb[i]=='d' or mb[i]=='D'){
            mglb[3]=true;
        }
        if(mb[i]=='e' or mb[i]=='E'){
            mglb[4]=true;
        }
        if(mb[i]=='f' or mb[i]=='F'){
            mglb[5]=true;
        }
        if(mb[i]=='g' or mb[i]=='G'){
            mglb[6]=true;
        }
        if(mb[i]=='h' or mb[i]=='H'){
            mglb[7]=true;
        }
        if(mb[i]=='i' or mb[i]=='I'){
            mglb[8]=true;
        }
        if(mb[i]=='j' or mb[i]=='J'){
            mglb[9]=true;
        }
        if(mb[i]=='k' or mb[i]=='K'){
            mglb[10]=true;
        }
        if(mb[i]=='l' or mb[i]=='L'){
            mglb[11]=true;
        }
        if(mb[i]=='m' or mb[i]=='M'){
            mglb[12]=true;
        }
        if(mb[i]=='n' or mb[i]=='N'){
            mglb[13]=true;
        }
        if(mb[i]=='o' or mb[i]=='O'){
            mglb[14]=true;
        }
        if(mb[i]=='p' or mb[i]=='P'){
            mglb[15]=true;
        }
        if(mb[i]=='q' or mb[i]=='Q'){
            mglb[16]=true;
        }
        if(mb[i]=='r' or mb[i]=='R'){
            mglb[17]=true;
        }
        if(mb[i]=='s' or mb[i]=='S'){
            mglb[18]=true;
        }
        if(mb[i]=='t' or mb[i]=='T'){
            mglb[19]=true;
        }
        if(mb[i]=='u' or mb[i]=='U'){
            mglb[20]=true;
        }
        if(mb[i]=='v' or mb[i]=='V'){
            mglb[21]=true;
        }
        if(mb[i]=='w' or mb[i]=='W'){
            mglb[22]=true;
        }
        if(mb[i]=='x' or mb[i]=='X'){
            mglb[23]=true;
        }
        if(mb[i]=='y' or mb[i]=='Y'){
            mglb[24]=true;
        }
        if(mb[i]=='z' or mb[i]=='Z'){
            mglb[25]=true;
        }
    }
    }
    if(mglb[0]==true){
        cout<<'A';
    }
    if(mglb[1]==true){
        cout<<'B';
    }
    if(mglb[2]==true){
        cout<<'C';
    }
    if(mglb[3]==true){
        cout<<'D';
    }
    if(mglb[4]==true){
        cout<<'E';
    }
    if(mglb[5]==true){
        cout<<'F';
    }
    if(mglb[6]==true){
        cout<<'G';
    }
    if(mglb[7]==true){
        cout<<'H';
    }
    if(mglb[8]==true){
        cout<<'I';
    }
    if(mglb[9]==true){
        cout<<'J';
    }
    if(mglb[10]==true){
        cout<<'K';
    }
    if(mglb[11]==true){
        cout<<'L';
    }
    if(mglb[12]==true){
        cout<<'M';
    }
    if(mglb[13]==true){
        cout<<'N';
    }
    if(mglb[14]==true){
        cout<<'O';
    }
    if(mglb[15]==true){
        cout<<'P';
    }
    if(mglb[16]==true){
        cout<<'Q';
    }
    if(mglb[17]==true){
        cout<<'R';
    }
    if(mglb[18]==true){
        cout<<'S';
    }
    if(mglb[19]==true){
        cout<<'T';
    }
    if(mglb[20]==true){
        cout<<'U';
    }
    if(mglb[21]==true){
        cout<<'V';
    }
    if(mglb[22]==true){
        cout<<'W';
    }
    if(mglb[23]==true){
        cout<<'X';
    }
    if(mglb[24]==true){
        cout<<'Y';
    }
    if(mglb[25]==true){
        cout<<'Z';
    }
    return 0;
}
