#include <iostream>
using namespace std;
int main (){
    char vhod[6];
    int chas1, min1, chas2, min2, res_chas, res_min;
    cin >> vhod;
    chas1 = (vhod[0] - '0') * 10 + vhod[1] - '0';
    min1 = (vhod[3] - '0') * 10 + vhod[4] - '0';
    cin >> vhod;
    chas2 = (vhod[0] - '0') * 10 + vhod[1] - '0';
    min2 = (vhod[3] - '0') * 10 + vhod[4] - '0';
    if (chas1 < chas2) {
        res_chas = chas2 - chas1;
    }
    else {
        res_chas = 24 - chas1 + chas2;
    }
    if (min1 < min2) {
        res_min = min2 - min1;
    } else {
        res_chas--;
        res_min = 60 + min2 - min1;
    }
    cout << res_chas << " " << res_min << "\n";
    return 0;
}
