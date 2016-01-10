#include <iostream>
using namespace std;

int main() {
    char A, B, C, D;
    long long E, R = 0, X = 0;
    long long a = 1;
    cin >> A;
    while (a > 0){
        if (A == 88){
            R = 1;
        }else{
            cin >> B;
            cin >> C;
            while (a > 0){
                if (C == 88){
                    R = 2;
                }else{
                    cin >> D;
                    cin >> E;
                }
            }
        }
        if (R == 1){
            X = E - C;
            break;
        }
        if (R == 2){
            X = E - A;
            break;
        }
        cin >> A;
    }
    cout << X;
    return 0;
}
