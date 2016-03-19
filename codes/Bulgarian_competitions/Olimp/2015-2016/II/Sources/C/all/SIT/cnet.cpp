#include<iostream>
#include<stdio.h>
using namespace std;
int purvo[40000],vtoro[40000];
bool dostignati[40000];

int tursi (int,int);
int main(){
int broi=0,brvruzki=0;
cin>>broi>>brvruzki;
for(int i=0;i<brvruzki;i++){
    cin>>purvo[i]>>vtoro[i];

}
for(int i=0;i<brvruzki;i++){
    tursi(i,brvruzki);
    for(int j=0;j<brvruzki;j++){
        dostignati[j]=0;
    }
}
return 0;
}
int tursi(int a,int b){
    dostignati[a]=true;
for(int i=0;i<b;i++){
 if(purvo[i]==a and dostignati[vtoro[i]]==false){
    dostignati[vtoro[i]]=true;

 }
}
for(int i=0;i<b;i++){
    if(dostignati[i]==true and i!=a){
     tursi(i,b);
    }
}
}
/*
8 13
0 1
0 2
1 3
3 0
7 1
3 5
4 1
4 5
7 5
5 2
5 6
4 7
7 4
*/
