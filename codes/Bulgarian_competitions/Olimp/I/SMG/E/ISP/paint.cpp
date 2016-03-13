#include <iostream>
using namespace std;

int main() {

 long long s[3], lv[3], st[3], i=0, a, b, sNaStaqta, cena[3], cenaNaEdnaKofa[3], broiKofi, buf;

 while (i<3) {
  cin >> s[i] >> lv[i] >> st[i];
  cenaNaEdnaKofa[i]=lv[i]*100+st[i];
  i++;
 }
 cin >> a >> b;

 sNaStaqta=a*b*4;

 i=0;

 while (i<3) {
  if (sNaStaqta%s[i]==0) {
   broiKofi=sNaStaqta/s[i];
  }

  else {broiKofi=(sNaStaqta/s[i])+1;}

  cena[i]=broiKofi*cenaNaEdnaKofa[i];

  i++;
 }

 if (cena[1]<cena[0]) {
  buf=cena[0];
  cena[0]=cena[1];
  cena[1]=buf;
 }

 if (cena[2]<cena[0]) {
  buf=cena[0];
  cena[0]=cena[2];
  cena[2]=buf;
 }

 cout << cena[0]/100 << " " << cena[0]%100 << endl;

 return 0;
}
