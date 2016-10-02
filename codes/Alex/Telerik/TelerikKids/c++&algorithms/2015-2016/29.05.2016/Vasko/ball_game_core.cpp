#include<iostream>

using namespace std;

#include"AI_code.h"
#include"AI_code1.h"

int main()
{
	bool alreadyLose[10]={false};
	int number_of_balls=10,number_of_players=2,player_on_turn=0,min_balls=1,max_balls=3;
	int onlinePlayers=number_of_players;
	cout<<"Number of players: \t"<<number_of_players<<endl;
	cout<<"Number of balls: \t"<<number_of_balls<<endl;
	cout<<"Diapason: \t\t["<<min_balls<<";"<<max_balls<<"]\n";
	cout<<"ENTER player_turn: \t";
	cin>>player_on_turn;

	string name[1]={"Veselin"};
	while(onlinePlayers>1){
		int current_number_of_balls=number_of_balls;
		while(current_number_of_balls>min_balls){

			if(player_on_turn>=number_of_players){
				player_on_turn=0;
			}

			int next_taking;
			if(player_on_turn==0){
				next_taking=how_many_balls_0(min_balls,max_balls,current_number_of_balls);
			}
			if(player_on_turn==1){
				next_taking=how_many_balls_1(min_balls,max_balls,current_number_of_balls);
			}

			if(next_taking<min_balls or next_taking>max_balls or next_taking>=current_number_of_balls){
				cout<<"Player "<<player_on_turn<<" have made a wrong turn! ";
				break;
			}else{
				current_number_of_balls-=next_taking;
				if(current_number_of_balls==1){
					cout<<"At the moment, there is "<<current_number_of_balls<<endl;
				}else{
					cout<<"At the moment, there are "<<current_number_of_balls<<endl;
				}
			}


			player_on_turn++;
			while(alreadyLose[player_on_turn])player_on_turn++;
			if(player_on_turn>=number_of_players){
				player_on_turn=0;
				while(alreadyLose[player_on_turn])player_on_turn++;
			}
		}
		onlinePlayers--;
		alreadyLose[player_on_turn]=true;
		cout<<"Player "<<player_on_turn<<" lost the game!\n";
		if(onlinePlayers>1){
			cout<<"The game started again with "<<number_of_balls;
			player_on_turn++;
			while(alreadyLose[player_on_turn])player_on_turn++;
			if(player_on_turn>=number_of_players){
				player_on_turn=0;
				while(alreadyLose[player_on_turn])player_on_turn++;
			}
			cout<<"Player "<<player_on_turn<<" will be first";
		}
	}
	int wonPlayer;
	for(wonPlayer=0;alreadyLose[wonPlayer];wonPlayer++){}
	cout<<"Player "<<wonPlayer<<" won the game";
	return 0;
}
