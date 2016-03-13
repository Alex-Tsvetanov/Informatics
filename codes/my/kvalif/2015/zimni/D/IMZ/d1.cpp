#include <iostream>
using namespace std;
long long Numbers[25];
unsigned WhichNumber;
int main(){
    cin >> Numbers[1] >> Numbers[2] >> Numbers[3] >> WhichNumber;
    if(WhichNumber < 4){
        cout << Numbers[WhichNumber];
        goto EndProgram;
    }
    for(unsigned i = 4; i <= 20; i++){
        Numbers[i] = Numbers[i - 1] + Numbers[i - 2] + Numbers[i - 3];
        if(i == WhichNumber){
            cout << Numbers[i];
            goto EndProgram;
        }
    }
    EndProgram:;
    cout << endl;
    return 0;
}

