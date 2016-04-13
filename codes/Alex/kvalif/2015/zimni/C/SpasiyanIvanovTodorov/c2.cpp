#include<iostream>
using namespace std;
int main(){
int xa=0,ya=0,xb=0,yb=0,broyach=0,broyach2=0;
cin>>xa>>ya;
int sborovea[200],sboroveb[200];
int broyacha=0,broyachb=0;
int naimalkoa=3000001,naimalkob=3000001;
int matrixa[100][100],matrixb[100][100];
for(broyach=0;broyach<100;broyach++){
    for(broyach2=0;broyach2<100;broyach2++){
        matrixa[broyach][broyach2]=0;
        matrixb[broyach][broyach2]=0;
    }
}
for(broyach=0;broyach<xa;broyach++){
    for(broyach2=0;broyach2<ya;broyach2++){
         cin>>matrixa[broyach][broyach2];
         sborovea[broyacha]+=matrixa[broyach][broyach2];
    }
    if(naimalkoa>sborovea[broyacha]){
        naimalkoa=sborovea[broyacha];
    }
    broyacha++;
}
cin>>xb>>yb;
for(broyach=0;broyach<xb;broyach++){
    for(broyach2=0;broyach2<yb;broyach2++){
         cin>>matrixb[broyach][broyach2];
         sboroveb[broyachb]+=matrixb[broyach][broyach2];
    }
       if(naimalkob>sboroveb[broyachb]){
        naimalkob=sboroveb[broyachb];
    }
    broyachb++;

}
for(broyach2=0;broyach2<ya;broyach2++){
  for(broyach=0;broyach<xa;broyach++){
  sborovea[broyacha]+=matrixa[broyach][broyach2];
  }
     if(naimalkoa>sborovea[broyacha]){
        naimalkoa=sborovea[broyacha];
    }
broyacha++;

}
for(broyach2=0;broyach2<yb;broyach2++){
  for(broyach=0;broyach<xb;broyach++){
  sboroveb[broyachb]+=matrixb[broyach][broyach2];
  }
       if(naimalkob>sboroveb[broyachb]){
        naimalkob=sboroveb[broyachb];
    }
broyachb++;
;
}
int kraena=0,pomneshta=0;
if(naimalkoa>0){
for(broyach=naimalkoa;broyach>=1;broyach--){
    for(broyach2=0;broyach2<broyacha;broyach2++){
        if(sborovea[broyach2]%broyach==0){
            kraena++;
        }
    }
    if(kraena==broyacha){
            cout<<broyach<<" ";
            pomneshta=broyach;
        break;
    }else{
    kraena=0;
    }
}
}else{
for(broyach=-naimalkoa;broyach>=1;broyach--){
    for(broyach2=0;broyach2<broyacha;broyach2++){
        if(sborovea[broyach2]%broyach==0){
            kraena++;
        }
    }
    if(kraena==broyacha){
            cout<<broyach<<" ";
            pomneshta=broyach;
        break;
    }else{
    kraena=0;
    }
}
}
int kraenb=0,pomneshtb=0;
if(naimalkob>0){
for(broyach=naimalkob;broyach>=1;broyach--){
    for(broyach2=0;broyach2<broyachb;broyach2++){
        if(sboroveb[broyach2]%broyach==0){
            kraenb++;
        }
    }
    if(kraenb==broyachb){
            cout<<broyach;
            pomneshtb=broyach;
        break;
    }else{
    kraenb=0;
    }
}
}else{
for(broyach=-naimalkob;broyach>=1;broyach--){
    for(broyach2=0;broyach2<broyachb;broyach2++){
        if(sboroveb[broyach2]%broyach==0){
            kraenb++;
        }
    }
    if(kraenb==broyachb){
            cout<<broyach;
            pomneshtb=broyach;
        break;
    }else{
    kraenb=0;
    }
}
}
cout<<endl;
if(pomneshta>pomneshtb){
    if(pomneshta%pomneshtb==0){
        cout<<"Y"<<endl;
    }else{
    cout<<"N"<<endl;
    }
}else{
if(pomneshtb%pomneshta==0){
        cout<<"Y"<<endl;
    }else{
    cout<<"N"<<endl;
    }
}
return 0;
}
/*
3 3
7 9 2
5 4 6
3 5 4
4 2
4 5
2 7
6 3
6 3
*/

