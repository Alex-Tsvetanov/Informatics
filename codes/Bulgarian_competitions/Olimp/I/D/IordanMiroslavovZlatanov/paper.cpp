#include <iostream>
int MainX, MainY, Answer, CuttingX, CuttingY;
int main(){
    std::cin >> MainX >> MainY;
    while(MainX != 1 or MainY != 1){
        if(MainX != 1){
            if(MainX % 2 == 0){
                MainX = MainX / 2;
                Answer++;
            }else{
                CuttingX = MainX / 2;
                MainX = MainX - CuttingX;
                Answer++;
            }
        }
        if(MainY != 1){
            if(MainY % 2 == 0){
                MainY = MainY / 2;
                Answer++;
            }else{
                CuttingY = MainY / 2;
                MainY = MainY - CuttingY;
                Answer++;
            }
        }
    }
    std::cout << Answer << "\n";
    return 0;
}
