#include<iostream>
using namespace std;
int main () {
char a;
long long first1=0,second1=0,first2=0,second2,first3,second3,cifra=1;
cin>>a;
first3=first3+a;
cin>>a;
first2=first2+a;
cin>>a;
first1=first1+a;
/*for(cifra=1;cifra<4;cifra=cifra+1){
    if(cifra==1){
        second3=a;
    }
    if(cifra==2){
        second2=a;
    }
    if(cifra==3){
        second1=a;
    }
    cin>>a;
}*/
cout<<first3<<first2<<first1/*<<" "<<second1<<second2<<second3*/;
//cout<<(first3+second3)<<(first2+second2)%10<<(first1+second1)%10<<endl;
//cout<<first3+second3<<first2+second2<<first1+second1<<endl;
return 0;
}
