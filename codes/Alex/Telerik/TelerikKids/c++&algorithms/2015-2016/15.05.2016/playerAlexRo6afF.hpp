struct AlexRo6afF : player
{
	AlexRo6afF (int pl_n, char** map)
	{
		player_num = pl_n;
		this->map = map;
	}
	turn_t turn (int plX, int plY)
	{
		return std::make_pair (std::make_pair (1, 2), std::make_pair (3, 4));
	}
};
