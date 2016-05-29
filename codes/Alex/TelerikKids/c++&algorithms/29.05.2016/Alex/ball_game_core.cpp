#include <iostream>
#include <gtkmm.h>
#include <set>
#include <stdlib.h>

using namespace std;
#include "structures.hpp"
game_core game;
#include "ball_game_AI_example.hpp"

int main (int argc, char *argv[])
{
	Gtk::Main app(argc, argv);
	game.set_rules (vector <int>{1,2,3,4}).set_balls (5);
	AI_alex player1;
	AI_alex player2;
	player1.choice (game.get_rules ());
	player2.choice (game.get_rules ());
	while (true)
	{
		int player1_turn = AI_alex (game.get_rules ());
		int player2_turn = AI_alex (game.get_rules ());
		game.doTurn (1, player1_turn);
		game.doTurn (2, player2_turn);
	}
}
