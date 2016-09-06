template <typename T>
class BIT
{
private:
	T* root;
	BIT <T>* left;
	BIT <T>* right;
	int level;
public:
	template<typename RAI, typename Comp>
	BIT (RAI bit, RAI eit, Comp f)
	{
		if (std::next (bit) == eit)
		{
			root = new T (*bit);
			left = nullptr;
			right = nullptr;
			level = 0;
		}
		else
		{
			RAI mit = bit + distance (bit, eit) / 2;
			left = new BIT <T> (bit, mit);
			right = new BIT <T> (mit, eit);
			root = *(left->root) + *(right->root);
			level = left->level + 1;
		}
	}

	void add (size_t ind, T a)
	{
		*root += a;
		if (level == 0)
		{
			return ;
		}
		if (ind & (1 << level))
			right->add (ind - (1 << level), a);
		else
			left->add (ind >> 1, a);
	}

	T get (size_t a, size_t b)
	{
		size_t from = 1, to = (1 << level);
		if (
	}
protected:
};
