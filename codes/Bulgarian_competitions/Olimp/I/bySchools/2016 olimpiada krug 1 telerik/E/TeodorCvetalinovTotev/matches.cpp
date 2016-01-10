#include <iostream>
using namespace std;

int main() {

    long long a, b, c , d , izhod = 2, str1, str2;

    cin >> a >> b >> c >> d;

    if (a == b && c == d) {
        izhod = 1;
        str1 = a;
        str2 = c;
    }

    if (a == c && b == d) {
        izhod = 1;
        str1 = a;
        str2 = b;
    }

    if (a == d && b == c) {
        izhod = 1;
        str1 = a;
        str2 = d;
    }

    if (izhod == 1){
        cout << "YES" << endl << str1*str2 << endl;
    }else{
        cout << "NO" << endl << a+b+c+d << endl;
    }

    return 0;
}
