#include <iostream>
using namespace std;
int n, vhod[3], res = 0;
pair<int, int> d[3];
bool susedi[100][101];
void reshenie(int dul, int index_na_posleden, int po){
  //  cout << dul << " a\n";
    //cout << dul << " " << index_na_posleden << " " << po <<  endl;
    //cout << vhod[index_na_posleden] << " " << po << " " << ((vhod[index_na_posleden] * po) < 100) << " ";
    //int a;
    //cin >> a;
    if (dul == n) {
        res++;
        return;
    }
    if (dul == 0) {
        for (int seg = 0; seg < 3; ++seg){
            for (int i = 1; vhod[seg] * i < 100; i++) {
                reshenie(2, seg, i);
            }
        }
    } else {
        /*for (int i = 0; i < 3; i++) {
            if (susedi[index_na_posleden][i]) {
                reshenie(dul + 1, i);
            }
        }*/
        for (int seg = 0; seg < 3; ++seg){
            for (int i = 1; vhod[seg] * i < 100; ++i) {
                //cout << "   i " << i << " seg " << seg << " " << vhod[index_na_posleden] * po << " " << vhod[seg] * i << endl;
                if (susedi[vhod[index_na_posleden] * po][vhod[seg] * i]) {
                    //cout << "   vzeh!\n";
                    reshenie(dul + 1, seg, i);
                    //cout << "produljavam\n";
                }
            }
        }
        //cout << "krai\n";
    }
}
int main () {

    cin >> n >> vhod[0] >> vhod[1] >> vhod[2];

    if (n == 2) {
        for (int i = vhod[0]; i < 100; i += vhod[0]) {
            res ++;
        }
        for (int i = vhod[1]; i < 100; i += vhod[1]) {
            res ++;
        }
        for (int i = vhod[2]; i < 100; i += vhod[2]) {
            res ++;
        }
        //cout << res << "\n";
        return 0;
    }

    for (int i = vhod[0]; i < 100; i += vhod[0]) {
        for (int j = vhod[0] * 2; j < 100; j += vhod[0]) {
            if (i % 10 == j / 10) { // i != j and
                susedi[i][j] = true;
            }
            if (j % 10 == i / 10) { //i != j and
                susedi[j][i] = true;
            }
        }
    }

    for (int i = vhod[1]; i < 100; i += vhod[1]) {
        for (int j = vhod[1] * 2; j < 100; j += vhod[1]) {
            if (i % 10 == j / 10) { // i != j and
                susedi[i][j] = true;
            }
            if (j % 10 == i / 10) { //i != j and
                susedi[j][i] = true;
            }
        }
    }

    for (int i = vhod[2]; i < 100; i += vhod[2]) {
        for (int j = vhod[2] * 2; j < 100; j += vhod[2]) {
            if (i % 10 == j / 10) { // i != j and
                susedi[i][j] = true;
            }
            if (j % 10 == i / 10) { //i != j and
                susedi[j][i] = true;
            }
        }
    }

    for (int i = vhod[0]; i < 100; i += vhod[0]) {
        for (int j = vhod[1]; j < 100; j += vhod[1]) {
            if (i % 10 == j / 10) { // i != j and
                susedi[i][j] = true;
            }
            if (j % 10 == i / 10) { //i != j and
                susedi[j][i] = true;
            }
        }
    }
    for (int i = vhod[1]; i < 100; i += vhod[1]) {
        for (int j = vhod[2]; j < 100; j += vhod[2]) {
            if (i % 10 == j / 10) { //i != j and
                susedi[i][j] = true;
            }
            if (j % 10 == i / 10) { //i != j and
                susedi[j][i] = true;
            }
        }
    }
    for (int i = vhod[0]; i < 100; i += vhod[0]) {
        for (int j = vhod[2]; j < 100; j += vhod[2]) {
            if (i % 10 == i / 10) { //i != j and
                susedi[i][j] = true;
            }
            if (j % 10 == i / 10) { //i != j and
                susedi[j][i] = true;
            }
        }
    }
    reshenie(0, -1, -1);
    cout << res << "\n";
    return 0;
}
