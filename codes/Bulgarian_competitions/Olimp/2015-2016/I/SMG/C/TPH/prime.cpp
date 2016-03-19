#include <iostream>
#include <string.h>
#include <math.h>
using namespace std;
int main ( ) {
    int sum = 0;
    char num[3001];
    cin >> num;
    bool predst[3001];
    int br;
    br = strlen(num);
    for (int i = 0; i < br; i++){
        predst[i] = num[i] - '0';
    }
    if (predst[0] == 1) sum +=2;
    if (predst[1] == 1) sum +=3;

    int neshto = 2;

    for (int prime = 5; neshto < br; prime++){
        bool k = 0;
        for(int delitel = 2; delitel < sqrt(prime) + 1;delitel++){
            if (prime % delitel == 0){
                k = 1;
                break;
            }
        }
        if (k == 0){
            if (predst[neshto] == 1){
                sum += prime;
            }
            neshto++;
        }
    }
    cout << sum;
    return 0;
}
