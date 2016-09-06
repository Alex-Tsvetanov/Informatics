#pragma once

template <typename T>
struct binary_search_tree
{
private:
	T* root;
	binary_search_tree <T>* left;
	binary_search_tree <T>* right;
	binary_search_tree <T>* parent;
public:
	binary_search_tree ()
	{
		left = right = parent = nullptr;
		root = nullptr;
	}
	int add (T a)
	{
		if (root == nullptr)
		{
			root = new T (a);
			return true;
		}
		else if (a < *root)
		{
			if (left == nullptr)
			{
				left = new binary_search_tree <T> ();
				left -> parent = this;
				left -> root = new T (a);
				return true;
			}
			else
				return left -> add (a);
		}
		else if (a > *root)
		{
			if (right == nullptr)
			{
				right = new binary_search_tree <T> ();
				right -> parent = this;
				right -> root = new T (a);
				return true;
			}
			else
				return right -> add (a);
		}
		else
			return false;
	}

	int remove (T a)
	{
		if (root == nullptr)
			throw "Remove from NullTree";
		else if (*root == a)
		{
			if (left == nullptr)
			{
				delete root;
				left = right -> left;
				root = right -> root;
				right = right -> right;
				return true;
			}
			else
			{
				binary_search_tree <int>* curr = left;
				while (curr -> right != nullptr)
					curr = curr -> right;
				delete root;
				root = curr -> root;
				curr -> parent-> right = curr -> left;
				return true;
			}
		}
		else if (*root < a)
		{
			if (right == nullptr)
				return false;
			else
				return right -> remove (a);
		}
		else if (*root > a)
		{
			if (left == nullptr)
				return false;
			else
				return left -> remove (a);
		}
		return -1;
	}

	int find (T a)
	{
		if (*root == a)
			return true;

		if (*root < a)
		{
			if (right == nullptr)
				return false;
			else
				return right -> find (a);
		}

		if (*root > a)
		{
			if (left == nullptr)
				return false;
			else
				return left -> find (a);
		}
	}

	void print (int spaces = 0)
	{
		for (int i = 0 ; i < spaces * 3 ; i ++)
		{
			if (i % 3 == 0)
				cout << "|";
			else
				cout << " ";
		}
		cout << "|---" << (*root) << "\n";
		if (left == nullptr)
		{
			for (int i = 0 ; i < spaces * 3 + 3 ; i ++)
			{
				if (i % 3 == 0)
					cout << "|";
				else
					cout << " ";
			}
			cout << "|--- Null" << "\n";
		}
		else
			left -> print (spaces + 1);
		
		if (right == nullptr)
		{
			for (int i = 0 ; i < spaces * 3 + 3 ; i ++)
			{
				if (i % 3 == 0)
					cout << "|";
				else
					cout << " ";
			}
			cout << "|--- Null" << "\n";

		}
		else
			right -> print (spaces + 1);
	}
protected:
};
