#include <iostream>
using namespace std;
int main () {
    long long x, y, d, razmerisamowsantimetri, srednastrana, strana, strana2;
    cin >> x;
    cin >> y;
    cin >> d;
    razmerisamowsantimetri = 100 * x + y;
    srednastrana = razmerisamowsantimetri / 4;
    strana = srednastrana + (d / 2);
    strana2 = srednastrana - (d / 2);
    cout << strana / 100 << " " << strana % 100 << endl;
    cout << strana2 / 100 << " " << strana2 % 100 << endl;

    return 0;
}
