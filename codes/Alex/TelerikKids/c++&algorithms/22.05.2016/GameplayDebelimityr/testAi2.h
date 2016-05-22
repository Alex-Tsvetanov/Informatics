#include<iostream>
#include<vector>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>
using namespace std;
struct TESTAI2{
    TESTAI2(){
        for(int i=0;i<=1000;i++){
            for(int j=0;j<=1000;j++){
                this->field[i][j]=0;
            }
        }
    }
    int randX,randY;
    int shootX,shootY;
    int playerX,playerY,enemyX,enemyY,turn,fieldSize;
    bool field[1000][1000];
    void randomCoords(){
        this->randX=rand()%this->fieldSize+1;
        this->randY=rand()%this->fieldSize+1;
    }
    bool validPos(int x,int y){
        if(this->field[x][y]==0 && x>0 && y>0 && x<=this->fieldSize && y<=this->fieldSize){
            if(x==this->playerX && y==this->playerY){
                return 0;
            }
            if(x==this->enemyX && y==this->enemyY){
                return 0;
            }
            return 1;
        }
        return 0;
    }
    void randomShootingCoords(){
        while(true){
            this->randomCoords();
            if(this->validPos(this->randX,this->randY)){
                this->shootX=this->randX;
                this->shootY=this->randX;
                cout<<randX<<" "<<randY<<endl;
                break;
            }
        }

    }
};
TESTAI2 TestAi2;
vector<int> testAi2(vector<int> param){
    srand(time(NULL));
    vector<int> res;
    if(param.size()==5){
        TestAi2.turn=param[0];
        TestAi2.fieldSize=param[1];
        TestAi2.playerX=param[2];
        TestAi2.playerY=param[3];
        TestAi2.enemyX=param[4];
        TestAi2.enemyY=param[5];
    }
    if(param.size()==0 || param.size()==4){
        if(param.size()==4){
            TestAi2.enemyX=param[0];
            TestAi2.enemyY=param[1];
            TestAi2.field[param[2]][param[3]]=1;
        }
        TestAi2.randomShootingCoords();
        TestAi2.field[TestAi2.shootX][TestAi2.shootY]=1;
        cin>>TestAi2.playerX>>TestAi2.playerY;

    }
    res.push_back(TestAi2.playerX);
    res.push_back(TestAi2.playerY);
    res.push_back(TestAi2.shootX);
    res.push_back(TestAi2.shootY);
    return res;
}
