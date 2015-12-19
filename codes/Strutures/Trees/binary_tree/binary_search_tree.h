template <typename T> struct binary_search_tree
{
	T* root;
	binary_search_tree <T>* left;
	binary_search_tree <T>* right;
	binary_search_tree () :
							root (nullptr),
							left (nullptr),
							right (nullptr)
	{

	}

	void remove (T a)
	{
		if (root == a)
		{
			binary_search_tree<T>* curr = this;
			while (curr->left != nullptr)
			{
				curr->root = curr->left->root;
				curr = curr->left;
			}
			delete curr->root;
			curr->root = nullptr;
		}
		else if (a < *root)
		{
			if (left != nullptr)
				left -> remove (a);
		}
		else if (a > *root)
		{
			if (right != nullptr)
				right -> remove (a);
		}
	}

	void add (T a)
	{
		if (root == nullptr)
			root = new T (a);
		else if (a < *root)
		{
			if (left == nullptr)
				left = new binary_search_tree <T> ();
			left -> add (a);
		}
		else if (a > *root)
		{
			if (right == nullptr)
				right = new binary_search_tree <T> ();
			right -> add (a);
		}
	}
};
