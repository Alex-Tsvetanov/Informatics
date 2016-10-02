# Документация за ботове
# How to make your AI?
```cpp
struct <<Name of Your AI>> : player
{
	<<Name of Your AI>> (int pl_n, char** map)
	{
		player_num = pl_n;
		this->map = map;
	}
	turn_t turn (int plX, int plY) const // Parameters are opponentX and opponentY
	{
		//Do calculates for your turn
		.............................
		return std::make_pair (std::make_pair (<<MOVE_X>>, <<MOVE_Y>>), std::make_pair (<<SHOOT_X>>, <<SHOOT_Y>>));
	}
};
```
### Answer: By shown above template
