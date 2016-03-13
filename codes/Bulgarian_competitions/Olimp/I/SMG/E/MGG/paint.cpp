#include <iostream>
using namespace std;
int main () {

    long long a, b, c, d, e, f, g, h, i, j, k;
    long long del, del2, del3, proiz;
    long long lev, lev2, lev3, stot, stot2, stot3;
    cin >> a;
    cin >> b;
    cin >> c;
    cin >> d;
    cin >> e;
    cin >> f;
    cin >> g;
    cin >> h;
    cin >> i;
    cin >> j;
    cin >> k;
    if ((0 >= a) || (0 > d) || (0 >= g) || (100 < a) || (100 < d) || (100 < g) || (0 >= j) || (0 >= k) || (25 < j) || (25 < k)) {
        return 0;
    }
    proiz = j * k * 4;
    if (proiz % a != 0) {
        del = proiz / a + 1;
    }
    else {
        del = proiz / a;
    }
    if (proiz % d != 0) {
        del2 = proiz / d + 1;
    }
    else {
        del2 = proiz / d;
    }
    if (proiz % g != 0) {
        del3 = proiz / g + 1;
    }
    else {
        del3 = proiz / g;
    }

    while (del > 0) {
        lev = lev + b;
        stot = stot + c;
        del = del - 1;
    }
    while (del2 > 0) {
        lev2 = lev2 + e;
        stot2 = stot2 + f;
        del2 = del2 - 1;
    }
    while (del3 > 0) {
        lev3 = lev3 + h;
        stot3 = stot3 + i;
        del3 = del3 - 1;
    }

    while (stot >= 100) {
        lev = lev + 1;
        stot = stot - 100;
    }
    while (stot2 >= 100) {
        lev2 = lev2 + 1;
        stot2 = stot2 - 100;
    }
    while (stot3 >= 100) {
        lev3 = lev3 + 1;
        stot3 = stot3 - 100;
    }
    if ((lev > lev2 > lev3) || (lev > lev2 == lev3)) {
        cout << lev << " " << stot;
        return 0;
    }
    else if (lev > lev2 < lev3) {
        if (lev > lev3) {
            cout << lev << " " << stot;
            return 0;
        }
        else {
            cout << lev3 << " " << stot3;
            return 0;
        }
    }
    else if (lev < lev2 < lev3) {
        cout << lev3 << " " << stot3;
        return 0;
    }
    else if ((lev < lev2 > lev3) || (lev < lev2 == lev3)) {
        if (stot2 > stot3) {
            cout << lev2 << " " << stot2;
            return 0;
        }
        else {
            cout << lev3 << " " << stot3;
            return 0;
        }
    }
    else if (lev == lev2 > lev3) {
        if (stot > stot2) {
            cout << lev << " " << stot;
            return 0;
        }
        else {
            cout << lev2 << " " << stot2;
            return 0;
        }
    }
    else if (lev == lev2 < lev3) {
        cout << lev3 << " " << stot3;
        return 0;
    }
    else if (lev == lev2 == lev3) {
        if (stot > stot2 > stot3) {
            cout << lev << " " << stot;
            return 0;
        }
    }
    else if (stot > stot2 < stot3) {
        if (stot > stot3) {
            cout << lev << " " << stot;
            return 0;
        }
        else {
            cout << lev3 << " " << stot3;
            return 0;
        }
    }
    else if (stot < stot2 > stot3) {
        cout << lev2 << " " << stot2;
        return 0;
    }
    else if (stot < stot2 < stot3) {
        cout << lev3 << " " << stot3;
        return 0;
    }

    return 0;
}
