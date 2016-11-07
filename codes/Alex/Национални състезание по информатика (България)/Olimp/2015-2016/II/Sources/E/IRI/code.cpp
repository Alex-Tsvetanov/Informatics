#include<iostream>
using namespace std;
int main()
{
    long long razlika=0, duljinaNaTexta=0, kodirane=0, i=0, mqstoVkoda=0;
    char text[1000000], kodiranText[1000000], bukvaZakodirane[1];
    bool vuvejdane=true;
    while(vuvejdane){
        cin>>text[i];
        if(text[i]=='.'){
            vuvejdane=false;
            duljinaNaTexta=i-1;
        }
        i++;
    }
    /*i=0;
    while(i<duljinaNaTexta){
            if(text[0]!=text[1]){
                mqstoVkoda++;
                kodiranText[0]=text[0];
                i=1;
            }
        for(i=i;text[i]==text[i-1] && i<duljinaNaTexta;i++){
            bukvaZakodirane[0]=text[i];
            kodirane++;
        }
        if(kodirane>1){
            kodiranText[mqstoVkoda]=kodirane;
            mqstoVkoda++;
            kodiranText[mqstoVkoda]=bukvaZakodirane[0];
            mqstoVkoda++;
        }else{
        kodiranText[mqstoVkoda]=bukvaZakodirane[0];
        }
    }*/

cout<<kodiranText;
return 0;

}
