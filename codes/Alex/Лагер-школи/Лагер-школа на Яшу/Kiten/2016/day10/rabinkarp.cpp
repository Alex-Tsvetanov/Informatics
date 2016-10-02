#include <iostream>

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
		{
			max_pow = ((unsigned long long)(max_pow) * a) % m;
		}
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

void rabin_karp (const std::string& text, const std::string& patt)
{
	rolling_hash text_hash (257, 1e9 + 7);
	rolling_hash patt_hash (257, 1e9 + 7);
	text_hash.calc_max_pow (patt.size ());
	text_hash.hash (text.substr (0, patt.size ()));
	patt_hash.calc_max_pow (patt.size ());
	patt_hash.hash (patt);
	if (text_hash.getHashCode () == patt_hash.getHashCode ())
	{
		if (text.substr (0, patt.size ()) == patt)
			std::cout << 1 << "\n";
	}
	for (size_t i = patt.size () ; i < text.size () ; i ++) 
	{
		//std::cout << text_hash.getHashCode () << " " << patt_hash.getHashCode () << "\n";
		text_hash.roll (text [i - patt.size ()], text [i]);
		if (text_hash.getHashCode () == patt_hash.getHashCode ())
		{
			if (text.substr (i - patt.size () + 1, patt.size ()) == patt)
				std::cout << i - patt.size () + 2 << "\n";
		}
	}
}

int main ()
{
	std::string text, patt;
	std::cin >> text >> patt;
	rabin_karp (text, patt);
}
