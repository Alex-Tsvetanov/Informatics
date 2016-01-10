#include <iostream>
using namespace std;

int main () {
    long long m, n, m1=1, n1=1, brm=0, brn=0;
    cin >> m >> n;
    while (m1<m) {
            m1 = 2*m1;
            brm++;
    }
    while (n1<n) {
            n1 = 2*n1;
            brn++;
    }

    cout << brm+brn << endl;
    return 0;
}
