#include <iostream>
#include <string>
#include <string.h>

using namespace std;

#define num_of_digits(N) ((N < 10) ? 1 : ((N < 100) ? 2 : ((N < 1000) ? 3 : ((N < 10000) ? 4 : ((N < 100000) ? 5 : ((N < 1000000) ? 6 : 7))))))

class literal_string
{
	const char* p;
	size_t length;
public:
	constexpr literal_string (const char* a) : p (a), length (0)
	{
	}
	
	constexpr char operator [] (size_t ind)
	{
		return ((ind < length) ? p [ind] : throw out_of_range ("literal_string out of range index - parameter of operator []"));
	}

	constexpr size_t size () 
	{
		if (length == 0)
			length = strlen (p);
		return length;
	}

	constexpr const char* get () const
	{
		return p;
	}
};

literal_string operator + (literal_string a, literal_string b)
{
	char* newString = new char [a.size () + b.size ()];
	strcpy (newString, a.get ());
	strcpy (newString + a.size (), b.get ());
	string f (newString);
	literal_string c (f.c_str ());
	return c;
}

constexpr literal_string f (int N)
{
	if (N == 1)
		return "1";
	char tostr [num_of_digits (N)];//COMPILE ERROR
	int ind = num_of_digits (N) - 1;
	int copyN = N;
	while (copyN > 0)
	{
		tostr [ind --] = copyN % 10 + '0';
		copyN /= 10;
	}
	literal_string prev = (f (N - 1));
	literal_string ans (tostr);
	ans = ans + prev + prev;
	return ans;
}

int main ()
{
	for (int i = 1 ; i < 10000 ; i ++)
	{
		f (i);
		cout << i << " -> " << endl;
	}
}
