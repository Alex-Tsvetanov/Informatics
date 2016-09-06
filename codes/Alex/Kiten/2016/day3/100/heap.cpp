#include <iostream>
#include <vector>
#include <algorithm>

template <typename T>
struct heap
{
private:
	std::vector <T> v;
public:
	heap ()
	{
		v.push_back (0);
	}
	void add (const T a)
	{
		v [0] ++;
		v.push_back (a);
		size_t ind = v.size () - 1;
		while (ind > 1)
		{
			if (v [ind] < v [ind >> 1])
			{
				std::swap (v [ind], v [ind >> 1]);
				ind /= 2;
			}
			else
				break;
		}
	}
	T top () const
	{
		return v [1];
	}
	void pop ()
	{
		v [0] --;
		std::swap (v [1], v [v.size () - 1]);
		v.pop_back ();
		size_t ind = 1;
		while (ind < v.size ())
		{
			if (2 * ind + 1 < v.size ())
			{
				if (v [ind * 2] < v [ind * 2 + 1])
				{
					if (v [ind] > v [ind * 2])
					{
						std::swap (v [ind], v [ind * 2]);
						ind = 2 * ind;
					}
					else
						break;
				}
				else
				{
					if (v [ind] > v [2 * ind + 1])
					{
						std::swap (v [ind], v [2 * ind + 1]);
						ind = 2 * ind + 1;
					}
					else
						break;
				}
			}
			else if (2 * ind < v.size ())
			{
				if (v [ind] > v [ind * 2])
				{
					std::swap (v [ind], v [ind * 2]);
					ind = ind * 2;
				}
				else
					break;
			}
			else
				break;
		}
	}
	T get ()
	{
		T a = top ();
		//std::cout << "Do Top ()" << std::endl;
		pop ();
		return a;
	}
};


int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	heap <int> h;
	int n;
	std::cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
//		cout << i << std::endl;
		char c;
		std::cin >> c;
		if (c == 'r')
			std::cout << h.get () << "\n";
		else // c = 'a'
		{
			int a;
			std::cin >> a;
			h.add (a);
		}
//		cout << "----------------------------------------" << std::endl;
	}
	std::cout.flush ();
	return 0;
}
