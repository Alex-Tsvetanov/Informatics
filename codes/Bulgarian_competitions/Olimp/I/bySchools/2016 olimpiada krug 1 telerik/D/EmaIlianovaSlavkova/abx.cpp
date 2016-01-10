#include<iostream>
#include<string.h>
using namespace std;
int main(){

    string abx;
    cin>>abx;
    long long len,k,i,j,b,mnoj=1,mnoj2=1;
    char b2;
    len=abx.size();
    b2=abx[len-2];


    for(i=len-2; i>=0; i--){

        if(abx[i]=='='){
           i=0;
        }else{
            b=b+abx[i]*(10*mnoj);
            mnoj++;

        }

    }
    char a;
    if(abx[0]=='X'){
            a=abx[len-(mnoj+2)];
        for(i=len-2; i>=0; i--){

            if(abx[i]=='='){
               i=0;
            }else{
                a=a+abx[i]*(10*mnoj2);
                mnoj2++;



            }
        }}

cout<<"-"<<b2<<endl;

return 0;
}
