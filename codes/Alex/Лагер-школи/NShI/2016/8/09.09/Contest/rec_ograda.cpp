#include <iostream> 
#include <stack>

unsigned int a [100000];
unsigned int b [100000];
	
unsigned int n;

std::stack <unsigned int> st;

unsigned int rec (unsigned int ind = 0, unsigned int min = -1)
{
	//std::cout << ind << " " << min << std::endl;
	if (ind == n)
		return (min == (unsigned int)(-1))?0:min;

	unsigned int ans = 0;

	ans = std::max (ans, rec (ind + 1, std::min (min, a [ind])));
	if (!st.empty ())
	{
		int t = st.top ();
		st.pop ();
		ans = std::max (ans, rec (ind, min));
		ans = std::max (ans, rec (ind + 1, std::min (min, a [ind] + t)));
		st.push (t);
	}
	return ans;
}

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	std::cin >> n;
	//std::cout << "n = " << n << std::endl;
	
	for (unsigned int i = 0 ; i < n ; i ++)
		std::cin >> a [i];
	
	unsigned int m;
	std::cin >> m;

	//std::cout << "m = " << m << std::endl;
	for (unsigned int i = 0 ; i < m ; i ++)
		std::cin >> b [i];

	//std::cout << "Stack pushing: " << std::endl;
	for (int i = m - 1 ; i >= 0 ; i --)
		st.push (b [i]);
	//std::cout << "Stack is full! " << std::endl;

	std::cout << rec () << "\n";

}
