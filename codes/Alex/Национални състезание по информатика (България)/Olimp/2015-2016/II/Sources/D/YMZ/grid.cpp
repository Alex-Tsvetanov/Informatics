#include <iostream>
using namespace std;
bool HaveIFoundARezult, HaveIFoundAZero, IHaveJustAdded;
long long Grid[210][210], BiggnesGridX, BiggnesGridY, Rezult = 1;
int main(){
    cin >> BiggnesGridX >> BiggnesGridY;
    for(int y = 1; y <= BiggnesGridY; y++){
        for(int x = 1; x <= BiggnesGridX; x++){
            cin >> Grid[x][y];
            if(Grid[x][y] == 1){
                Grid[x][y] = -1;
            }
        }
    }
    while(true){
        for(int y = 1; y <= BiggnesGridY; y++){
            for(int x = 1; x <= BiggnesGridX; x++){
                if(Grid[x][y] == 0){
                    if(IHaveJustAdded){
                        Grid[x][y] = Rezult;
                        IHaveJustAdded = false;
                        goto SkipThisTurn;
                    }
                    HaveIFoundAZero = true;
                    if(x + 1 <= BiggnesGridX){
                        if(Grid[x + 1][y] == Rezult){
                            Grid[x][y] = Rezult;
                            HaveIFoundARezult = true;
                        }
                    }
                    if(x - 1 > 0){
                        if(Grid[x - 1][y] == Rezult){
                            Grid[x][y] = Rezult;
                            HaveIFoundARezult = true;
                        }
                    }
                    if(y + 1 <= BiggnesGridY){
                        if(Grid[x][y + 1] == Rezult){
                            Grid[x][y] = Rezult;
                            HaveIFoundARezult = true;
                        }
                    }
                    if(y - 1 > 0){
                        if(Grid[x][y - 1] == Rezult){
                            Grid[x][y] = Rezult;
                            HaveIFoundARezult = true;
                        }
                    }
                }
            }
        }
        if(!HaveIFoundAZero){
            cout << Rezult - 1 << endl;
            goto EndIt;
        }
        HaveIFoundAZero = false;
        if(!HaveIFoundARezult){
            Rezult++;
            IHaveJustAdded = true;
        }
        HaveIFoundARezult = false;
        SkipThisTurn:;

    }
    EndIt:;

    return 0;
}
