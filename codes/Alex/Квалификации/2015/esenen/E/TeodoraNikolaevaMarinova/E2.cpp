#include <iostream>
using namespace std;

int main() {
    long long m, c, k, dyljina_samo_v_cm;
    cin >> m >> c;
    cin >> k;

    dyljina_samo_v_cm = m*100 + c;

    cout << (dyljina_samo_v_cm * k) / 100 << " " << (dyljina_samo_v_cm * k) % 100 << endl;
    return 0;
}
