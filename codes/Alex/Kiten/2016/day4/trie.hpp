class trie
{
	char* root;
	trie* children [26];
	bool is_end;
public:
	bool has (basic_string <char> s)
	{
		trie* curr = children [s [0] - 'a'];
		for (int i = 1 ; i < (int)s.size () ; i ++)
		{
			if (curr == nullptr)
				return false;

			curr = curr->children [s [i] - 'a'];
		}
		return curr->is_end;
	}

	void add (basic_string <char> s)
	{
		trie* curr = children [s [0] - 'a'];
		for (int i = 1 ; i < (int)s.size () ; i ++)
		{
			if (curr == nullptr)
			{
				curr = new trie  ();
			}

			curr = curr->children [s [i] - 'a'];
		}
		curr->is_end = true;
	}

	void remove (basic_string <char> s)
	{
		trie* curr = children [s [0] - 'a'];
		trie* for_del = nullptr; int j = -1;
		for (int i = 1 ; i < (int)s.size () ; i ++)
		{
			if (curr->is_end)
			{
				for_del = curr;
				j = i;
			}
			curr = curr->children [s [i] - 'a'];
		}
		curr->is_end = false;
		for (int i = j + 1 ; i < (int)s.size () ; i ++)
		{
			curr = for_del->children [s [i] - 'a'];
			delete[] for_del;
			for_del = curr;
		}
	}
};
