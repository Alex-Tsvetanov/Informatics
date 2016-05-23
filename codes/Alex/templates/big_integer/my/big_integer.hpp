#include <vector>
#include <algorithm>
#include <sstream>
#include <iomanip>

std::string __big_int_clean (std::string str)
{
	std::reverse (std::begin (str), std::end (str));
	while (str [str.size () - 1] == '0')
		str.erase (str.size () - 1, 1);
	std::reverse (std::begin (str), std::end (str));
	return std::move (str);
}

struct big_int
{
	typedef int64_t digit_t;
	static const digit_t base = 1000000000000000000;//10^18
	std::vector <digit_t> digits;
	bool positive;

	big_int (int8_t a = 0)
	{
		positive = (a >= 0);
		a = (positive) ? a : (-a);
		digits.push_back (a);
	}

	big_int (int16_t a = 0)
	{
		positive = (a >= 0);
		a = (positive) ? a : (-a);
		digits.push_back (a);
	}

	big_int (int32_t a = 0)
	{
		positive = (a >= 0);
		a = (positive) ? a : (-a);
		digits.push_back (a);
	}

	big_int (int64_t a = 0)
	{
		positive = (a >= 0);
		a = (positive) ? a : (-a);
		digits.push_back (a);
	}

	std::string to_string () const
	{
		std::stringstream ss;
		for (int i = digits.size () - 1 ; i >= 0 ; i --)
			ss << std::setw (18) << std::setfill ('0') << digits [i];
		return __big_int_clean (ss.str ());
	}

	big_int operator += (const big_int& a)
	{
		if (positive and a.positive)
		{
			for (std::size_t i = 0 ; i < digits.size () ; i ++)
			{
				digit_t curr = digits [i] + a.digits [i];
				if (i == digits.size () - 1 and curr / base > 0)
					digits.push_back (curr / base);
				else if (i == digits.size () - 1)
					;
				else
				{
					digits [i + 1] += curr / base;
				}
				digits [i] = curr % base;
			}
			return *this;
		}
		else if (positive and !a.positive)
		{
			big_int b = *this;
			big_int c = a;
			c.positive = true;
			return (*this = b - c);
:	}
		else
		{
			big_int c = *this;
			big_int d = a;
			c.positive = not c.positive;
			d.positive = not d.positive;
			d += c;
			d.positive = not d.positive;
			return std::move (d);
		}
	}

	bool operator < (big_int a)
	{
		if (digits.size () < a.digits.size ())
			return true;
		else if (digits.size () > a.digits.size ())
			return false;
		else
			for (int i = digits.size () - 1; i >= 0 ; i --)
				if (digits [i] < a.digits [i])
					return true;
				else if (digits [i] > a.digits [i])
					return false;
		return false;
	}

	big_int operator -= (const big_int& a)
	{
		big_int c = a;
		c.positive = not c.positive;
		*this += c;
		return *this;
	}

	big_int operator - ()
	{
		big_int c = 0;
		c -= *this;
		return std::move (c);
	}
};

std::ostream& operator << (std::ostream& out, const big_int& a)
{
	out << a.to_string ();
	return out;
}

big_int operator + (const big_int& a, const big_int& b)
{
	big_int c = a;
	c += b;
	return std::move (c);
}

big_int operator - (const big_int& a, const big_int& b)
{
	big_int c = a;
	big_int d = b;
	d.positive = not d.positive;
	c += d;
	return std::move (c);
}
