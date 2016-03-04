set K (int t, int s)
{
	if (t == s)
	{
		auto a = K (t, s - 1);
		for (auto& x : a)
			x = x + "0";
		return a;
	}
	if (1 == s)
	{
		auto a = K (t - 1, s);
		for (auto& x : a)
			x = x + "1";
		a.insert (string (t - 1, '1') + "01");
		return a;
	}
	if (i < s and s < t)
	{
		auto a = K (t, s - 1);
		for (auto& x : a)
			x = x + "0";
		auto b = K (t - 1, s);
		for (auto& x : b)
			x = x + "1";
		string c = string (t - 1, '1') + string (s, '0') + "1";
		for (auto x : b)
			a.insert (x);
		a.insert (c);
		return a;
	}
}
