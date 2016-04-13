#include <iostream>
using namespace std;

int main() {
    long long L, H, broibelejka, X[16], Y[16], a[16], b[16], novX[16], novY[16], nova[16], novb[16], maxS = 0;
    cin >> L >> H >> broibelejka;
    while (broibelejka > 0){
        cin >> X[broibelejka] >> Y[broibelejka] >> a[broibelejka] >> b[broibelejka];
        nova[broibelejka] = 0;
        novb[broibelejka] = 0;
        novX[broibelejka] = 0;
        novY[broibelejka] = 0;
        while (novX[broibelejka] < L){
            if ((X[broibelejka] <= novX[broibelejka]) && (X[broibelejka] + a[broibelejka] >= novX[broibelejka])){
                while (novb[broibelejka] <= X[broibelejka]){
                    novb[broibelejka]++;
                }
            }else{
                while (novb[broibelejka] < H){
                    novb[broibelejka]++;
                }
            }
            if ((Y[broibelejka] <= novY[broibelejka]) && (Y[broibelejka] + b[broibelejka] >= novY[broibelejka])){
                while (nova[broibelejka] <= Y[broibelejka]){
                nova[broibelejka]++;
                }
            }else{
                while (nova[broibelejka] < L){
                    nova[broibelejka]++;
                }
            }
            if (nova[broibelejka] * novb[broibelejka] > maxS){
                maxS = nova[broibelejka] * novb[broibelejka];
            }
            novX[broibelejka]++;
        }
        while (novY[broibelejka] < H){
            if ((X[broibelejka] <= novX[broibelejka]) && (X[broibelejka] + a[broibelejka] >= novX[broibelejka])){
                while (novb[broibelejka] <= X[broibelejka]){
                    novb[broibelejka]++;
                }
            }else{
                while (novb[broibelejka] < H){
                    novb[broibelejka]++;
                }
            }
            if ((Y[broibelejka] <= novY[broibelejka]) && (Y[broibelejka] + b[broibelejka] >= novY[broibelejka])){
                while (nova[broibelejka] <= Y[broibelejka]){
                nova[broibelejka]++;
                }
            }else{
                while (nova[broibelejka] < L){
                    nova[broibelejka]++;
                }
            }
            if (nova[broibelejka] * novb[broibelejka] > maxS){
                maxS = nova[broibelejka] * novb[broibelejka];
            }
            novY[broibelejka]++;
        }
        broibelejka--;
    }
    cout << maxS;
    return 0;
}
