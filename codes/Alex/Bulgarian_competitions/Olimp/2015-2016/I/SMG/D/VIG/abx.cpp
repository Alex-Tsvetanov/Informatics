#include<iostream>
#include<cstring>
using namespace std;
int main(){
    long long a=0, b=0, i, len;
    char vhod[10];
    cin>>vhod;
    len=strlen(vhod);
    if(vhod[0]=='X'){
        i=2;
        while(vhod[i]!='='){
            a+=vhod[i]-'0';
            a*=10;
            i++;
        }
        a/=10;
        i++;
        while(i<len){
            b+=vhod[i]-'0';
            b*=10;
            i++;
        }
        b/=10;
    }
    else{
        for(i=0;vhod[i]!='+';i++){
            a+=vhod[i]-'0';
            a*=10;
        }
        a/=10;
        i+=3;
        while(i<len){
            b+=vhod[i]-'0';
            b*=10;
            i++;
        }
        b/=10;
    }
    cout<<b-a<<endl;
    return 0;
}
