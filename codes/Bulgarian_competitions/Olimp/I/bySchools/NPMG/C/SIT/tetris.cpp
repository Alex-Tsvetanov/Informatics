#include<iostream>
#include<cstring>
#include<cmath>
using namespace std;
int main(){
    bool krai=0,krai2=0;
long long dulj=0,shir=0,x=0,y=0,broyach=0,poreditsa=0,tochki=0,broyach2=0;
cin>>dulj>>shir;
char pole[100][100];
for(x=0;x<dulj;x++){
    for(y=0;y<shir;y++){
        cin>>pole[x][y];
    }
}
for(x=dulj-1;krai!=true;x--){
    for(y=0;y<shir;y++){
        if(pole[x][y]=='*'){
           broyach++;
        }
    }
    if(broyach==shir){
poreditsa++;
 for(y=0;y<shir;y++){
     pole[x][y]='.';
 }
    }else{
      tochki+=poreditsa*(poreditsa+1)/2;
    krai=true;
    }
    broyach=0;
}

krai=false;
poreditsa=0;
broyach=0;

while(krai2==false){
    //    cout<<"da";
for(x=0;x<dulj;x++){
    for(y=0;y<shir;y++){
if(pole[x][y]=='.'){
    broyach2++;
}
    }
}
if(broyach2>dulj*shir-4){
    krai2=true;
}else{
broyach2=0;
}
  for(x=dulj-1;krai!=true;x--){
    for(y=0;y<shir;y++){
        if(pole[x][y]=='*'){
           broyach++;
        }
    }
    if(broyach==shir){
poreditsa++;
 for(y=0;y<shir;y++){
     pole[x][y]='.';
 }
    }else{
      tochki+=poreditsa*(poreditsa+1)/2;
    krai=true;
    }
    broyach=0;
}
 for(x=dulj-1;x>=0;x--){
    for(y=0;y<shir;y++){
     if(pole[x][y]=='*' and pole[x+1][y]!='*'and x!=dulj-1){
        pole[x][y]='.';
        pole[x+1][y]='*';
     }
    }
 }
 krai=false;
poreditsa=0;

}
cout<<tochki;
return 0;
}
/*
5 4
**.*
****
....
****
****
*/
