#include <iostream>
#include <string>

using namespace std;

void computeLPSArray (const char *pat, int M, int *lps,int startind = 0)
{
	int len = 0;
	int i;

	lps[0] = 0;
	i = 1;
	while (i < M)
	{
		if (pat[i+startind] == pat[len+startind])
		{
			len++;
			lps[i] = len;
			i++;
		}
		else
		{
			if (len != 0)
			{
				len = lps[len-1];
			}
			else
			{
				lps[i] = 0;
				i++;
			}
		}
	}
}

int main ()
{
	string input;
	cin >> input;
	const char* pat = input.c_str ();
	int* lps = new int [input.size ()];

	for (int i = 0 ; i < (int)input.size () ; i ++)
	{
		computeLPSArray (pat, input.size () - i, lps, i);
		if (lps [input.size () - i - 1] * 2 >= (int)input.size () - i)
		{
			cout << input.substr (i, input.size () - i - lps [input.size () - i - 1]) << endl;
			break;
		}
	}

	delete[] lps;
}
