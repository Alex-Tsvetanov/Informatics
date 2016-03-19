#include <iostream>
using namespace std;
bool Table[205][205];
long long TableX, TableY, AmountOfAds, PositionXOfAds[20], PositionYOfAds[20], BiggnesOfAdsX[20], BiggnesOfAdsY[20], FirstRezult, SecondRezult;
int main(){
    cin >> TableX >> TableY >> AmountOfAds;
    if(AmountOfAds == 0){
        cout << TableX * TableY << endl;
        goto EndIt;
    }
    for(int i = 1; i <= AmountOfAds; i++){
        cin >> PositionXOfAds[i] >> PositionYOfAds[i] >> BiggnesOfAdsX[i] >> BiggnesOfAdsY[i];
        PositionXOfAds[i]++;
        PositionYOfAds[i]++;
    }
    for(int i = 1; i <= AmountOfAds; i++){
        for(int y = PositionYOfAds[i]; y <= BiggnesOfAdsY[i]; y++){
            for(int x = PositionXOfAds[i]; x <= BiggnesOfAdsX[i]; x++){
                Table[x][y] = true;
            }
        }
    }
    for(int x = TableX, y = TableY; ; x--){
        for(int ay = 1; ay <= TableY; ay++){
            for(int ax = 1; ax <= TableX; ax++){
                if(Table[ax][ay]){
                    goto NotThisDay;
                }
            }
        }
        FirstRezult = x * y;
        NotThisDay:;

    }
    for(int x = TableX, y = TableY; ; y--){
        for(int ay = 1; ay <= TableY; ay++){
            for(int ax = 1; ax <= TableX; ax++){
                if(Table[ax][ay]){
                    goto NotThisDay1;
                }
            }
        }
        SecondRezult = x * y;
        NotThisDay1:;

    }
    if(FirstRezult == SecondRezult){
        cout << FirstRezult << endl;
        goto EndIt;
    }
    if(FirstRezult > SecondRezult){
        cout << FirstRezult << endl;
    }else{
        cout << SecondRezult << endl;
    }
    EndIt:;

    return 0;
}
