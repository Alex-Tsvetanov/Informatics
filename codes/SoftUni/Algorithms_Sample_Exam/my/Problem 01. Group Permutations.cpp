#include <iostream>
#include <cstring>
#include <algorithm>

using namespace std;
using T = char;

T* arr;

struct a
{
    size_t l [32];
    a ()
    {
	for (int i = 0 ; i < 32 ; i ++)
	    l [i] = 0;
    }

} letters;

bool next_permutation (T* first, T* last)
{
    if (first == last)
        return false;
    T* i = first;
    ++ i;
    if (i == last)
        return false;
    i = last;
    -- i;
    
    for(;;)
    {
        T* ii = i;
        --i;
        if (*i < *ii)
        {
            T* j = last;
            while (!(*i < *--j))
            {}
	    if (*i == *j)
	    {
		goto Next;
	    }
            std::iter_swap (i, j);
            std::reverse (ii, last);
            return true;
        }
        Next:
        {

        }
        if (i == first)
        {
            std::reverse(first, last);
            return false;
        }
    }
}

void perm (T* arr, int n)
{
    do
    {
	for (int i = 0 ; i < n ; i ++)
	    for (int j = 0 ; j < letters.l [arr [i] - 'A'] ; j ++)
		cout << arr [i];
	cout << std::endl;
    }
    while (next_permutation (arr + 0, arr + n));
}

int main ()
{
    int n;
    arr = new T [21];
    cin >> arr;
    n = strlen (arr);
    for (int i = 0 ; i < n ; i ++)
	letters.l [arr [i] - 'A'] ++;
    n = 0;
    for (int i = 0 ; i < 32 ; i ++)
	if (letters.l [i] != 0)
	    arr [n ++] = i + 'A';
    perm (arr, n);
}
