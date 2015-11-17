#include <iostream>
using namespace std;
int main(){
    bool IsThisHorseAttackPossible[10];
    char FieldStatistics[30], UntilThisLetter, HorseStatistics[30], HorseLetterPosition, StartingPointForFieldX = 'a';
    long long UntilThisNumber = 30, HorseNumberPosition = 30, HowMuchLine, HorseLetterPositionDefragged = 1, PositionsForHorseAttacksX[10], PositionsForHorseAttacksY[10];
    cin >> FieldStatistics >> HorseStatistics;
    UntilThisLetter = FieldStatistics[0];
    HorseLetterPosition = HorseStatistics[0];
    for(long long HorseAttacks = 1; HorseAttacks <= 8; HorseAttacks++){
        IsThisHorseAttackPossible[HorseAttacks] = true;
    }
    if(FieldStatistics[1] == '9' or FieldStatistics[1] == '8' or FieldStatistics[1] == '7' or FieldStatistics[1] == '6' or FieldStatistics[1] == '5' or FieldStatistics[1] == '4' or FieldStatistics[1] == '3'){
        if(FieldStatistics[1] == '9'){
            UntilThisNumber = 9;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '8'){
            UntilThisNumber = 8;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '7'){
            UntilThisNumber = 7;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '6'){
            UntilThisNumber = 6;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '5'){
            UntilThisNumber = 5;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '4'){
            UntilThisNumber = 4;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '3'){
            UntilThisNumber = 3;
            goto endOfNumber;
        }
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '0'){
        UntilThisNumber = 10;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '1'){
        UntilThisNumber = 11;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '2'){
        UntilThisNumber = 12;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '3'){
        UntilThisNumber = 13;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '4'){
        UntilThisNumber = 14;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '5'){
        UntilThisNumber = 15;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '6'){
        UntilThisNumber = 16;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '7'){
        UntilThisNumber = 17;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '8'){
        UntilThisNumber = 18;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '1' and FieldStatistics[2] == '9'){
        UntilThisNumber = 19;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '0'){
        UntilThisNumber = 20;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '1'){
        UntilThisNumber = 21;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '2'){
        UntilThisNumber = 22;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '3'){
        UntilThisNumber = 23;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '4'){
        UntilThisNumber = 24;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '5'){
        UntilThisNumber = 25;
        goto endOfNumber;
    }
    if(FieldStatistics[1] == '2' and FieldStatistics[2] == '6'){
        UntilThisNumber = 26;
        goto endOfNumber;
    }
    if(UntilThisNumber == 30){
        if(FieldStatistics[1] == '1'){
            UntilThisNumber = 1;
            goto endOfNumber;
        }
        if(FieldStatistics[1] == '2'){
            UntilThisNumber = 2;
            goto endOfNumber;
        }
    }
    endOfNumber:;

    if(HorseStatistics[1] == '9' or HorseStatistics[1] == '8' or HorseStatistics[1] == '7' or HorseStatistics[1] == '6' or HorseStatistics[1] == '5' or HorseStatistics[1] == '4' or HorseStatistics[1] == '3'){
        if(HorseStatistics[1] == '9'){
            HorseNumberPosition = 9;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '8'){
            HorseNumberPosition = 8;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '7'){
            HorseNumberPosition = 7;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '6'){
            HorseNumberPosition = 6;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '5'){
            HorseNumberPosition = 5;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '4'){
            HorseNumberPosition = 4;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '3'){
            HorseNumberPosition = 3;
            goto endOfNumberOfHorse;
        }
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '0'){
        HorseNumberPosition = 10;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '1'){
        HorseNumberPosition = 11;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '2'){
        HorseNumberPosition = 12;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '3'){
        HorseNumberPosition = 13;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '4'){
        HorseNumberPosition = 14;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '5'){
        HorseNumberPosition = 15;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '6'){
        HorseNumberPosition = 16;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '7'){
        HorseNumberPosition = 17;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '8'){
        HorseNumberPosition = 18;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '1' and HorseStatistics[2] == '9'){
        HorseNumberPosition = 19;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '0'){
        HorseNumberPosition = 20;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '1'){
        HorseNumberPosition = 21;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '2'){
        HorseNumberPosition = 22;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '3'){
        HorseNumberPosition = 23;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '4'){
        HorseNumberPosition = 24;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '5'){
        HorseNumberPosition = 25;
        goto endOfNumberOfHorse;
    }
    if(HorseStatistics[1] == '2' and HorseStatistics[2] == '6'){
        HorseNumberPosition = 26;
        goto endOfNumberOfHorse;
    }
    if(HorseNumberPosition == 30){
        if(HorseStatistics[1] == '1'){
            HorseNumberPosition = 1;
            goto endOfNumberOfHorse;
        }
        if(HorseStatistics[1] == '2'){
            HorseNumberPosition = 2;
            goto endOfNumberOfHorse;
        }
    }
    endOfNumberOfHorse:;

    for( HowMuchLine = 1; StartingPointForFieldX != UntilThisLetter; HowMuchLine++, StartingPointForFieldX++){}
    StartingPointForFieldX = 'a';
    for( HorseLetterPositionDefragged = 1; StartingPointForFieldX != HorseLetterPosition; HorseLetterPositionDefragged++, StartingPointForFieldX++){}
    for(long long AttacksOfHorse = 1; AttacksOfHorse <= 8; AttacksOfHorse++){
        if(AttacksOfHorse == 1){
            PositionsForHorseAttacksX[1] = HorseLetterPositionDefragged + 1;
            PositionsForHorseAttacksY[1] = HorseNumberPosition - 2;
        }
        if(AttacksOfHorse == 2){
            PositionsForHorseAttacksX[2] = HorseLetterPositionDefragged - 1;
            PositionsForHorseAttacksY[2] = HorseNumberPosition - 2;
        }
        if(AttacksOfHorse == 3){
            PositionsForHorseAttacksX[3] = HorseLetterPositionDefragged - 2;
            PositionsForHorseAttacksY[3] = HorseNumberPosition - 1;
        }
        if(AttacksOfHorse == 4){
            PositionsForHorseAttacksX[4] = HorseLetterPositionDefragged - 2;
            PositionsForHorseAttacksY[4] = HorseNumberPosition + 1;
        }
        if(AttacksOfHorse == 5){
            PositionsForHorseAttacksX[5] = HorseLetterPositionDefragged - 1;
            PositionsForHorseAttacksY[5] = HorseNumberPosition + 2;
        }
        if(AttacksOfHorse == 6){
            PositionsForHorseAttacksX[6] = HorseLetterPositionDefragged + 1;
            PositionsForHorseAttacksY[6] = HorseNumberPosition + 2;
        }
        if(AttacksOfHorse == 7){
            PositionsForHorseAttacksX[7] = HorseLetterPositionDefragged + 2;
            PositionsForHorseAttacksY[7] = HorseNumberPosition + 1;
        }
        if(AttacksOfHorse == 8){
            PositionsForHorseAttacksX[8] = HorseLetterPositionDefragged + 2;
            PositionsForHorseAttacksY[8] = HorseNumberPosition - 1;
        }
    }
    if(PositionsForHorseAttacksX[1] > HowMuchLine or PositionsForHorseAttacksY[1] > UntilThisNumber){
        IsThisHorseAttackPossible[1] = false;
    }
    if(PositionsForHorseAttacksX[2] > HowMuchLine or PositionsForHorseAttacksY[2] > UntilThisNumber){
        IsThisHorseAttackPossible[2] = false;
    }
    if(PositionsForHorseAttacksX[3] > HowMuchLine or PositionsForHorseAttacksY[3] > UntilThisNumber){
        IsThisHorseAttackPossible[3] = false;
    }
    if(PositionsForHorseAttacksX[4] > HowMuchLine or PositionsForHorseAttacksY[4] > UntilThisNumber){
        IsThisHorseAttackPossible[4] = false;
    }
    if(PositionsForHorseAttacksX[5] > HowMuchLine or PositionsForHorseAttacksY[5] > UntilThisNumber){
        IsThisHorseAttackPossible[5] = false;
    }
    if(PositionsForHorseAttacksX[6] > HowMuchLine or PositionsForHorseAttacksY[6] > UntilThisNumber){
        IsThisHorseAttackPossible[6] = false;
    }
    if(PositionsForHorseAttacksX[7] > HowMuchLine or PositionsForHorseAttacksY[7] > UntilThisNumber){
        IsThisHorseAttackPossible[7] = false;
    }
    if(PositionsForHorseAttacksX[8] > HowMuchLine or PositionsForHorseAttacksY[8] > UntilThisNumber){
        IsThisHorseAttackPossible[8] = false;
    }
    StartingPointForFieldX = 'a';
    cout << "  ";
    for(long long WhichLetter = 1; WhichLetter <= HowMuchLine; WhichLetter++, StartingPointForFieldX++){
        cout << StartingPointForFieldX;
    }
    cout << endl;
    for(long long FieldPositionY = 1; FieldPositionY <= UntilThisNumber; FieldPositionY++){
        cout << FieldPositionY << " ";
        for(long long FieldPositionX = 1; FieldPositionX <= HowMuchLine; FieldPositionX++){
            if(PositionsForHorseAttacksX[1] == FieldPositionX and PositionsForHorseAttacksY[1] == FieldPositionY and IsThisHorseAttackPossible[1]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[2] == FieldPositionX and PositionsForHorseAttacksY[2] == FieldPositionY and IsThisHorseAttackPossible[2]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[3] == FieldPositionX and PositionsForHorseAttacksY[3] == FieldPositionY and IsThisHorseAttackPossible[3]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[4] == FieldPositionX and PositionsForHorseAttacksY[4] == FieldPositionY and IsThisHorseAttackPossible[4]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[5] == FieldPositionX and PositionsForHorseAttacksY[5] == FieldPositionY and IsThisHorseAttackPossible[5]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[6] == FieldPositionX and PositionsForHorseAttacksY[6] == FieldPositionY and IsThisHorseAttackPossible[6]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[7] == FieldPositionX and PositionsForHorseAttacksY[7] == FieldPositionY and IsThisHorseAttackPossible[7]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(PositionsForHorseAttacksX[8] == FieldPositionX and PositionsForHorseAttacksY[8] == FieldPositionY and IsThisHorseAttackPossible[8]){
                cout << "X";
                goto MoreImportantLetterDrawn;
            }
            if(FieldPositionX == HorseLetterPositionDefragged and FieldPositionY == HorseNumberPosition){
                cout << "H";
                goto MoreImportantLetterDrawn;
            }
            cout << "O";
            MoreImportantLetterDrawn:;

        }
        cout << endl;
    }
    return 0;
}
