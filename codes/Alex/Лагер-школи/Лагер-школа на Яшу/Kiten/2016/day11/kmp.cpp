#include <iostream>
#include <string.h>
#include <vector>

std::vector <int> kmp_search (const char *text, const char *pattern)
{
	int* T;
	int i, j;
	std::vector <int> result;

	if (pattern [0] == '\0')
		return {};

	/* Construct the lookup table */
	T = new int [strlen (pattern) + 1];
	T[0] = -1;
	for (i=0; pattern[i] != '\0'; i++) {
		T[i+1] = T[i] + 1;
		while (T[i+1] > 0 and pattern[i] != pattern[T[i+1]-1])
			T[i+1] = T[T[i+1]-1] + 1;
	}

	/* Perform the search */
	for (i=j=0; text[i] != '\0'; ) {
		if (j < 0 or text[i] == pattern[j]) {
			++i, ++j;
			if (pattern[j] == '\0') {
				result.push_back (i - j);
			}
		}
		else j = T[j];
	}

	delete[] T;
	return result;
}

int main ()
{
	std::string text, patt;
	std::cin >> text >> patt;
	auto v = kmp_search (text.c_str (), patt.c_str ());

	for (auto& x : v)
		std::cout << x << "\n";
}
