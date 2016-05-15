struct AlexRo6afF : player
{
	AlexRo6afF (int pl_n, const char** map)
	{
		player_num = pl_n;
		this->map = map;
		
	}
	turn_t turn (int plX, int plY)
	{
		return {{1, 2}, {3, 4}};
	}
};
