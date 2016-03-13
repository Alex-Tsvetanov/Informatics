#include <iostream>
using namespace std;

int main() {
    long long a, b, c;
    cin >> a >> b >> c;

    if ((a+b!=c) and (a-b!=c) and (a*b!=c)) {
        cout << "0" << endl;
    }
    else {
        if ((a+b==c) and (a-b==c) and (a*b==c)) {
            cout << "+" << endl;
        }
        else {
            if ((a+b==c) or (a-b==c)) {
                if (a+b==c) {
                    cout << "+" << endl;
                }
                else {
                    cout << "-" << endl;
                }
            }
            else {
                if (a*b==c) {
                cout << "*" << endl;
                }
            }

        }
    }
    return 0;
}
