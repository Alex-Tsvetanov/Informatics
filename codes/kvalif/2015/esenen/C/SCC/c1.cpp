#include <iostream>
using namespace std;
int n, m, poznanstva[501][502], br_priateli[501], a, b, res, seg;
bool uvedomen_li_e[501], koi[501], svurshih_li, vsichki_li;
void uvedomi(int koi) {
    for (int i = 0; i < br_priateli[koi]; ++i) {
        uvedomi(poznanstva[koi][i]);
    }
    uvedomen_li_e[koi] = true;
}
int main () {
    cin >> n >> m;
    res = n;
    for (int i = 0; i< n; ++i) {
        br_priateli[i] = 0;
    }
    for (int i = 0; i < m; ++i) {
        cin >> a >> b;
        a--;
        b--;
        poznanstva[a][br_priateli[a]] = b;
        poznanstva[b][br_priateli[b]] = a;
    }
    for (int i = 1; seg <= n + 1; i++) {
        a = i;
        seg = 0;
        for (int j = 0; a; ++j) {
            koi[j] = a % 2;
            if (koi[j]) {
                seg++;
            }
            a /= 2;
        }
        if (seg == 0) seg = 1;
        for (int j = 0; j < n; j++) {
            uvedomen_li_e[j] = false;
        }
        for (int p = 0; p < n; ++p) {
            if (koi[p]) {
                uvedomi(p);
            }
        }
        vsichki_li = true;
        for (int j = 0; j < n; j++) {
            if (!uvedomen_li_e[j]) {
                vsichki_li = false;
            }
        }
        if (vsichki_li and seg < res) res = seg;
    }
    cout << res;
    return 0;
}
