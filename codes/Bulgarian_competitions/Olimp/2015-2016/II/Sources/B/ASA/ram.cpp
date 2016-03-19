#include <iostream>

using namespace std;
int const S = 10000;
int main()
{
    long long K;
    int s=0;
    int a[S][2];
    cin >> K;
    for(int M=0; M<S; M++){
        if(M > K) break;
        for(int N=0; N<S; N++){
            if(N > K) break;
            if((2*M*N - N + M + 1== K)&& M!=0 && M!= 1 && N!=0 && N !=1){
                a[s][0] = M;
                a[s][1] = N;
                s++;
            }
        }
        if(3*M-1==K){
            a[s][0] = 1;
            a[s][1] = M;
            s++;
        }
    }
    cout << s << endl;
    for(int i=s-1; i>=0; i--){
        for(int j=0; j<i; j++){
            if(a[i][0] < a[j][0]) swap(a[i], a[j]);
        }
    }

    for(int i=0; i<s; i++){
        cout <<a[i][0]<<" "<<a[i][1] << endl;
    }
    return 0;
}
