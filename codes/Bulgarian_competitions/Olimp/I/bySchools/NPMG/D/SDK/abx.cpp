#include<iostream>
#include<cstring>
using namespace std;
int main(){
    char izraz[1000];
    long long i, nsb, nch, j, br=0;
    bool ravno=false;
    cin>>izraz;
    for(i=0;i<strlen(izraz);i++){
        if(izraz[i]=='='){
            ravno=true;
        }
        if(ravno==true){
            j=strlen(izraz)-(i+1);
            if(j==1){
                nsb=izraz[i+1]-'0';
                break;
            }
            if(j==2){
                nsb=((izraz[i+1]-'0')*10)+(izraz[i+2]-'0');
                break;
            }
            if(j==3){
                nsb=((izraz[i+1]-'0')*100)+((izraz[i+2]-'0')*10)+(izraz[i+3]-'0');
                break;
            }
            if(j==4){
                nsb=((izraz[i+1]-'0')*1000)+((izraz[i+2]-'0')*100)+((izraz[i+3]-'0')*10)+(izraz[i+4]);
            }
        }
    }
    for(i=0;i<strlen(izraz)-j;i++){
        if(izraz[i]>='0' and izraz[i]<='9'){
            br++;
        }
    }
    for(i=0;i<strlen(izraz)-j;i++){
        if(izraz[i]>='0' and izraz[i]<='9'){
            if(br==1){
                nch=izraz[i]-'0';
            }
            if(br==2){
                nch=((izraz[i]-'0')*10)+(izraz[i+1]-'0');
                break;
            }
            if(br==3){
                nch=((izraz[i]-'0')*100)+((izraz[i+1]-'0')*10)+(izraz[i+2]-'0');
                break;
            }
            if(br==4){
                nch=((izraz[i]-'0')*1000)+((izraz[i+1]-'0')*100)+((izraz[i+2]-'0')*10)+(izraz[i+3]-'0');
                break;
            }
        }
    }
    cout<<nsb-nch;
    return 0;
}
