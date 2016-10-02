#include <iostream>

using namespace std;

char player_1_win [1<<20];

int main ()
{
	unsigned int a, b, c, p1, p2;
	unsigned int ans = 0;
	cin >> a >> b >> c >> p1 >> p2;

	for (int i = 0 ; i <= p2 ; i ++)
	{
		char curr = (!player_1_win [(i - a) % c] or !player_1_win [(i - b) % c] or !player_1_win [(i - c) % c]);
		player_1_win [(i) % c] = curr;
	}
}
