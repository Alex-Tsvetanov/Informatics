#include <iostream>
bool IsThisAcceptable[30];
char Word;
int AllWords[30], Winners[8];
long long TheBiggest, TheNumberBiggest;
int main(){
    Word = 'a';
    while(true){
        std::cin >> Word;
        if(Word == '#'){
            goto EndIt;
        }
        if(Word == 'a' or Word == 'A'){
            AllWords[1]++;
        }
        if(Word == 'b' or Word == 'B'){
            AllWords[2]++;
        }
        if(Word == 'c' or Word == 'C'){
            AllWords[3]++;
        }
        if(Word == 'd' or Word == 'D'){
            AllWords[4]++;
        }
        if(Word == 'e' or Word == 'E'){
            AllWords[5]++;
        }
        if(Word == 'f' or Word == 'F'){
            AllWords[6]++;
        }
        if(Word == 'g' or Word == 'G'){
            AllWords[7]++;
        }
        if(Word == 'h' or Word == 'H'){
            AllWords[8]++;
        }
        if(Word == 'i' or Word == 'I'){
            AllWords[9]++;
        }
        if(Word == 'j' or Word == 'J'){
            AllWords[10]++;
        }
        if(Word == 'k' or Word == 'K'){
            AllWords[11]++;
        }
        if(Word == 'l' or Word == 'L'){
            AllWords[12]++;
        }
        if(Word == 'm' or Word == 'M'){
            AllWords[13]++;
        }
        if(Word == 'n' or Word == 'N'){
            AllWords[14]++;
        }
        if(Word == 'o' or Word == 'O'){
            AllWords[15]++;
        }
        if(Word == 'p' or Word == 'P'){
            AllWords[16]++;
        }
        if(Word == 'q' or Word == 'Q'){
            AllWords[17]++;
        }
        if(Word == 'r' or Word == 'R'){
            AllWords[18]++;
        }
        if(Word == 's' or Word == 'S'){
            AllWords[19]++;
        }
        if(Word == 't' or Word == 'T'){
            AllWords[20]++;
        }
        if(Word == 'u' or Word == 'U'){
            AllWords[21]++;
        }
        if(Word == 'v' or Word == 'V'){
            AllWords[22]++;
        }
        if(Word == 'w' or Word == 'W'){
            AllWords[23]++;
        }
        if(Word == 'x' or Word == 'X'){
            AllWords[24]++;
        }
        if(Word == 'y' or Word == 'Y'){
            AllWords[25]++;
        }
        if(Word == 'z' or Word == 'Z'){
            AllWords[26]++;
        }
    }
    EndIt:;

    for(unsigned i = 0; i < 6; i++){
        for(unsigned Counter = 1; Counter <= 26; Counter++){
            if(TheBiggest < AllWords[Counter] and AllWords[Counter] != -1){
                TheBiggest = AllWords[Counter];
                TheNumberBiggest = Counter;
            }
            if(Counter == 26){
                AllWords[TheNumberBiggest] = -1;
            }
        }
        TheBiggest = 0;
        Winners[i] = TheNumberBiggest;
        if(Winners[i] == 1 and !IsThisAcceptable[1]){
            IsThisAcceptable[1] = true;
            std::cout << "A";
        }
        if(Winners[i] == 2 and !IsThisAcceptable[2]){
            IsThisAcceptable[2] = true;
            std::cout << "B";
        }
        if(Winners[i] == 3 and !IsThisAcceptable[3]){
            IsThisAcceptable[3] = true;
            std::cout << "C";
        }
        if(Winners[i] == 4 and !IsThisAcceptable[4]){
            IsThisAcceptable[4] = true;
            std::cout << "D";
        }
        if(Winners[i] == 5 and !IsThisAcceptable[5]){
            IsThisAcceptable[5] = true;
            std::cout << "E";
        }
        if(Winners[i] == 6 and !IsThisAcceptable[6]){
            IsThisAcceptable[6] = true;
            std::cout << "F";
        }
        if(Winners[i] == 7 and !IsThisAcceptable[7]){
            IsThisAcceptable[7] = true;
            std::cout << "G";
        }
        if(Winners[i] == 8 and !IsThisAcceptable[8]){
            IsThisAcceptable[8] = true;
            std::cout << "H";
        }
        if(Winners[i] == 9 and !IsThisAcceptable[9]){
            IsThisAcceptable[9] = true;
            std::cout << "I";
        }
        if(Winners[i] == 10 and !IsThisAcceptable[10]){
            IsThisAcceptable[10] = true;
            std::cout << "J";
        }
        if(Winners[i] == 11 and !IsThisAcceptable[11]){
            IsThisAcceptable[11] = true;
            std::cout << "K";
        }
        if(Winners[i] == 12 and !IsThisAcceptable[12]){
            IsThisAcceptable[12] = true;
            std::cout << "L";
        }
        if(Winners[i] == 13 and !IsThisAcceptable[13]){
            IsThisAcceptable[13] = true;
            std::cout << "M";
        }
        if(Winners[i] == 14 and !IsThisAcceptable[14]){
            IsThisAcceptable[14] = true;
            std::cout << "N";
        }
        if(Winners[i] == 15 and !IsThisAcceptable[15]){
            IsThisAcceptable[15] = true;
            std::cout << "O";
        }
        if(Winners[i] == 16 and !IsThisAcceptable[16]){
            IsThisAcceptable[16] = true;
            std::cout << "P";
        }
        if(Winners[i] == 17 and !IsThisAcceptable[17]){
            IsThisAcceptable[17] = true;
            std::cout << "Q";
        }
        if(Winners[i] == 18 and !IsThisAcceptable[18]){
            IsThisAcceptable[18] = true;
            std::cout << "R";
        }
        if(Winners[i] == 19 and !IsThisAcceptable[19]){
            IsThisAcceptable[19] = true;
            std::cout << "S";
        }
        if(Winners[i] == 20 and !IsThisAcceptable[20]){
            IsThisAcceptable[20] = true;
            std::cout << "T";
        }
        if(Winners[i] == 21 and !IsThisAcceptable[21]){
            IsThisAcceptable[21] = true;
            std::cout << "U";
        }
        if(Winners[i] == 22 and !IsThisAcceptable[22]){
            IsThisAcceptable[22] = true;
            std::cout << "V";
        }
        if(Winners[i] == 23 and !IsThisAcceptable[23]){
            IsThisAcceptable[23] = true;
            std::cout << "W";
        }
        if(Winners[i] == 24 and !IsThisAcceptable[24]){
            IsThisAcceptable[24] = true;
            std::cout << "X";
        }
        if(Winners[i] == 25 and !IsThisAcceptable[25]){
            IsThisAcceptable[25] = true;
            std::cout << "Y";
        }
        if(Winners[i] == 26 and !IsThisAcceptable[26]){
            IsThisAcceptable[26] = true;
            std::cout << "Z";
        }
    }
    std::cout << "\n";
    return 0;
}
