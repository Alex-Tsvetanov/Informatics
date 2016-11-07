#include <iostream>
using namespace std;

int main () {
    long long s[3], lv[3], st[3], a, b, Ss, kutii[3], i=0, cenaed[3], cenaobshto[3];
    while (i<3) {
        cin >> s[i] >> lv[i] >> st[i];
        i++;
    }
    cin >> a >> b;

    Ss=4*a*b;
    i=0;
    while (i<3) {
        if (Ss%s[i]!=0) {
            kutii[i]=(Ss/s[i]) +1;
        } else {
            kutii[i]=Ss/s[i];
        }
        i++;
    }

    i=0;
    while (i<3) {
        cenaed[i]=lv[i]*100 + st[i]*1;
        i++;
    }

    i=0;
    while (i<3) {
        cenaobshto[i]=kutii[i]*cenaed[i];
        i++;
    }

    if ((cenaobshto[0]<=cenaobshto[1]) and (cenaobshto[0]<=cenaobshto[2])) {
        lv[0]=cenaobshto[0]/100;
        st[0]=cenaobshto[0]%100;
        cout << lv[0] << " " << st[0] << endl;
        return 0;
    }
    if ((cenaobshto[1]<=cenaobshto[0]) and (cenaobshto[1]<=cenaobshto[2])) {
        lv[1]=cenaobshto[1]/100;
        st[1]=cenaobshto[1]%100;
        cout << lv[1] << " " << st[1] << endl;
        return 0;
    }
    if ((cenaobshto[2]<=cenaobshto[0]) and (cenaobshto[2]<=cenaobshto[1])) {
        lv[2]=cenaobshto[2]/100;
        st[2]=cenaobshto[2]%100;
        cout << lv[2] << " " << st[2] << endl;
        return 0;
    }

}
