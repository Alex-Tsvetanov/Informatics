#include <iostream>
using namespace std;

int main() {
    long long M, N, broi;
    broi = 0;
    cin >> M >> N;
    if ((M > 1000) or (N > 1000)){
        M = 1;
        N = 1;
        cout << "1 < M,N < 1000";
    }
    while (M > 1){
        if (M % 2 == 0){
            M = M / 2;
            broi = broi + 1;
        }else{
            M = M - 1;
            if (M % 2 == 0){
                M = M / 2;
                broi = broi + 1;
                M = M + 1;
            }
        }
    }
    while (N > 1){
        if (N % 2 == 0){
            N = N / 2;
            broi = broi + 1;
        }else{
            N = N - 1;
            if (N % 2 == 0){
                N = N / 2;
                broi = broi + 1;
                N = N + 1;
            }
        }
    }
    cout << broi << endl;
    return 0;
}
