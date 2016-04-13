#include<iostream>
using namespace std;
int main(){
long long A,B,a,b,c,d,e,f,goshovoChislo,istinskoChislo,chislo,chislo10,chislo100;
char znak;
znak='+';
znak='-';
znak='*';
znak='%';
cin>>A>>znak>>B;
istinskoChislo=A+B;
A=100*a+10*b+c;
B=100*d+10*e+f;
chislo=c+f;
chislo10=b+e;
chislo100=a+d;
0<b,c,e,f<10;
1<a,d<10;
if(chislo==10 or 11 or 12 or 13 or 14 or 15 or 16 or 17 or 18){
    goshovoChislo=istinskoChislo-10;
}

cout<<goshovoChislo<<"\n"<<istinskoChislo;

return 0;
}
