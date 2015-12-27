struct __range
{
	int s; int e;
	
	__range () {}
	__range (int __s, int __e) : s (__s), e (__e) //[s, e]
	{
	
	}
};

template <typename T>
struct Prefix
{
	__range range;
	std::vector <T> prefix;

	Prefix () {}
	Prefix (__range _range)
	{
		range = _range;
	}
	void addMin (T min)
	{
		if (prefix.size () > 0)
			min = std::min (prefix [prefix.size () - 1], min);
		prefix.push_back (min);
	}
	T getMin (int to)
	{
		std::cout << "Get Min Prefix:" << endl;
		for (int i = 0 ; i < (int)prefix.size () ; i ++)
			std::cout << std::setw (2) << i + range.s << " ";
		std::cout << endl;
		for (int i = 0 ; i < (int)prefix.size () ; i ++)
			std::cout << std::setw (2) << prefix [i] << " ";
		std::cout << endl << "Get Index: " << to << endl;
		//int myIndex = to - range.s;
		//return prefix [myIndex];
		return T ();
	}
};

template <typename T>
struct Sufix
{
	__range range;
	std::vector <T> sufix;

	Sufix () {}
	Sufix (__range _range)
	{
		range = _range;
	}
	void addMin (T min)
	{
		if (sufix.size () > 0)
			min = std::min (sufix [sufix.size () - 1], min);
		sufix.push_back (min);
	}
	T getMin (int to)
	{
		int myIndex = range.e - range.s + 1 - (to - range.s);
		return sufix [myIndex];
	}
};

template <typename T>
struct vertex
{
	__range range;
	Prefix <T> prefix;
	Sufix <T> sufix;

	vertex () {}
	vertex (__range _range) : range (_range)
	{
		prefix = Prefix<T> (range);
		 sufix =  Sufix<T> (range);
	}

	void setRange (int s, int e)
	{
		range = __range (s, e);
		prefix.range = (range);
		 sufix.range = (range);
	}
	
	void addSufix (int min)
	{
		sufix.addMin (min);
	}
	const std::vector<T>& getSufix () const
	{
		return sufix.sufix;
	}
	void addPrefix (int min)
	{
		prefix.addMin (min);
	}
	const std::vector<T>& getPrefix () const
	{
		return prefix.prefix;
	}
};

template<typename X> X next_power_number_of_2 (X value)
{
	return ((sizeof (X) * 8) - __builtin_clz(value));
}
template<typename X> X next_power_of_2 (X value)
{
	return 1 << ((sizeof (X) * 8) - __builtin_clz(value));
}

template <typename T>
struct BIT
{
    vertex<T>** tree;
    int depth;

    BIT () {}

    ~BIT ()
    {
		for (int i = 0 ; i <= depth ; i ++)
			delete[] tree [i];
		delete[] tree;
    }

    void init (std::vector <T> arr)
    {
		depth = 31 - __builtin_clz (arr.size ());
		if ( (1ull << depth) < arr.size () )
			depth ++;
			
		generate ();

		//init last line (leaves)
		int row = depth;
			for (int col = 0 ; col < (int)arr.size () ; col ++)
			{
				int s, e, len;
				s = col;
				len = (1 << (depth - row));
				e = s + len - 1;

				tree [row][col].setRange (s, e);
				tree [row][col].addPrefix (arr [col]);
				tree [row][col].addSufix (arr [col]);
			}
			for (int col = arr.size () ; col < (1 << depth) ; col ++)
				tree [row][col] = tree [row][col - 1];

		//init other lines
		for (int row = depth - 1 ; row >= 0 ; row --)
		{
			for (int col = 0 ; col < (1 << depth) ; col ++)
			{
				int s, e, len;
				s = col;
				len = (1 << (depth - row));
				e = s + len - 1;

				tree [row][col].setRange (s, e);
				//built prefix
					for (auto& x : tree [row + 1][2 * col].getPrefix ())
						tree [row][col].addPrefix (x);
					for (auto& x : tree [row + 1][2 * col + 1].getPrefix ())
						tree [row][col].addPrefix (x);
				//built sufix
					for (auto& x : tree [row + 1][2 * col + 1].getSufix ())
						tree [row][col].addSufix (x);
					for (auto& x : tree [row + 1][2 * col].getSufix ())
						tree [row][col].addSufix (x);

			}
		}
    }

    void generate ()
    {
	    tree = new vertex<T>* [depth + 1];
	    for (int i = 0 ; i < depth + 1 ; i ++)
		    tree [i] = new vertex<T> [(1 << i)];
    }
private:
    static bool cmp (T a, T b)
    {
        return Depth [a] <= Depth [b];
    }
public:
    T query (int a, int b)
    {
		cout << "Query for " << a << " and " << b << endl;
		if (b < a)
			std::swap (a, b);
		cout << "Edited Query is " << a << " and " << b << endl;
		cout << tree [depth][a].prefix.getMin (a) << endl;
		T global_min = tree [depth][a].prefix.getMin (a);
		cout << "Current global min is " << global_min << endl;
		__range subrange;
		while (a <= b)
		{
			subrange = __range (a, next_power_of_2 (a) - 1);
			if (subrange.e > b)
				subrange.e = b;
			std::cout << subrange.s << " " << subrange.e << endl;
			int level = next_power_number_of_2 (a);
			T minForSubrange = tree [depth - level][(a >> level)].prefix.getMin (subrange.e);
			global_min = min (global_min, minForSubrange, cmp);
			a = subrange.e + 1;
		}
		return global_min;
    }
};

/*
template <typename T>
struct BIT
{
    T** tree;
    int levels;
    BIT () {}

    void fill ()
    {
        for (int row = levels - 1 ; row >= 0 ; row --)
            for (int col = 0 ; col < (1 << row) ; col ++)
            {
                tree [row][col] =
                    (
                        (depth [tree [row + 1][2 * col]] <= depth [tree [row + 1][2 * col + 1]])
                        ?
                        tree [row + 1][2 * col]
                        :
                        tree [row + 1][2 * col + 1]
                    );
            }
    }

    void init (std::vector <T> arr)
    {
        levels = 31 - __builtin_clz (arr.size ());
        if ( (1ull << levels) < arr.size () )
            levels ++;

        tree = new T* [levels + 1];
        for (int j = levels - 1 ; j >= 0 ; j --)
            tree [j] = new T [1ull << (j + 1)];

        tree [levels] = new T [ 1ull << levels ];
        for (int i = 0 ; i < (int)arr.size () ; i ++)
            tree [levels][i] = arr [i];
        for (int i = (int)arr.size () ; i < (1 << levels) ; i ++)
            tree [levels][i] = tree [levels][i - 1];

        fill ();
    }
    static bool cmp (T a, T b)
    {
        return depth [a] <= depth [b];
    }

    T query (int a, int b)
    {
        if (b < a)
            swap (b, a);
        //return *min_element (tree [levels] + a, tree [levels] + b, cmp);
 //       cout << "Query for " << a << " and " << b << endl;
        int diff = b - a + 1;
        T ans = tree [levels][a];
        if (a % 2 == 1)
        {
            ans = min (ans, tree [levels][a], cmp);
            a ++;
            diff --;
        }
        if (b % 2 == 0)
        {
            ans = min (ans, tree [levels][b], cmp);
            b --;
            diff --;
        }
        int row = levels, col = a;
        ans = min (ans, tree [row][col], cmp);
        while (diff > 0)
        {
            if (diff % 2 == 1)
            {
 //               cout << "\tGet " << tree [row][col] << endl;
                ans = min (ans, tree [row][col], cmp);
            }

            diff /= 2;
            row --;
            col = (col + 1) / 2;
        }
 //       cout << "Answer of query is " << ans << endl;
        return ans;
    }

    ~BIT ()
    {
        for (int i = 0 ; i <= levels ; i ++)
            delete[] tree [i];
        delete[] tree;
    }
};
*/
