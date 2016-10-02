#include <iostream>
#include <map>

struct rolling_hash
{
private:
	unsigned hash_code;
	unsigned a, m;
	unsigned max_pow;
public:
	rolling_hash (unsigned _a, unsigned _m)
	{
		a = _a;
		max_pow = 1;
		m = _m;
	}

	unsigned getHashCode () const
	{
		return hash_code;
	}

	void calc_max_pow (unsigned n)
	{
		for (unsigned i = 1 ; i < n ; i ++) 
			max_pow = ((unsigned long long)(max_pow) * a) % m;
	}
	
	unsigned hash (const std::string& s)
	{
		unsigned h = 0;
		for (size_t i = 0 ; i < s.size () ; i ++)
			h = ((((unsigned long long)(h) * a) % m) + s [i]) % m;
		return hash_code = h;
	}

	unsigned roll (char rem, char add)
	{
		hash_code += m;
		hash_code -= ((unsigned long long)(rem) * max_pow) % m;
		hash_code %= m;
		hash_code = ((unsigned long long)(hash_code) * a) % m;
		hash_code += add;
		hash_code %= m;
		return hash_code;
	}
};

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	std::string s;
	std::cin >> s;
	unsigned k;
	std::cin >> k;
	for (unsigned i = 0 ; i < k ; i ++)
	{
		unsigned len;
		std::cin >> len;
		unsigned long long n = 0;
		std::map < std::pair < unsigned, unsigned >, unsigned long long > br; 
		rolling_hash hash1 (257, 1000000007);
		rolling_hash hash2 (281, 1000018379);
		hash1.hash (s.substr (0, len));
		hash2.hash (s.substr (0, len));
		n += br [{hash1.getHashCode (), hash2.getHashCode ()}];
		br [{hash1.getHashCode (), hash2.getHashCode ()}] ++;
		for (unsigned j = 0 ; j < s.size () - len ; j ++)
		{
			hash1.roll (s [j], s [j + len]);
			hash2.roll (s [j], s [j + len]);
			n += br [{hash1.getHashCode (), hash2.getHashCode ()}];
			br [{hash1.getHashCode (), hash2.getHashCode ()}] ++;
		}
		std::cout << n << "\n";
	}
}
