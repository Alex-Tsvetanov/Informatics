struct AI_alex
{
	range my_range;
	void choice (game_rules rules)
	{
		my_range = *rules.all_ranges.begin ();
	}
	int turn (game_rules rules)
	{
		return *rules.rules.begin ();
	}
};
