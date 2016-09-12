#include <iostream> 
#include <stack>

unsigned int a [100000];
unsigned int b [100000];
unsigned int n;
unsigned int m;
	
bool check (unsigned int ans)
{
	std::stack <unsigned int> st;
	for (int i = m - 1 ; i >= 0 ; i --)
		st.push (b [i]);
	unsigned int indA = 0;
	//std::cout << "Ans?: " << ans << std::endl;
	while (!st.empty () and indA < n)
	{
		//std::cout << "Stack Top: " << st.top () << " currA = " << a [indA] << std::endl;
		if (a [indA] + st.top () < ans)
		{
			//std::cout << "\t1) Only POP\n";
			st.pop ();
		}
		else if (a [indA] >= ans)
		{
			//std::cout << "\t2) Only shift\n";
			indA ++;
		}
		else
		{
			//std::cout << "\t1) POP and SHIFT\n";
			indA ++;
			st.pop ();
		}
		//std::cout << "EMPTY?: " << st.empty () << "\n";
	}
	for ( ; indA < n ; indA ++)
		if (a [indA] < ans)
			return false;
	return indA == n;
}

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);

	unsigned int maxA = 0, maxB = 0;

	std::cin >> n;
	
	for (unsigned int i = 0 ; i < n ; i ++)
	{
		std::cin >> a [i];
		maxA = std::max (maxA, a [i]);
	}
	std::cin >> m;

	for (unsigned int i = 0 ; i < m ; i ++)
	{
		std::cin >> b [i];
		maxB = std::max (maxB, b [i]);
	}
	//std::cout << "All is right!" << std::endl;

	unsigned int left = 0, right = maxA + maxB;
	while (left < right - 1)
	{
		unsigned int mid = (left + right) / 2;
		//std::cout << "Mid: " << mid << std::endl;
		bool CHECK = check (mid);
		//std::cout << "CHECK: " << CHECK << std::endl;
		if (CHECK)
			left = mid;
		else
			right = mid;
	}
	if (check (right))
	{
		std::cout << right << "\n";
	}
	else
		std::cout << left << "\n";
}
