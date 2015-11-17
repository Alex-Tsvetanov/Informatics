#include <iostream>
using namespace std;
int main(){
    long long Number, TheLowestAdding = 70000;
    cin >> Number;
    for(long long RectangleX = 1, RectangleY, Adding; RectangleX <= Number; RectangleX++){
        if(Number % RectangleX == 0){
            RectangleY = Number / RectangleX;
            if(RectangleX > RectangleY){
                goto endOfProgram;
            }
            Adding = RectangleX * 2 + RectangleY * 2;
            if(TheLowestAdding > Adding){
                TheLowestAdding = Adding;
            }
        }
    }
    endOfProgram:;

    cout << TheLowestAdding;
    return 0;
}
