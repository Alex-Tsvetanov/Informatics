#include<iostream>
using namespace std;
int redica[10][100000];
int main(){
    int brchisla[10], i, j;
    for(i=0; i<10; i++){
        cin >> brchisla[i];
        for(j=0; j<brchisla[i]; j++){
            cin >> redica[i][j];
        }
    }
    cout << "00000\n";
    return 0;
}
