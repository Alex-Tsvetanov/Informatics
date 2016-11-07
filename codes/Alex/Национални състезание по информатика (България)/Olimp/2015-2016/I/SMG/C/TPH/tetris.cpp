#include <iostream>
using namespace std;
int main ( ) {
    int x,y;
    cin >> x >> y;

    int brpov = 0, brred;
    int sum = 0;
    char pole[x][y];
    for (int a = 0; a < x; a++){
        brred = 0;
        for (int b = 0; b < y; b++){
            cin >> pole[a][b];
            if (pole[a][b] == '*'){
                brred++;
            }
        }
        if (brred == y){
            brpov++;
        } else if (brpov > 0){
            sum += (brpov*(brpov + 1))/2;
            brpov = 0;

        }
        if (brred == y && a == x - 1){
            sum += (brpov*(brpov + 1))/2;
        }

    }
    cout << sum;
    return 0;
}

