#include <iostream>
using namespace std;
bool FoundTheCase, WhenToStartToCount;
char BrokenMasiv[1060], SymbolsINeedToCopy[1060], TheWall;
int NumberOfSymbolsInBrokenMasiv, WallPosition, NumberOfSymbolsINeedToCopy;
int main(){
    cin >> NumberOfSymbolsInBrokenMasiv >> BrokenMasiv;
    for(int i = 1; ; i++){
        if(i == NumberOfSymbolsInBrokenMasiv - 1){
            TheWall = BrokenMasiv[i];
            WallPosition = NumberOfSymbolsInBrokenMasiv - 1;
            goto OutOfCheckingForWall;
        }
        if(i < NumberOfSymbolsInBrokenMasiv - 1){
            for(int BackSymbol = i - 1, FrontSymbol = i + 1; FrontSymbol <= NumberOfSymbolsInBrokenMasiv - 1 or BackSymbol >= 0; BackSymbol--, FrontSymbol++){
                if(BrokenMasiv[BackSymbol] == BrokenMasiv[FrontSymbol]){
                    if(FrontSymbol == NumberOfSymbolsInBrokenMasiv - 1){
                        goto IDefinetlyGotTheWall;
                    }
                }
                if(BrokenMasiv[BackSymbol] != BrokenMasiv[FrontSymbol]){
                    goto SearchForOtherWall;
                }
            }
            IDefinetlyGotTheWall:;

            TheWall = BrokenMasiv[i];
            WallPosition = i;
            FoundTheCase = true;
            goto OutOfCheckingForWall;
        }
        SearchForOtherWall:;

    }
    OutOfCheckingForWall:;

    NumberOfSymbolsINeedToCopy = WallPosition - (NumberOfSymbolsInBrokenMasiv - (WallPosition + 1));
    if(NumberOfSymbolsINeedToCopy == 0){
        cout << "0\n";
        goto EndProgram;
    }
    cout << NumberOfSymbolsINeedToCopy << "\n";
    for(int i = 0; i < NumberOfSymbolsINeedToCopy; i++){
        SymbolsINeedToCopy[i] = BrokenMasiv[i];
    }
    for(int i = NumberOfSymbolsINeedToCopy - 1; i >= 0; i--){
        cout << SymbolsINeedToCopy[i];
    }
    cout << "\n";
    EndProgram:;

    return 0;
}
