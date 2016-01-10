#include <iostream>
using namespace std;

int main() {

    long long a, b, izhoda, izhodb , a1, a2, a3, b1, b2, b3;
    char pl;

    cin >> a  >> pl >> b;

    a1 = a%10;
    a2 = a/10%10;
    a3 = a/100%10;
    b1 = b%10;
    b2 = b/10%10;
    b3 = b/100%10;

    izhoda = a+b;
    izhodb = izhoda;

    if (a1+b1 >= 10){
        izhodb = izhoda-10;
    }
    if (a2+b2 >= 100){
        izhodb = izhoda-100;
    }

    cout << izhodb << endl << izhoda << endl;

    return 0;
}
