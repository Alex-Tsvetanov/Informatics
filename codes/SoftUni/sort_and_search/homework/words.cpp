#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;
using T = char;

T* arr;

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
    sort (arr, arr + n);
    int ans = 0;
    do
    {
	for (int i = 0 ; i < n - 1 ; i ++)
	    if (arr [i] == arr [i + 1])
		goto Next;
	ans ++;
	Next:
	{

	}
    } while (next_permutation (arr + 0, arr + n));
    cout << ans << "\n";
}

int main ()
{
    std::string a;
    cin >> a;
    arr = new T [a.size ()];
    for (int i = 0 ; i < (int)a.size () ; i ++)
	arr [i] = a [i];
    perm (arr, a.size ());
}
