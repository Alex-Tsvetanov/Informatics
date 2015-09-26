	vector < set < int > > allHard;
	
	bool Intersect (vector < int > arr)
	{
		for (int i = 0 ; i < (int)arr.size () ; i ++)
			for (int j = i + 1 ; j < (int)arr.size () ; j ++)
				if (arr [i] == arr [j])
					return true;
				else if (Intersect (arr [i], arr [j]))
					return true;
		return false;
	}

	
	void gen_hard ()
	{
		if (polygon.size () <= 3) return;

		if (polygon.size () == 4) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				allHard.push_back ({a});

		if (polygon.size () == 5) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					if (not Intersect ({a, b}))
						allHard.push_back ({a, b});

		if (polygon.size () == 6) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					for (auto& c : ln [b]) 
						if (not Intersect ({a, b, c}))
							allHard.push_back ({a, b, c});

		if (polygon.size () == 7) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					for (auto& c : ln [b])
						for (auto& d : ln [c])
							if (not Intersect ({a, b, c, d}))
								allHard.push_back ({a, b, c, d});

		if (polygon.size () == 8) 
			for (int a = 0 ; a < (int)edges.size () ; a ++)
				for (auto& b : ln [a])
					for (auto& c : ln [b])
						for (auto& d : ln [c])
							for (auto& e : ln [d])
								if (not Intersect ({a, b, c, d, e}))
									allHard.push_back ({a, b, c, d, e});
				
	}

	make_func_print_triangulation(gen_hard_printer, allHard, allHardCounter)
