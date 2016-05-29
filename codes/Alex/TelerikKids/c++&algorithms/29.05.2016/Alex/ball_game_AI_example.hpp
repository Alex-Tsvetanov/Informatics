struct
{
	range my_range;
	void choice (game_rules rules)
	{
		my_range = *rules.all_ranges.begin ();
	}
	int AI_alex (game_rules rules)
	{
		return *rules.rules.begin ();
	}
} AI_alex;
