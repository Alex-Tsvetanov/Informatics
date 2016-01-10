#include <iostream>

using namespace std;

int main(){
    
    //Declarations
    int amount;
    int smallest;
    int biggest;
    int input;
    int lengthIncr;
    int lengthDecr;
    cin>>amount;
    int a[amount];
    
    //Value input
    cin>>input;
    smallest = input;
    biggest = input;
    
    int increasingIni = input;
    int increasingEnd = input;
    int decreasingIni = input;
    int decreasingEnd = input;
    
    for (int i = 1; i<amount; i++){
        cin>>input;
        a[i] = input;
        if (input < smallest) {
            smallest = input;
            increasingIni = i+1;
        }
        if (input > biggest) {
            biggest = input;
            decreasingIni = i+1;
        } 
        if (input >= biggest) {
            increasingEnd = i+1;
        }
        if (input <= smallest) {
            decreasingEnd = i+1;
        }
    } 
    
    lengthIncr = increasingEnd - increasingIni + 1;
    lengthDecr = decreasingEnd - decreasingIni + 1;
    
    if (lengthDecr > lengthIncr) {
        cout << increasingIni << " " << increasingEnd;
    } else if (lengthDecr < lengthIncr) {
        cout << decreasingIni << " " << decreasingEnd;
    } else {
        int sumIncr = increasingEnd + increasingIni;
        int sumDecr = decreasingEnd + decreasingIni;
        
        if (sumIncr < sumDecr) {
            cout << increasingIni << " " << increasingEnd;
        } else{
            cout << decreasingIni << " " << decreasingEnd;
        }
    }
    
    return 0;
}