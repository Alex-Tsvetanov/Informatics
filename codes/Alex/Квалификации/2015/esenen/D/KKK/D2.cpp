#include<iostream>
using namespace std;
    char pole[30][30];
    void fillPole(int x,int y){
        pole[x][y]='X';
    }
int main(){
    int col,rol;
    char a;
    cin.get(a);
    cin>>rol;
    col=a-'a'+1;
    int col1,rol1;
    cin.get(a);
    cin.get(a);
    cin>>rol1;
    col1=a-'a';
    for(int i=0;i<30;i++){
        for(int j=0;j<30;j++){
            pole[j][i]='O';
        }
    }
    col1+=2;
    rol1+=1;
    int b;
    if(rol/10<1){
        b=0;
    }else{
    b=1;
    }
    pole[col1][rol1]='H';

    fillPole(col1-1,rol1-2);
    fillPole(col1+1,rol1-2);
    fillPole(col1-1,rol1+2);
    fillPole(col1+1,rol1+2);
    fillPole(col1-2,rol1-1);
    fillPole(col1+2,rol1-1);
    fillPole(col1-2,rol1+1);
    fillPole(col1+2,rol1+1);
    if(b==1){
        cout<<" ";
    }
    cout<<"  ";
    for(int i=0;i<col;i++){
        cout<<(char)(i+'a');
    }
    cout<<endl;
    for(int y=2;y<rol+2;y++){
            if(b==1 and (y-1)/10<1){
                cout<<" ";
            }
            cout<<y-1<<" ";
        for(int x=2;x<col+2;x++){
            cout<<pole[x][y];
        }
        cout<<endl;
    }
return 0;
}
