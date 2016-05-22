#include<iostream>
#include<windows.h>
#include<vector>
#include<cmath>
#include"testAi.h"
#include"testAi2.h"
using namespace std;
struct Coords{
    int x,y;
    Coords(){
        this->x=0;
        this->y=0;
    };
    Coords(int x_,int y_){
        this->x=x_;
        this->y=y_;
    };
    bool operator ==(Coords A){
        if(A.x==this->x && A.y==this->y){
            return 1;
        }
        return 0;
    }
    Coords operator -(Coords A){
        Coords res(A.x - this->x, A.y - this->y);
        return res;
    }
};
class Isola{
private:
    int firstPlayer,fieldSize;
    Coords player1Pos,player2Pos;
    bool field[1000][1000];
    bool playing;

    vector<int> player1Play(vector<int> param);
    vector<int> player2Play(vector<int> param);
    bool validRes(vector<int> res,Coords playerPos);
    void print();
public:
    Isola(int fieldSize_,int firstPlayer_);
    int play();
};
Isola::Isola(int fieldSize_,int firstPlayer_){
    if(!(fieldSize_%2)){
        fieldSize_++;
    }
    this->fieldSize=fieldSize_;
    this->firstPlayer=firstPlayer_;

    if(this->firstPlayer==1){
        this->player1Pos=Coords(this->fieldSize/2+1,1);
        this->player2Pos=Coords(this->fieldSize/2+1,this->fieldSize);
    }
    if(this->firstPlayer==2){
        this->player1Pos=Coords(this->fieldSize/2+1,this->fieldSize);
        this->player2Pos=Coords(this->fieldSize/2+1,1);

    }
    int n=this->fieldSize;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(i==0 || j==0 || i==n+1 || j==n+1){
                this->field[i][j]=1;
            }else{
                this->field[i][j]=0;
            }
        }
    }
}
void Isola::print(){
    int n=this->fieldSize;
    for(int i=0;i<=n+1;i++){
        for(int j=0;j<=n+1;j++){
            if(Coords(j,i)==this->player1Pos){
                cout<<"1";
                continue;
            }
            if(Coords(j,i)==this->player2Pos){
                cout<<"2";
                continue;
            }
            if(this->field[j][i]){
                cout<<"*";
                continue;
            }
            if(!this->field[j][i]){
                cout<<" ";
            }
        }
        cout<<endl;
    }
}
bool Isola::validRes(vector<int> res,Coords playerPos){
    if(!this->playing){
        return 1;
    }
    Coords movePos(res[0],res[1]),shootPos(res[2],res[3]);
    if(!(movePos.x>=1 && movePos.x<=this->fieldSize && movePos.y>=1 && movePos.y<=this->fieldSize)){
        return 0;
    }
    if(!(shootPos.x>=1 && shootPos.x<=this->fieldSize && shootPos.y>=1 && shootPos.y<=this->fieldSize)){
        return 0;
    }
    Coords dist=playerPos-movePos;
    if(abs(dist.x)>1 || abs(dist.y)>1){
        cout<<dist.x<<" "<<dist.y<<endl;
        return 0;
    }
    if(this->field[movePos.x][movePos.y]==1){

        return 0;
    }
    if(this->field[shootPos.x][shootPos.y]==1){
        return 0;
    }
    if(player1Pos==movePos || player2Pos==movePos){
        return 0;
    }
    return 1;
}
vector<int> Isola::player1Play(vector<int> param){
    //change name of function here
    vector<int> res=testAi(param);

    if(validRes(res,this->player1Pos)){
        if(this->playing){
            field[res[2]][res[3]]=1;
            player1Pos=Coords(res[0],res[1]);
        }
        return res;
    }else{
        res.push_back(0);
        return res;
    }
}
vector<int> Isola::player2Play(vector<int> param){
    //change name of function here
    vector<int> res=testAi2(param);

    if(validRes(res,this->player2Pos)){
        if(this->playing){
            field[res[2]][res[3]]=1;
            player2Pos=Coords(res[0],res[1]);
        }
        return res;
    }else{
        res.push_back(0);
        return res;
    }
}
int Isola::play(){
    int sleepTimeMS=1000;
    cout<<"Starting game of Isola on field with a size of: "<<this->fieldSize<<endl<<"The first player to play will be: "<<this->firstPlayer<<endl;
    this->print();
    this->playing=0;
    vector<int> beginParam1,beginParam2;
    beginParam1.push_back(this->fieldSize);
    if(this->firstPlayer==1){
        beginParam1.push_back(1);
    }else{
        beginParam1.push_back(2);
    }
    beginParam1.push_back(this->player1Pos.x);
    beginParam1.push_back(this->player1Pos.y);
    beginParam1.push_back(this->player2Pos.x);
    beginParam1.push_back(this->player2Pos.y);

    beginParam2.push_back(this->fieldSize);
    if(this->firstPlayer==2){
        beginParam1.push_back(1);
    }else{
        beginParam1.push_back(2);
    }
    beginParam2.push_back(this->player2Pos.x);
    beginParam2.push_back(this->player2Pos.y);
    beginParam2.push_back(this->player1Pos.x);
    beginParam2.push_back(this->player1Pos.y);


    Isola::player1Play(beginParam1);
    Isola::player2Play(beginParam2);
    this->playing=1;
    vector<int> resP1,resP2;

    if(this->firstPlayer==1){
        vector<int> voidP;
        resP1=Isola::player1Play(voidP);
        if(!resP1.back()){
            cout<<"Player 1 Lost";
            return 1;
        }
        print();
        Sleep(sleepTimeMS);

        resP2=Isola::player2Play(resP1);
        if(!resP2.back()){
            cout<<"Player 2 Lost";
            return 2;
        }
        print();
        Sleep(sleepTimeMS);

    }
    if(this->firstPlayer==2){
        vector<int> voidP;
        resP2=Isola::player2Play(voidP);
        if(!resP2.back()){
            cout<<"Player 1 Lost";
            return 1;
        }
        print();

    }
    while(true){
        resP1=Isola::player1Play(resP2);
        if(!resP1.back()){
            cout<<"Player 1 Lost";
            return 1;
        }
        print();
        Sleep(sleepTimeMS);


        resP2=Isola::player2Play(resP1);
        if(!resP2.back()){
            cout<<"Player 2 Lost";
            return 2;
        }
        print();
        Sleep(sleepTimeMS);


    }
}
int main(){
    Isola game1(11,1);
    game1.play();
    return 0;
}
