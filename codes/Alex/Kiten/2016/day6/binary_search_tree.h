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
		if (*root == a)
		{
			if (left == nullptr and right == nullptr)
			{
				delete root;
				return true;
			}
			else if (left == nullptr)
			{
				delete root;
				root = right->root;
				left = right->left;
				right = right->right;
				return true;
			}
			else if (right == nullptr)
			{
				delete root;
				root = right->root;
				left = right->left;
				right = right->right;
				return true;
			}
			else
			{
				//TODO
				binary_search_tree <T>* curr = left;
				if (curr -> right == nullptr)
				{
					delete root;
					root = curr -> root;
					left = curr -> left;
					return true;
				}
				else
				{
					while (curr -> right -> right != nullptr)
						curr = curr -> right;
					delete root;
					root = curr -> right -> root;
					curr -> right = curr -> right -> left;
					return true;
				}
			}
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
		else
			return -1;
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

	bool find (T a)
	{
		if (root != nullptr)
		{
			if (*root == a)
				return true;
			if (*root > a)
			{
				if (left != nullptr)
					return left->find (a);
				return false;
			}
			if (*root < a)
			{
				if (right != nullptr)
					return right->find (a);
				return false;
			}
		}
		return false;
	}

	void print (int spaces = 0)
	{
		cout << string (spaces * 3, ' ') << "Ͱ " << *root;
		left -> print (spaces + 1);
		right -> print (spaces + 1);
	}
};
