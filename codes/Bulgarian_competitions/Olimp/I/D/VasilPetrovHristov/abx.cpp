#include<iostream>
using namespace std;
int main(){
char text[100];
long long o=0,p=0,n=0,y=0;
cin>>text;
if(text[0]-48<10){y=0;}else{y=2;}
if(y==2){
    for(o=y; text[o]!='='; o++){
        p=p*10;
        p=p+(text[o]-48);
    }
    o++;
}
if(y==0){
    for(o=y; text[o]!='+'; o++){
        p=p*10;
        p=p+(text[o]-48);
    }
    o+=3;
}
for(o=o; text[o]!='\0';o++){
    n=n*10;
    n=n+(text[o]-48);
}
n=n-p;
cout<<n;
return 0;
}
