#include <vector>

template <typename T>
struct heap
{
private:
	std::vector <T> v;
public:
	void add (const T a)
	{
		v.push_back (a);
		size_t ind = v.size ();
		while (ind > 0)
		{
			if (v [ind] < v [ind >> 1])
			{
				swap (v [ind], v [ind >> 1]);
				ind >>= 1;
			}
			else
				break;
		}
	}
	T top () const
	{
		return v [0];
	}
	void pop ()
	{
		swap (v [0], v [v.size () - 1]);
		v.pop_back ();
		size_t ind = 0;
		while (ind < v.size ())
		{
			if (2 * ind + 1 < v.size ())
			{
				if (v [ind * 2] < v [ind * 2 + 1])
				{
					if (v [ind] > v [ind * 2])
					{
						swap (v [ind], v [ind << 1]);
						ind = 2 * ind;
					}
				}
				else
					if (v [ind] > v [2 * ind + 1])
					{
						swap (v [ind], v [2 * ind + 1]);
						ind = 2 * ind + 1;
					}
			}
			else if (2 * ind < v.size ())
			{
				if (v [ind] > v [ind * 2])
				{
					swap (v [ind], v [ind * 2]);
					ind = ind * 2;
				}
			}
			else
				break;
		}
	}
	T get ()
	{
		T a = top ();
		pop ();
		return a;
	}
};
