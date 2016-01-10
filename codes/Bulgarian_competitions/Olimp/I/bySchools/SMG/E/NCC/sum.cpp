#include <iostream>
using namespace std;
int main(){
long long A,B,C,D,a,b,c,d,e,f;
char z;
A,B>99;
A,B<1000;
A=100*a+10*b+c;
B=100*d+10*e+f;
cin>>A>>z>>B;
if((c+f)>9 and (b+e)<10){
    C=(A+B)-10;
    cout<<C<<"\n";
}
if((b+e)>9 and (c+f)<10){
    C=(A+B)-100;
    cout<<C<<"\n";
}
if((c+f)>9 and (b+e)>9){
    C=(A+B)-110;
    cout<<C<<"\n";
}
if((c+f)<10 and (b+e)<10){
    C=A+B;
    cout<<C<<"\n";
}
D=A+B;
cout<<D;

return 0;
}
