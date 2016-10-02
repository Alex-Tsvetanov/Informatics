#include <iostream>

using namespace std;

struct course
{
	int day;
	int ind;
	int theme;
	int level;
	course ()
	{

	}
	course (int day_, int indoftheday, int theme_, int l)
	{
		day = day_;
		ind = indoftheday;
		theme = theme_;
		level = l;
	}
};

struct possibility
{
	static int by_time (const course a, const course b)
	{
		if (a.day == b.day and a.ind == b.ind)
			return 1 << 0;
		if (a.day == b.day and abs (a.ind - b.ind) > 1)
			return 1 << 1;
		if (a.day != b.day)
			return 1 << 2;
		if (a.day == b.day and abs (a.ind - b.ind) == 1)
			return 1 << 3;
		return -1;
	}

	static int by_diff (const course a, const course b)
	{
		if (a.theme == b.theme)
			return abs (a.level - b.level);
		return 1;
	}
};
