#pragma once
#include <stdexcept>
#include <system_error>
#include <cstring>

namespace otl // OpenTreeLib
{
	template <typename T>
	struct tree
	{
		T* root;

		virtual ~tree ()
		{
			delete root;
		}
		
		bool add (T x)
		{
			return __add (x);
		}
		
		bool remove (T x)
		{
			return __remove (x);
		}
		
		bool find (T x) const
		{
			return __find (x) != nullptr;
		}

		virtual void print (const char*) const = 0; 
		virtual bool __add (T) = 0;
		virtual bool __remove (T) = 0;
		virtual const tree<T>* __find (T) const = 0;
		virtual std::size_t children () const = 0;
		virtual tree<T>* child (const std::size_t) const = 0;
	};

	template <typename T>
	struct binary_tree : public tree <T>
	{
		virtual ~binary_tree ()
		{
			delete tree <T>::root;
		}
		virtual void print (const char*) const = 0; 
		virtual void preorder () const = 0;
		virtual bool __add (T) = 0;
		virtual bool __remove (T) = 0;
		virtual const binary_tree<T>* __find (T) const = 0;
		virtual std::size_t children () const = 0;
		virtual binary_tree<T>* child (const std::size_t) const = 0;
	};

	template <typename T>
	struct binary_search_tree : public binary_tree <T>
	{
	private:
		T* root;
		binary_search_tree<T>* left;
		binary_search_tree<T>* right;
	public:
		virtual void preorder () const override
		{
			if (root != nullptr)
			{
				std::cout << *root << "\n";
				if (left != nullptr) left -> preorder ();
				if (right != nullptr) right -> preorder ();
			}
		}

		virtual void print (const char* x) const override
		{
			for (size_t i = 0 ; i < strlen (x) ; i ++)
			{
				if (x [i] == 'R')
					if (root != nullptr)
						std::cout << *root << "\n";
				if (x [i] == 'l')
					if (left != nullptr) left -> print (x);
				if (x [i] == 'r')
					if (right != nullptr) right -> print (x);
			}
		}

		virtual ~binary_search_tree ()
		{
			if (  left != nullptr) delete left;
			if ( right != nullptr) delete right;
			if (  root != nullptr) delete root;
		}

		std::size_t children () const override
		{
			return (left != nullptr) + 2 * (right != nullptr);
		}

		binary_search_tree<T>* child (const std::size_t x) const override
		{
			if (x == 1)
				return left;
			else if (x == 2)
				return right;
			else
				throw std::invalid_argument ("binary_search_tree::child (): Argument 0 can be only 1 or 2!");
		}

		virtual bool __add (const T x) override
		{
			if (root == nullptr)
			{
				root = new T (x);
				return true;
			}
			else if ((*root) == x)
				return false;
			else if ((*root) < x)
			{
				if (right != nullptr)
					return right -> __add (x);
				else
				{
					right = new binary_search_tree <T> ();
					return right -> __add (x);
				}
			}
			else if ((*root) > x)
			{
				if (left != nullptr)
					return left -> __add (x);
				else
				{
					left = new binary_search_tree <T> ();
					return left -> __add (x);
				}
			}
			throw std::system_error (std::error_code (5, std::system_category ()) ,"else-if operator fail");
		}

		virtual bool __remove (T d) override
		{
			binary_search_tree <T>* curr = this;
			binary_search_tree <T>* parent = nullptr;

			while (curr != nullptr)
			{
				if (curr -> root == nullptr)
					return false;
				else if ((*curr -> root) == d)
					break;
				else
				{
					parent = curr;
					if (d > (*curr -> root))
						curr = curr -> right;
					else
						curr = curr -> left;
				}
			}

			if (parent == nullptr)
			{
				binary_search_tree <T>* tmp = curr -> left;
				if (tmp == nullptr)
				{
					curr -> right -> parent = curr -> parent;
					curr = curr -> right;
					return true;
				}
				while (tmp -> right != nullptr)
				{
					tmp = tmp -> right;
				}
				*(curr -> root) = *(tmp -> root);
				tmp -> parant -> right = tmp -> left;
				tmp -> left -> parent = tmp -> parent;
			}

			if (curr == nullptr)
				return false;

			if (curr -> left == nullptr and curr -> right != nullptr)
			{
				if (parent -> left == curr)
				{
					parent -> left = curr -> right;
					delete curr;
				}
				else
				{
					parent -> right = curr -> right;
					delete curr;
				}
				return true;
			}
			else if (curr -> left != nullptr and curr -> right == nullptr)
			{
				if (parent -> left == curr)
				{
					parent -> left = curr -> left;
					delete curr;
				}
				else
				{
					parent -> right = curr -> left;
					delete curr;
				}
				return true;
			}
			else if (curr -> left == nullptr and curr -> right == nullptr)
			{
				if (parent -> left == curr)
					parent -> left = nullptr;
				else
					parent -> right = nullptr;

				delete curr;
				return true;
			}
			else if (curr -> left != nullptr and curr -> right != nullptr)
			{
				binary_search_tree <T>* chkr;
				chkr = curr -> right;
				if ((chkr -> left == nullptr) and (chkr -> right == nullptr))
				{
					curr = chkr;
					delete chkr;
					curr -> right = nullptr;
				}
				else
				{
					if ((curr -> right) -> left != nullptr)
					{
						binary_search_tree <T>* lcurr;
						binary_search_tree <T>* lcurrp;
						lcurrp = curr -> right;
						lcurr = (curr -> right) -> left;
						while (lcurr -> left != nullptr)
						{
							lcurrp = lcurr;
							lcurr = lcurr -> left;
						}
						(*curr -> root) = (*lcurr -> root);
						delete lcurr;
						lcurrp -> left = nullptr;
					}
					else
					{
						binary_search_tree <T>* tmp;
						tmp = curr -> right;
						(*curr -> root) = (*tmp -> root);
						curr -> right = tmp -> right;
						delete tmp;
					}
				}
				return true;
			}
			throw std::system_error (std::error_code (5, std::system_category ()) ,"else-if operator fail");
		}

		virtual const binary_search_tree<T>* __find (T a) const override
		{
			if (root == nullptr)
				return nullptr;
			else if ((*root) < a)
			{
				if (right == nullptr)
					return nullptr;
				return right -> __find (a);
			}
			else if ((*root) > a)
			{
				if (left == nullptr)
					return nullptr;
				return left -> __find (a);
			}
			else if ((*root) == a)
				return this;
			throw std::system_error (std::error_code (5, std::system_category ()) ,"else-if operator fail");
		}
	};

	template <typename T>
	struct AVL : public binary_search_tree <T>
	{

	};

	template <typename T>
	struct RedBlack : public binary_search_tree <T>
	{

	};

	template <typename T>
	struct Binary : public binary_tree <T>
	{

	};
}
