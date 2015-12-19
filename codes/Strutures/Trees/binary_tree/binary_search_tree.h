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

	bool remove (T a)
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
				return left -> remove (a);
			else
				return false;
		}
		else if (a > *root)
		{
			if (right != nullptr)
				return right -> remove (a);
			else
				return false;
		}
		return true;
	}

	bool add (T a)
	{
		if (root == nullptr)
		{
			root = new T (a);
			return true;
		}
		else if (a < *root)
		{
			if (left == nullptr)
				left = new binary_search_tree <T> ();
			left -> add (a);
			return true;
		}
		else if (a > *root)
		{
			if (right == nullptr)
				right = new binary_search_tree <T> ();
			right -> add (a);
			return true;
		}
		else
			return false;
	}

	T findMin ()
	{

	}
};
