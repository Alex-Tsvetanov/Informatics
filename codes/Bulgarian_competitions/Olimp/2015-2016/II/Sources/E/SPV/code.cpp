#include<iostream>
using namespace std;

int main(){

char code[1000000];
int i=0, l, letters=0, br=0, br2=1, br3=0;

cin>>code;

while(1){
    if(code[i]){
        letters++;
    }else{
        break;
    }
    i++;
}

for(l=0; l<code[letters]; l++){
    if(code[l]==code[l+1]){
        br++;
    }else if(code[l]!=code[l+1]){
        br2++;
        if(br>=1&&br<=9){
            br3++;
        }else if(br>=10&&br<=99){
            br3+=2;
        }else if(br>=100&&br<=999){
            br3+=3;
        }else if(br>=1000&&br<=9999){
            br3+=4;
        }else if(br>=10000&&br<=99999){
            br3+=5;
        }else if(br>=100000&&br<=999999){
            br3+=6;
        }
        br=0;
    }
}
cout<<letters-(br2+br3);
}
