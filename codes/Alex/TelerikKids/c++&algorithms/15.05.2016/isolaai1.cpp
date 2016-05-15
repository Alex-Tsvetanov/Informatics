#include <iostream>
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <cmath>

#ifdef _WIN32
#include <windows.h>

void sleep(unsigned milliseconds)
{
	Sleep(milliseconds);
}
#else
#include <unistd.h>

void sleep(unsigned milliseconds)
{
	usleep(milliseconds * 1000); // takes microseconds
}
#endif

using namespace std;
//handshake data
int fieldSize=11,playerTurn;
int playerX,playerY;
int enemyX,enemyY;
// handshake data

//Ai result
int field[1000][1000];

bool validMove(int x,int y,int pX,int pY){
	if(field[x][y]==1){
		return 0;
	}
	if(x==enemyX && y==enemyY){
		return 0;
	}
	if(x==playerX && y==playerY){
		return 0;
	}
	if(abs(x-pX)>1 || abs(y-pY)>1){
		return 0;
	}
	return 1;
}
bool validShoot(int x,int y){
	if(field[x][y]==1){
		return 0;
	}
	if(x==enemyX && y==enemyY){
		return 0;
	}
	if(x==playerX && y==playerY){
		return 0;
	}
	return 1;
}
void movePlayer()
{
	int vhodX,vhodY;
	cin>>vhodX>>vhodY;// replace with custom code
	if(validMove(vhodX,vhodY,playerX,playerY)){
		playerX=vhodX;
		playerY=vhodY;
	}else{
		cout<<"player lost";
		while(true){}
	}
}
void shootPlayer()
{
	int vhodX,vhodY;
	cin>>vhodX>>vhodY;// replace with custom code
	if(validShoot(vhodX,vhodY)){
		field[vhodY][vhodX]=1;
	}else{
		cout<<"player lost";
		while(true){}
	}
}
void moveEnemy(){
	int vhodX,vhodY;
	cin>>vhodX>>vhodY;// replace with custom code
	if(validMove(vhodX,vhodY,enemyX,enemyY)){
		enemyX=vhodX;
		enemyY=vhodY;
	}else{
		cout<<"enemy lost";
		while(true){}
	}
}
void shootEnemy(){
	int vhodX,vhodY;

	cin>>vhodX>>vhodY;// replace with custom code

	if(validShoot(vhodX,vhodY)){
		field[vhodY][vhodX]=1;
	}else{
		cout<<"enemy lost";
		while(true){}
	}
}
void print(){
	for(int i=1;i<=fieldSize;i++){
		for(int j=1;j<=fieldSize;j++){
			if(i==playerX && j==playerY){
				cout<<1; continue;
			}
			if(i==enemyX && j==enemyY){
				cout<<2; continue;
			}
			if(field[i][j]==0){
				cout<<"0"; continue;
			}
			if(field[i][j]==1){
				cout<<"*"; continue;
			}
		}
		cout<<endl;
	}
	cout<<endl;
}
void handshake(){
	cout<<"Expecting to get size,turn,pX,pY,eX,eY :"<<endl;
	cin>>fieldSize>>playerTurn;
	cin>>playerX>>playerY;
	cin>>enemyX>>enemyY;
	cin>>timeLimitMS;
}
int main(){
	int timeLimitMS=4000;
	handshake();
	print();



	if(playerTurn==1){
		movePlayer();
		shootPlayer();
		print();
		Sleep(500);
	}
	while(true)
	{
		turn_t turn_Enemy = Enemy.turn ();

		print();
		Sleep(500);
		movePlayer();
		shootPlayer();
		print();
		sleep(1);
	}
	return 0;
}
