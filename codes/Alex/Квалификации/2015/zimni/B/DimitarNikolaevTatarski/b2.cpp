#include<iostream>
//#include<windows.h>
using namespace std;
bool rotten[1001][1001];
int x1,y1,x2,y2;
int sizeX,sizeY;
int days;
int rottenBr;
void rot(int x,int y,int x1,int y1,int depth){
    if(depth<0 || x<=0 || y<=0 || x>sizeX || y>sizeY || x1<=0 || y1<=0 || x1>sizeX || y1>sizeY ){
        return ;
    }
    if(!rotten[x][y]){
        rotten[x][y]=1;
        rottenBr++;
    }
    if(!rotten[x1][y1]){
        rotten[x1][y1]=1;
        rottenBr++;
    }
    rot(x-1,y,x1-1,y1,depth-1);
    rot(x,y-1,x1,y1-1,depth-1);
    rot(x,y+1,x1,y1+1,depth-1);
    rot(x+1,y,x1+1,y1,depth-1);
}
int main(){
    cin>>sizeX>>sizeY;
    cin>>days;
    cin>>x1>>y1>>x2>>y2;
    rot(sizeX-x1+1,y1,sizeX-x2+1,y2,days);
    cout<<sizeX*sizeY-rottenBr<<endl;
    return 0;
}
