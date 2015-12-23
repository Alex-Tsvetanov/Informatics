template <typename T>
struct BIT
{
	T** tree;
	int levels;
	BIT () {}
	
	void fill ()
	{
		for (int row = levels - 1 ; row >= 0 ; row ++)
			for (int col = 0 ; col < (1 << row) ; col ++)
				tree [row][col] = min (tree [row][2 * col], tree [row][2 * col + 1]);
	}

	void init (std::vector <T> arr)
	{
		levels = __builtin_ctz (arr.size ());
		if ( (1ull << levels) < arr.size () )
			levels ++;

		int x = (1ull << levels);

		tree = new T* [levels + 1];
		for (int j = levels - 1 ; j >= 0 ; j --)
			tree [j] = new T [1ull << (j + 1)];

		tree [levels] = new T [ 1ull << levels ];
		for (int i = 0 ; i < arr.size () ; i ++)
			tree [levels][i] = arr [i];
		for (int i = arr.size () ; i < (1ull << levels) ; i ++)
			tree [levels][i] = tree [levels][i - 1];

		fill ();
	}

	T query (int a, int b)
	{
		int diff = b - a + 1;
		int row = levels, col = a;
		T ans = tree [row][col];
		while (diff > 0)
		{
			if (diff % 2 == 1)
				ans = min (ans, tree [row][col]);

			diff /= 2;
			row --;
			col = (col + 1) / 2;
		}
	}

	~BIT ()
	{
		for (int i = 0 ; i <= levels ; i ++)
			delete[] tree [i];
		delete[] tree;
	}
};
