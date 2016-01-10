#include<iostream>
#include<string>
using namespace std;
int main(){
    string word;
    cin>>word;
    char j,l,p;
    long long len=word.size(),br[len],razlika,i,k;

    for(i=0; i<len; i++){
            l=word[i];
            if('l'>='a' and 'l'<='z'){
                razlika='z'-'l';
                word[i]='Z'-razlika;

            }

    }
    for(k=0; k<len; k++){
        for(i=0; i<len; i++){
            if(word[k]==word[i]){

                br[k]++;
            }
        }
    }
    for(k=len-1; k>0; k--){
        for(i=0; i<k-1; i++){
            if(br[k]>br[i]){
                j=word[k];
                word[k]=word[i];
                word[i]=j;
            }
        }
    }
    for(i=0; i<6; i++){
            cout<<word[i];
    }
return 0;
}
