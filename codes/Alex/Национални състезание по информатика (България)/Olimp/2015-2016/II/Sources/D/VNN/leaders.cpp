#include <iostream>
using namespace std;
int main() {
    long long broi, nomer2 = 0, nomer = 0, chislo[100], max[100];
    cin >> broi;
    nomer2 = broi;
    max[0] = 0;
    while (nomer2 > 0){
        max[nomer2] = 0;
        nomer2--;
    }
    for (nomer = 0; nomer < broi; nomer++){
            cin >> chislo[nomer];
    }
    for(nomer = nomer - 1; nomer >= 0; nomer--){
        if (chislo[nomer] > max[nomer2]){
            nomer2++;
            max[nomer2] = chislo[nomer];
        }
    }
    while (nomer2 > 0){
        cout << max[nomer2] << " ";
        nomer2--;
    }
    return 0;
}
