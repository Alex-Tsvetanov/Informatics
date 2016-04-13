#include <iostream>
#include <string>
#include <algorithm>
using namespace std;
bool kak (char a, char b) {
    return (a - '0') > (b - '0');
}
int main () {
char vhod[2>>1000], mini[2>>1000];
unsigned long long nuli, dul, Mdul;
    nuli = 0;
    dul = 0;
    cin >> vhod;
        //cout << nuli << endl;
    for (int i = 0; vhod[i] != '\0'; ++i) {
        //cout << i << " " << nuli << endl;
        if (vhod[i] == '0') {
                //cout << "NULA\n";
                ++nuli;
        }
        ++dul;
    }
    sort(vhod, vhod + dul, kak);
    //cout << vhod[8] << " a " <<  vhod[7] << " " << dul - 1 - nuli << endl;
    mini[0] = vhod[dul - 1 - nuli];
    //cout << mini[0];
    Mdul = 1;
    for (int i = 0; i < nuli; ++i) {
        mini[Mdul] = '0';
        ++Mdul;
    }
    for (int i = dul - nuli - 1; i >= 0; --i) {
        mini[i] = vhod[i];
        Mdul++;
    }
    cout << "0" << endl;
    return 0;
}
