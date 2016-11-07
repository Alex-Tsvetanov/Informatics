#include <iostream>
#include <algorithm>
using namespace std;
long long AmountOfNumbers, AllNumbers[1000006], ThatOneGuy[1000006], BiggnesOfSorted;
int main(){
    cin >> AmountOfNumbers;
    for(long long i = 1; i <= AmountOfNumbers; i++){
        cin >> AllNumbers[i];
    }
    for(long long i = 1, z = 1; i <= AmountOfNumbers - 1; i++, z = 1){
        BiggnesOfSorted = AmountOfNumbers - i;
        for(long long j = i + 1; j <= AmountOfNumbers; j++, z++){
            ThatOneGuy[z] = AllNumbers[j];
        }
        sort(ThatOneGuy + 1, ThatOneGuy + z + 1);
        if(AllNumbers[i] >= ThatOneGuy[z]){
            cout << AllNumbers[i] << " ";
        }
    }
    cout << AllNumbers[AmountOfNumbers] << endl;
    return 0;
}
