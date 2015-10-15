#include <iostream>
#include <string>
#include <vector>

using namespace std;

struct Byte
{
	string in_hex; // lenght = 2
	string tr;
	Byte (){}
	Byte (string a)
	{
		this->in_hex = a;
		tr = this -> trf ();
	}
	const string trf () const
	{
		string a = in_hex;
		if ('A' <= a [1] and a [1] <= 'Z')
			a [1] = a [1] - 'A' + 'a';
		if ('A' <= a [0] and a [0] <= 'Z')
			a [0] = a [0] - 'A' + 'a';
		return a;
	}
};

bool operator == (Byte a, Byte b)
{
	return a.in_hex == b.in_hex;
}

using T = Byte;

int lps [128];

void computeLPSArray (const vector <T>& pat, int M, int *lps);

vector <size_t> KMPSearch (const vector <T>& pat, const vector <T>& txt)
{
	int M = pat.size ();
	int N = txt.size ();

	int j = 0;

	computeLPSArray (pat, M, &lps[0]);

	vector <size_t> res;

	int i = 0;
	while (i < N)
	{
		if (pat [j].tr == txt [i].tr)
		{
			j ++;
			i ++;
		}

		if (j == M)
		{
			res.push_back (i - j);
			j = lps [j - 1];
		}
		else if (i < N && (!(pat [j].tr == txt [i].tr)))
		{
			if (j != 0)
				j = lps [j - 1];
			else
				i = i + 1;
		}
	}
	return move (res);
}

void computeLPSArray (const vector <T>& pat, int M, int *lps)
{
	int len = 0;
	int i;

	lps [0] = 0;
	i = 1;

	while (i < M)
	{
		if (pat [i].tr == pat [len].tr)
		{
			len ++;
			lps [i] = len;
			i ++;
		}
		else
		{
			if (len != 0)
				len = lps [len - 1];
			else 
			{
				lps [i] = 0;
				i ++;
			}
		}
	}
}

void inputBytes (vector <T>& a, vector <T>& b)
{
	string A;
	cin >> A;
	for (int i = 0 ; i < (int)A.size () ; i += 2)
	{
		string AA = {A [i], A [i + 1]};
		a.push_back (Byte (AA));
		b.push_back (Byte (AA));
	}
}

void inputBytes (vector <T>& a)
{
	string A;
	cin >> A;
	for (int i = 0 ; i < (int)A.size () ; i += 2)
	{
		string AA = {A [i], A [i + 1]};
		a.push_back (Byte (AA));
	}
}

vector<T> a [100];
vector<T> b;
vector<T> c;
vector <size_t> o;

int main ()
{
	cin.tie (nullptr);
	ios::sync_with_stdio (false);
	int n;
	cin >> n;

	for (int i = 0 ; i < n ; i ++)
		inputBytes (a [i]);
	inputBytes (b, c);
	for (int i = 0 ; i < n ; i ++)
	{
		o = KMPSearch (a [i], b);
		for (auto& pos : o)
				for (size_t j = 0 ; j < a [i].size () ; j ++)
					c [pos + j] = {"@@"};
	}
	for (auto& x : c)
	{
		cout << x.in_hex;
	}
	cout << endl;
}

