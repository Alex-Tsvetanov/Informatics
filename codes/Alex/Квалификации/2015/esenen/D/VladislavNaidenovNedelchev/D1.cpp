#include <iostream>
using namespace std;

int main (){

    long long N, P, a, b, T, T2;
    cin >> N;

    if (N < 30000){
        for (a = 0; a <= N; a = a + 1){
            for (b = 0; b <= a; b = b + 1){
                if (N == a * b){
                    P = a * 2 + b * 2;
                    cout << P << endl;
                }
            }
        }
    }else{
        cout << endl << "1 < N < 30000 !" << endl;
    }
    return 0;
}
