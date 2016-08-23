template <typename T>
struct BIT
{
	T* root;
	BIT <T>* left;
	BIT <T>* right;
	size_t s, e, n;

	template <typename RAI>
	BIT (RAI a, RAI b, T (&func)(T, T), size_t S = 0)
	{
		n = b - a;
		s = S; 
		e = S + n;
		if (a == 0)
			;
		else if (std::next (a) == b)
		{
			root = new T (*a);
		}
		else
		{
			left  = new BIT <T> (a + 0, a + n / 2, func, s);
			right = new BIT <T> (a + n / 2, b + 0, func, (s + e) / 2);
			root = new T (func (*left->root, *right->root));
		}
	}

	T operator ()(size_t a, size_t b)
	{
		//cout << a << " " << b << "\n";
	//cout << (root == nullptr) << "\n";
		if (a == s and b == e) // full range
			return *root;
	//cout << left->s << " " << left->e << "\n";
		if (a <= left->e and b <= left->e) // full in left
			return (*left) (a, b);
	//cout << right->s << " " << right->e << "\n";
		if (a >= right->s and b >= right->s) // full in right
			return (*right) (a, b);
		else
			return (*left) (a, left->e) + (*right) (right->s, b);
	}
};
