#include <iostream>
#include "player.hpp"
#include "playerAlexRo6afF.hpp"

using std::cin;
using std::cout;

    #include <unistd.h>

void draw (const char** map, const int gridX, const int gridY, const int _1_x, const int _1_y, const int _2_x, const int _2_y)
{
	for (int i  = 0 ; i < gridY ; i ++, cout << '\n') 
		for (int j  = 0 ; j < gridX ; j ++) 
			cout << map [i][j];
}

bool validMove (int x, int y, int pX, int pY, const player& player1, const player& player2)
{
	if(player1.map [x][y] == '#')
	{
		return 0;
	}
	if(x == player2.myX && y == player2.myY)
	{
		return 0;
	}
	if(x == player1.myX && y == player1.myY)
	{
		return 0;
	}
	if(abs (x - pX) > 1 || abs (y - pY) > 1)
	{
		return 0;
	}
	return 1;
}
void doAction (player& player_, turn_t turn)
{
	int fromX = player_.myX;
	int fromY = player_.myY;
	int toX = turn.first.first;
	int toY = turn.first.second;
	if(validMove (toX,toY,fromX,fromY))
	{
		player_.myX = toX;
		player_.myY = toY;
	}
	else
	{
		cout<<"player lost";
		while(true){}
	}

}

int main ()
{
	int timeLimitMS=4000;
	int gridX, gridY;
	cin >> gridX >> gridY;
	char** map = new char* [gridY];
	for (int i = 0 ; i < gridY ; i ++)
	{
		map [i] = new char [gridX];
		for (int j = 0 ; j < gridY ; j ++)
			map [i][j] = ' ';
	}

	int _1_x, _1_y;
	int _2_x, _2_y;
	cin >> _1_x >> _1_y >> _2_x >> _2_y;

	player player1 = AlexRo6afF (1, map);
	player1.myX = _1_x; player1.myY = _1_y; 
	player player2 = AlexRo6afF (2, map);
	player2.myX = _2_x; player2.myY = _2_y; 

	while (true)
	{
		turn_t player1_turn = player1.turn (player2.myX, player2.myY);
		doAction (player1, player1_turn);
		draw (map, gridX, gridY, player1.myX, player1.myY, player2.myX, player.myY);
		turn_t player2_turn = player2.turn (player1.myX, player1.myY);
		doAction (player2, player2_turn);
		draw (map, gridX, gridY, player1.myX, player1.myY, player2.myX, player.myY);
	}

	return 0;
}
