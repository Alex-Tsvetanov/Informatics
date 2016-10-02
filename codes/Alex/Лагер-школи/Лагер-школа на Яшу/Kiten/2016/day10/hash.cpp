#include <iostream>
#include <string>

using namespace std;

template<typename T>
/*abstract*/ class hash_t
{
public:
	uint64_t a, m;
	virtual uint64_t hash (T s) const = 0;
};

struct : public hash_t<std::string>
{
	const uint64_t a = 101, m = 1e9 + 7;
	uint64_t hash (std::string s) const
	{
		uint64_t h = 0;
		for (size_t i = 0 ; i < s.size () ; i ++)
			h = (((h * a) % m) + s [i]) % m;
		return h;
	}
} hash1;


int main ()
{
	cout << hash1.hash ("asdf") << "\n";
}
