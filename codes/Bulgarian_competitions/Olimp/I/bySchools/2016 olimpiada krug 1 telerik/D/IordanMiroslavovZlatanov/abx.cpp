#include <iostream>
bool SecondNumberHardFinding = false;
char AllNumbers[30], ActualFirstNumber[30], ActualSecondNumber[30];
int FirstNumber, SecondNumber, BiggnessOfFirstNumber, BiggnessOfSecondNumber;
int main(){
    std::cin >> AllNumbers;
    if(AllNumbers[0] == 'X'){
        for(unsigned i = 2, j = 0; AllNumbers[i] != '='; i++, j++){
            ActualFirstNumber[j] = AllNumbers[i];
            BiggnessOfFirstNumber++;
        }
        for(unsigned i = 0, j = 0; ; i++){
            if(AllNumbers[i] == '='){
                SecondNumberHardFinding = true;
                goto NextTime;
            }
            if(SecondNumberHardFinding){
                ActualSecondNumber[j] = AllNumbers[i];
                j++;
                BiggnessOfSecondNumber++;
                if(AllNumbers[i + 1] != '0' and AllNumbers[i + 1] != '1' and AllNumbers[i + 1] != '2' and AllNumbers[i + 1] != '3' and AllNumbers[i + 1] != '4' and AllNumbers[i + 1] != '5' and AllNumbers[i + 1] != '6' and AllNumbers[i + 1] != '7' and AllNumbers[i + 1] != '8' and AllNumbers[i + 1] != '9'){
                    goto OutOfThisTrash;
                }
            }
            NextTime:;

        }
        OutOfThisTrash:;

        if(BiggnessOfFirstNumber == 1){
            if(ActualFirstNumber[0] == '1'){
                FirstNumber = 1;
            }
            if(ActualFirstNumber[0] == '2'){
                FirstNumber = 2;
            }
            if(ActualFirstNumber[0] == '3'){
                FirstNumber = 3;
            }
            if(ActualFirstNumber[0] == '4'){
                FirstNumber = 4;
            }
            if(ActualFirstNumber[0] == '5'){
                FirstNumber = 5;
            }
            if(ActualFirstNumber[0] == '6'){
                FirstNumber = 6;
            }
            if(ActualFirstNumber[0] == '7'){
                FirstNumber = 7;
            }
            if(ActualFirstNumber[0] == '8'){
                FirstNumber = 8;
            }
            if(ActualFirstNumber[0] == '9'){
                FirstNumber = 9;
            }
        }
        if(BiggnessOfFirstNumber == 2){
            for(unsigned i = 0, j = 10; i < BiggnessOfFirstNumber; i++, j = j / 10){
                if(ActualFirstNumber[i] == '1'){
                    FirstNumber = FirstNumber + 1 * j;
                }
                if(ActualFirstNumber[i] == '2'){
                    FirstNumber = FirstNumber + 2 * j;
                }
                if(ActualFirstNumber[i] == '3'){
                    FirstNumber = FirstNumber + 3 * j;
                }
                if(ActualFirstNumber[i] == '4'){
                    FirstNumber = FirstNumber + 4 * j;
                }
                if(ActualFirstNumber[i] == '5'){
                    FirstNumber = FirstNumber + 5 * j;
                }
                if(ActualFirstNumber[i] == '6'){
                    FirstNumber = FirstNumber + 6 * j;
                }
                if(ActualFirstNumber[i] == '7'){
                    FirstNumber = FirstNumber + 7 * j;
                }
                if(ActualFirstNumber[i] == '8'){
                    FirstNumber = FirstNumber + 8 * j;
                }
                if(ActualFirstNumber[i] == '9'){
                    FirstNumber = FirstNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfFirstNumber == 3){
            for(unsigned i = 0, j = 100; i < BiggnessOfFirstNumber; i++, j = j / 10){
                if(ActualFirstNumber[i] == '1'){
                    FirstNumber = FirstNumber + 1 * j;
                }
                if(ActualFirstNumber[i] == '2'){
                    FirstNumber = FirstNumber + 2 * j;
                }
                if(ActualFirstNumber[i] == '3'){
                    FirstNumber = FirstNumber + 3 * j;
                }
                if(ActualFirstNumber[i] == '4'){
                    FirstNumber = FirstNumber + 4 * j;
                }
                if(ActualFirstNumber[i] == '5'){
                    FirstNumber = FirstNumber + 5 * j;
                }
                if(ActualFirstNumber[i] == '6'){
                    FirstNumber = FirstNumber + 6 * j;
                }
                if(ActualFirstNumber[i] == '7'){
                    FirstNumber = FirstNumber + 7 * j;
                }
                if(ActualFirstNumber[i] == '8'){
                    FirstNumber = FirstNumber + 8 * j;
                }
                if(ActualFirstNumber[i] == '9'){
                    FirstNumber = FirstNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfFirstNumber == 4){
            for(unsigned i = 0, j = 1000; i < BiggnessOfFirstNumber; i++, j = j / 10){
                if(ActualFirstNumber[i] == '1'){
                    FirstNumber = FirstNumber + 1 * j;
                }
                if(ActualFirstNumber[i] == '2'){
                    FirstNumber = FirstNumber + 2 * j;
                }
                if(ActualFirstNumber[i] == '3'){
                    FirstNumber = FirstNumber + 3 * j;
                }
                if(ActualFirstNumber[i] == '4'){
                    FirstNumber = FirstNumber + 4 * j;
                }
                if(ActualFirstNumber[i] == '5'){
                    FirstNumber = FirstNumber + 5 * j;
                }
                if(ActualFirstNumber[i] == '6'){
                    FirstNumber = FirstNumber + 6 * j;
                }
                if(ActualFirstNumber[i] == '7'){
                    FirstNumber = FirstNumber + 7 * j;
                }
                if(ActualFirstNumber[i] == '8'){
                    FirstNumber = FirstNumber + 8 * j;
                }
                if(ActualFirstNumber[i] == '9'){
                    FirstNumber = FirstNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfSecondNumber == 1){
            if(ActualSecondNumber[0] == '1'){
                SecondNumber = 1;
            }
            if(ActualSecondNumber[0] == '2'){
                SecondNumber = 2;
            }
            if(ActualSecondNumber[0] == '3'){
                SecondNumber = 3;
            }
            if(ActualSecondNumber[0] == '4'){
                SecondNumber = 4;
            }
            if(ActualSecondNumber[0] == '5'){
                SecondNumber = 5;
            }
            if(ActualSecondNumber[0] == '6'){
                SecondNumber = 6;
            }
            if(ActualSecondNumber[0] == '7'){
                SecondNumber = 7;
            }
            if(ActualSecondNumber[0] == '8'){
                SecondNumber = 8;
            }
            if(ActualSecondNumber[0] == '9'){
                SecondNumber = 9;
            }
        }
        if(BiggnessOfSecondNumber == 2){
            for(unsigned i = 0, j = 10; i < BiggnessOfSecondNumber; i++, j = j / 10){
                if(ActualSecondNumber[i] == '1'){
                    SecondNumber = SecondNumber + 1 * j;
                }
                if(ActualSecondNumber[i] == '2'){
                    SecondNumber = SecondNumber + 2 * j;
                }
                if(ActualSecondNumber[i] == '3'){
                    SecondNumber = SecondNumber + 3 * j;
                }
                if(ActualSecondNumber[i] == '4'){
                    SecondNumber = SecondNumber + 4 * j;
                }
                if(ActualSecondNumber[i] == '5'){
                    SecondNumber = SecondNumber + 5 * j;
                }
                if(ActualSecondNumber[i] == '6'){
                    SecondNumber = SecondNumber + 6 * j;
                }
                if(ActualSecondNumber[i] == '7'){
                    SecondNumber = SecondNumber + 7 * j;
                }
                if(ActualSecondNumber[i] == '8'){
                    SecondNumber = SecondNumber + 8 * j;
                }
                if(ActualSecondNumber[i] == '9'){
                    SecondNumber = SecondNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfSecondNumber == 3){
            for(unsigned i = 0, j = 100; i < BiggnessOfSecondNumber; i++, j = j / 10){
                if(ActualSecondNumber[i] == '1'){
                    SecondNumber = SecondNumber + 1 * j;
                }
                if(ActualSecondNumber[i] == '2'){
                    SecondNumber = SecondNumber + 2 * j;
                }
                if(ActualSecondNumber[i] == '3'){
                    SecondNumber = SecondNumber + 3 * j;
                }
                if(ActualSecondNumber[i] == '4'){
                    SecondNumber = SecondNumber + 4 * j;
                }
                if(ActualSecondNumber[i] == '5'){
                    SecondNumber = SecondNumber + 5 * j;
                }
                if(ActualSecondNumber[i] == '6'){
                    SecondNumber = SecondNumber + 6 * j;
                }
                if(ActualSecondNumber[i] == '7'){
                    SecondNumber = SecondNumber + 7 * j;
                }
                if(ActualSecondNumber[i] == '8'){
                    SecondNumber = SecondNumber + 8 * j;
                }
                if(ActualSecondNumber[i] == '9'){
                    SecondNumber = SecondNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfSecondNumber == 4){
            for(unsigned i = 0, j = 1000; i < BiggnessOfSecondNumber; i++, j = j / 10){
                if(ActualSecondNumber[i] == '1'){
                    SecondNumber = SecondNumber + 1 * j;
                }
                if(ActualSecondNumber[i] == '2'){
                    SecondNumber = SecondNumber + 2 * j;
                }
                if(ActualSecondNumber[i] == '3'){
                    SecondNumber = SecondNumber + 3 * j;
                }
                if(ActualSecondNumber[i] == '4'){
                    SecondNumber = SecondNumber + 4 * j;
                }
                if(ActualSecondNumber[i] == '5'){
                    SecondNumber = SecondNumber + 5 * j;
                }
                if(ActualSecondNumber[i] == '6'){
                    SecondNumber = SecondNumber + 6 * j;
                }
                if(ActualSecondNumber[i] == '7'){
                    SecondNumber = SecondNumber + 7 * j;
                }
                if(ActualSecondNumber[i] == '8'){
                    SecondNumber = SecondNumber + 8 * j;
                }
                if(ActualSecondNumber[i] == '9'){
                    SecondNumber = SecondNumber + 9 * j;
                }
            }
        }
        std::cout << SecondNumber - FirstNumber << "\n";
    }else{
        for(unsigned i = 0, j = 0; AllNumbers[i] != '+'; i++, j++){
            ActualFirstNumber[j] = AllNumbers[i];
            BiggnessOfFirstNumber++;
        }



        for(unsigned i = 0, j = 0; ; i++){
            if(AllNumbers[i] == '='){
                SecondNumberHardFinding = true;
                goto NextTime1;
            }
            if(SecondNumberHardFinding){
                ActualSecondNumber[j] = AllNumbers[i];
                j++;
                BiggnessOfSecondNumber++;
                if(AllNumbers[i + 1] != '0' and AllNumbers[i + 1] != '1' and AllNumbers[i + 1] != '2' and AllNumbers[i + 1] != '3' and AllNumbers[i + 1] != '4' and AllNumbers[i + 1] != '5' and AllNumbers[i + 1] != '6' and AllNumbers[i + 1] != '7' and AllNumbers[i + 1] != '8' and AllNumbers[i + 1] != '9'){
                    goto OutOfThisTrash1;
                }
            }
            NextTime1:;

        }
        OutOfThisTrash1:;

        if(BiggnessOfFirstNumber == 1){
            if(ActualFirstNumber[0] == '1'){
                FirstNumber = 1;
            }
            if(ActualFirstNumber[0] == '2'){
                FirstNumber = 2;
            }
            if(ActualFirstNumber[0] == '3'){
                FirstNumber = 3;
            }
            if(ActualFirstNumber[0] == '4'){
                FirstNumber = 4;
            }
            if(ActualFirstNumber[0] == '5'){
                FirstNumber = 5;
            }
            if(ActualFirstNumber[0] == '6'){
                FirstNumber = 6;
            }
            if(ActualFirstNumber[0] == '7'){
                FirstNumber = 7;
            }
            if(ActualFirstNumber[0] == '8'){
                FirstNumber = 8;
            }
            if(ActualFirstNumber[0] == '9'){
                FirstNumber = 9;
            }
        }
        if(BiggnessOfFirstNumber == 2){
            for(unsigned i = 0, j = 10; i < BiggnessOfFirstNumber; i++, j = j / 10){
                if(ActualFirstNumber[i] == '1'){
                    FirstNumber = FirstNumber + 1 * j;
                }
                if(ActualFirstNumber[i] == '2'){
                    FirstNumber = FirstNumber + 2 * j;
                }
                if(ActualFirstNumber[i] == '3'){
                    FirstNumber = FirstNumber + 3 * j;
                }
                if(ActualFirstNumber[i] == '4'){
                    FirstNumber = FirstNumber + 4 * j;
                }
                if(ActualFirstNumber[i] == '5'){
                    FirstNumber = FirstNumber + 5 * j;
                }
                if(ActualFirstNumber[i] == '6'){
                    FirstNumber = FirstNumber + 6 * j;
                }
                if(ActualFirstNumber[i] == '7'){
                    FirstNumber = FirstNumber + 7 * j;
                }
                if(ActualFirstNumber[i] == '8'){
                    FirstNumber = FirstNumber + 8 * j;
                }
                if(ActualFirstNumber[i] == '9'){
                    FirstNumber = FirstNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfFirstNumber == 3){
            for(unsigned i = 0, j = 100; i < BiggnessOfFirstNumber; i++, j = j / 10){
                if(ActualFirstNumber[i] == '1'){
                    FirstNumber = FirstNumber + 1 * j;
                }
                if(ActualFirstNumber[i] == '2'){
                    FirstNumber = FirstNumber + 2 * j;
                }
                if(ActualFirstNumber[i] == '3'){
                    FirstNumber = FirstNumber + 3 * j;
                }
                if(ActualFirstNumber[i] == '4'){
                    FirstNumber = FirstNumber + 4 * j;
                }
                if(ActualFirstNumber[i] == '5'){
                    FirstNumber = FirstNumber + 5 * j;
                }
                if(ActualFirstNumber[i] == '6'){
                    FirstNumber = FirstNumber + 6 * j;
                }
                if(ActualFirstNumber[i] == '7'){
                    FirstNumber = FirstNumber + 7 * j;
                }
                if(ActualFirstNumber[i] == '8'){
                    FirstNumber = FirstNumber + 8 * j;
                }
                if(ActualFirstNumber[i] == '9'){
                    FirstNumber = FirstNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfFirstNumber == 4){
            for(unsigned i = 0, j = 1000; i < BiggnessOfFirstNumber; i++, j = j / 10){
                if(ActualFirstNumber[i] == '1'){
                    FirstNumber = FirstNumber + 1 * j;
                }
                if(ActualFirstNumber[i] == '2'){
                    FirstNumber = FirstNumber + 2 * j;
                }
                if(ActualFirstNumber[i] == '3'){
                    FirstNumber = FirstNumber + 3 * j;
                }
                if(ActualFirstNumber[i] == '4'){
                    FirstNumber = FirstNumber + 4 * j;
                }
                if(ActualFirstNumber[i] == '5'){
                    FirstNumber = FirstNumber + 5 * j;
                }
                if(ActualFirstNumber[i] == '6'){
                    FirstNumber = FirstNumber + 6 * j;
                }
                if(ActualFirstNumber[i] == '7'){
                    FirstNumber = FirstNumber + 7 * j;
                }
                if(ActualFirstNumber[i] == '8'){
                    FirstNumber = FirstNumber + 8 * j;
                }
                if(ActualFirstNumber[i] == '9'){
                    FirstNumber = FirstNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfSecondNumber == 1){
            if(ActualSecondNumber[0] == '1'){
                SecondNumber = 1;
            }
            if(ActualSecondNumber[0] == '2'){
                SecondNumber = 2;
            }
            if(ActualSecondNumber[0] == '3'){
                SecondNumber = 3;
            }
            if(ActualSecondNumber[0] == '4'){
                SecondNumber = 4;
            }
            if(ActualSecondNumber[0] == '5'){
                SecondNumber = 5;
            }
            if(ActualSecondNumber[0] == '6'){
                SecondNumber = 6;
            }
            if(ActualSecondNumber[0] == '7'){
                SecondNumber = 7;
            }
            if(ActualSecondNumber[0] == '8'){
                SecondNumber = 8;
            }
            if(ActualSecondNumber[0] == '9'){
                SecondNumber = 9;
            }
        }
        if(BiggnessOfSecondNumber == 2){
            for(unsigned i = 0, j = 10; i < BiggnessOfSecondNumber; i++, j = j / 10){
                if(ActualSecondNumber[i] == '1'){
                    SecondNumber = SecondNumber + 1 * j;
                }
                if(ActualSecondNumber[i] == '2'){
                    SecondNumber = SecondNumber + 2 * j;
                }
                if(ActualSecondNumber[i] == '3'){
                    SecondNumber = SecondNumber + 3 * j;
                }
                if(ActualSecondNumber[i] == '4'){
                    SecondNumber = SecondNumber + 4 * j;
                }
                if(ActualSecondNumber[i] == '5'){
                    SecondNumber = SecondNumber + 5 * j;
                }
                if(ActualSecondNumber[i] == '6'){
                    SecondNumber = SecondNumber + 6 * j;
                }
                if(ActualSecondNumber[i] == '7'){
                    SecondNumber = SecondNumber + 7 * j;
                }
                if(ActualSecondNumber[i] == '8'){
                    SecondNumber = SecondNumber + 8 * j;
                }
                if(ActualSecondNumber[i] == '9'){
                    SecondNumber = SecondNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfSecondNumber == 3){
            for(unsigned i = 0, j = 100; i < BiggnessOfSecondNumber; i++, j = j / 10){
                if(ActualSecondNumber[i] == '1'){
                    SecondNumber = SecondNumber + 1 * j;
                }
                if(ActualSecondNumber[i] == '2'){
                    SecondNumber = SecondNumber + 2 * j;
                }
                if(ActualSecondNumber[i] == '3'){
                    SecondNumber = SecondNumber + 3 * j;
                }
                if(ActualSecondNumber[i] == '4'){
                    SecondNumber = SecondNumber + 4 * j;
                }
                if(ActualSecondNumber[i] == '5'){
                    SecondNumber = SecondNumber + 5 * j;
                }
                if(ActualSecondNumber[i] == '6'){
                    SecondNumber = SecondNumber + 6 * j;
                }
                if(ActualSecondNumber[i] == '7'){
                    SecondNumber = SecondNumber + 7 * j;
                }
                if(ActualSecondNumber[i] == '8'){
                    SecondNumber = SecondNumber + 8 * j;
                }
                if(ActualSecondNumber[i] == '9'){
                    SecondNumber = SecondNumber + 9 * j;
                }
            }
        }
        if(BiggnessOfSecondNumber == 4){
            for(unsigned i = 0, j = 1000; i < BiggnessOfSecondNumber; i++, j = j / 10){
                if(ActualSecondNumber[i] == '1'){
                    SecondNumber = SecondNumber + 1 * j;
                }
                if(ActualSecondNumber[i] == '2'){
                    SecondNumber = SecondNumber + 2 * j;
                }
                if(ActualSecondNumber[i] == '3'){
                    SecondNumber = SecondNumber + 3 * j;
                }
                if(ActualSecondNumber[i] == '4'){
                    SecondNumber = SecondNumber + 4 * j;
                }
                if(ActualSecondNumber[i] == '5'){
                    SecondNumber = SecondNumber + 5 * j;
                }
                if(ActualSecondNumber[i] == '6'){
                    SecondNumber = SecondNumber + 6 * j;
                }
                if(ActualSecondNumber[i] == '7'){
                    SecondNumber = SecondNumber + 7 * j;
                }
                if(ActualSecondNumber[i] == '8'){
                    SecondNumber = SecondNumber + 8 * j;
                }
                if(ActualSecondNumber[i] == '9'){
                    SecondNumber = SecondNumber + 9 * j;
                }
            }
        }
        std::cout << SecondNumber - FirstNumber << "\n";
    }
    return 0;
}
