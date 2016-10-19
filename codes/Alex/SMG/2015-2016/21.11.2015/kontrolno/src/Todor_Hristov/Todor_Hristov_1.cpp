#include <iostream>
#include <string>
using namespace std;
int main () {
    string a, b;
    bool x = 0,y = 0;
    cin >> a >> b;
    int firstH = a[0] * 10 + a[1],secondH = b[0] * 10 + b[1];
    int firstM = a[3] * 10 + a[4],secondM = b[3] * 10 + b[4];
    int c,d;
    //cout << a[0];
    if (firstH < secondH){
        c = secondH - firstH;
        if (secondM - firstM < 0){
            c--;
            d = secondM - firstM + 60;
        } else {
            d = secondM - firstM;
        }
        if (c < 9){
            x = 1;
        }
        if (d < 9){
            y = 1;
        }
        if (x == 0 && y == 0){
            cout << c << ":" << d;
        } else if (x == 1 && y == 0){
            cout << "0" << c << ":" << d;
        } else if (x == 0 && y == 1){
            cout << c << ":" << "0" << d;
        } else {
            cout << "0" << c << ":" << "0" << d;
        }
    } else if (firstH == secondH) {
        if (secondM - firstM < 0){
            cout << "23" << ":" << secondM - firstM + 60;
        } else if (secondM - firstM == 0){
            cout << "00:00";
        } else {
            if (secondM - firstM > 9){
                cout << "00:" << secondM - firstM;
            } else {
                cout << "00:0" << secondM - firstM;
            }
        }
    } else {
        c = secondH - firstH + 24;
        if (secondM - firstM < 0){
            c--;
            d = secondM - firstM + 60;
        } else {
            d = secondM - firstM;
        }
        if (c < 9){
            x = 1;
        }
        if (d < 9){
            y = 1;
        }
        if (x == 0 && y == 0){
            cout << c << ":" << d;
        } else if (x == 1 && y == 0){
            cout << "0" << c << ":" << d;
        } else if (x == 0 && y == 1){
            cout << c << ":" << "0" << d;
        } else {
            cout << "0" << c << ":" << "0" << d;
        }
    }
    return 0;
}
//
