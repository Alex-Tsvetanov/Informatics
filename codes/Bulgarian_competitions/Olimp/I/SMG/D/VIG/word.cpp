#include<iostream>
#include<conio.h>
int b[26], kolko, i, ng, j, k;
char a;
using namespace std;
int main(){
    a=_getch();
    while(a!='#'){
        if(a>='a' and a<='z'){
            if(!b[a-'a']){
                kolko++;
            }
            b[a-'a']++;
            if(b[a-'a']>ng)ng=b[a-'a'];
        }
        if(a>='A' and a<='Z'){
            if(!b[a-'A']){
                kolko++;
            }
            b[a-'A']++;
            if(b[a-'A']>ng)ng=b[a-'A'];
        }
        a=_getch();
    }
    j=ng;
    for(int p=0;p<kolko and p<6;j--){
        for(i=0;i<26;i++){
            if(b[i]==j){
                a='A'+i;
                cout<<a;
                p++;
            }
            if(p>=kolko or p>=6)break;
        }
    }
    cout<<endl;
    return 0;
}
