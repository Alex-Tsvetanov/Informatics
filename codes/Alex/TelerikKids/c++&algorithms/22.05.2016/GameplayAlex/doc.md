# Документация за ботове
# How to make your AI?
```cpp
struct <i><<Name of Your AI>></i> : player
{
	__<<Name of Your AI>>__ (int pl_n, char** map)
	{
		player_num = pl_n;
		this->map = map;
	}
	turn_t turn (int plX, int plY) // Parameters are __opponentX__ and __opponentY__
	{
		//Do calculates for your turn
		//and return pair of 2 points -  **first** point coordinates to **move**
		//                              **second** point coortinates to **shoot**
		return std::make_pair (std::make_pair (1, 2), std::make_pair (3, 4));
	}
};
```
