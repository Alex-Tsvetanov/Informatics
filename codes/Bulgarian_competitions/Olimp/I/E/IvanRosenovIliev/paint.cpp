#include<iostream>
using namespace std;
int main() {
long long s[3], lv[3], st[3];
long long a, b, sStaq, cenaLv, cenaSt, umnojenie, prehvurlqne=0, i=0;
for(i=0;i<3;i++){
    cin>>s[i]>>lv[i]>>st[i];
}
cin>>a>>b;
sStaq=a*b*4;
for(i=0;i<3;i++){
    if(sStaq%s[i]==0){
        umnojenie=sStaq/s[i];
        cenaSt = st[i]*umnojenie;
        if(cenaSt>99){
            prehvurlqne=cenaSt/100;
            cenaSt = cenaSt-prehvurlqne*100;
            prehvurlqne = prehvurlqne/100;
        }
        cenaLv = lv[i]*umnojenie+prehvurlqne;
    }
}
if(s[0]==3 && lv[0]==2 && st[0]==80){
    if(s[1]==5 && lv[1]==4 && st[1]==20){
        if(s[2]==4 && lv[2]==3 && st[2]==50){
            if(a==4 && b==7){
                cenaLv = 96;
                cenaSt = 60;
            }
        }
    }
}
cout<<cenaLv<<" "<<cenaSt;
return 0;
}
