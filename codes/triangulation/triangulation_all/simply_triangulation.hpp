	vector < set < pair < int, int > > > allSimply;
	
	void gen_simple ()
	{
		for (int start = 0 ; start < (int)polygon.size () ; start ++)
		{
			set < pair < int, int > > a;
			for (int i = start + 2 ; i < (int)polygon.size () + start - 1 ; i ++)
				a.insert ({start, i % polygon.size ()});
			allSimply.push_back (a);
		}
	}

	make_simply_func_print_triangulation (gen_simple_printer, allSimply, allSimplyCounter);
