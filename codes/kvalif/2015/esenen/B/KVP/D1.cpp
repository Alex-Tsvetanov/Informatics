#include <iostream>
#include <math.h>

using namespace std;

float n, a [100], b [100], izh, maxi, ind, x, y;

float litse (int p, int o, int l) {
    float stra, strb, strc, P;
    if (a [p] == a [o]) stra = max (b [p], b [o]) - min (b [p], b [o]);
    else {
        if (b [p] == b [o]) stra = max (a [p], a [o]) - min (a [p], a [o]);
        else stra = sqrt ((max (a [p], a [o]) - min (a [p], a [o])) * (max (a [p], a [o]) - min (a [p], a [o])) + (max (b [p], b [o]) - min (b [p], b [o])) * (max (b [p], b [o]) - min (b [p], b [o])));
    }
    if (a [l] == a [o]) strb = max (b [l], b [o]) - min (b [l], b [o]);
    else {
        if (b [l] == b [o]) strb = max (a [l], a [o]) - min (a [l], a [o]);
        else strb = sqrt ((max (a [l], a [o]) - min (a [l], a [o])) * (max (a [l], a [o]) - min (a [l], a [o])) + (max (b [l], b [o]) - min (b [l], b [o])) * (max (b [l], b [o]) - min (b [l], b [o])));
    }
    if (a [p] == a [l]) strc = max (b [p], b [l]) - min (b [p], b [l]);
    else {
        if (b [p] == b [l]) strc = max (a [p], a [l]) - min (a [p], a [l]);
        else strc = sqrt ((max (a [p], a [l]) - min (a [p], a [l])) * (max (a [p], a [l]) - min (a [p], a [l])) + (max (b [p], b [l]) - min (b [p], b [l])) * (max (b [p], b [l]) - min (b [p], b [l])));
    }
    P = (stra + strb + strc) / 2;
    return sqrt (P * (P - stra) * (P - strb) * (P - strc));
}

int main () {
    cin >> n;
    for (int q = 1; n != 0; q ++) {
        for (int i = 0; i < n; i ++) {
            cin >> x >> y;
            a [i] = x;
            b [i] = y;
        }
        for (int i = n; i >= 3; i --) {
            izh += litse (0, n - i + 1, n - i + 2);
        }
        cout << izh << endl;
        if (maxi < izh) {
            maxi = izh;
            ind = q;
        }
        cin >> n;
    }
    cout << ind << endl;
    return 0;
}
