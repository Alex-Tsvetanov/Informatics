#include <iostream>
#include <string>
#include <algorithm>

using std::cin;
using std::cout;
using std::sort;
using T = std::string;

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
    do
    {
	for (int i = 0 ; i < n ; i ++)
	    cout << arr [i] << " ";
	cout << std::endl;
    } while (next_permutation (arr + 0, arr + n));
}

int main ()
{
    int n;
    cin >> n;
    arr = new T [n];
    for (int i = 0 ; i < n ; i ++)
	    cin >> arr [i];
    perm (arr, n);
}
