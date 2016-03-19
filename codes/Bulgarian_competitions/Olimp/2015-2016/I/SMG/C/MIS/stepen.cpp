#include <iostream>
#include <cwchar>
using namespace std;
int main () {
long vuvedeno;
long stepen;
long proba;
long nachini;
nachini=0;
stepen=0;
proba=1;
cin>>vuvedeno;


while(proba<vuvedeno-2){
            proba=proba+1;

        while(vuvedeno>1 , vuvedeno%proba==0){
                stepen=stepen+1;
                vuvedeno=vuvedeno/proba;




        }
            if(vuvedeno=1){
                nachini=nachini+1;
            }


}
cout<<nachini;
cout<<"\n";
cout<<proba;
cout<<" ";
cout<<stepen;
return 0;
}
