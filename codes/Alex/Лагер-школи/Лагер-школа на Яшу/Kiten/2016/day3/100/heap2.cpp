#include <queue>
#include <iostream>

int main ()
{
	std::priority_queue <int, std::vector <int>, std::greater <int> > h;
	int n;
	std::cin >> n;
	for (int i = 0 ; i < n ; i ++)
	{
		char c;
		std::cin >> c;
		if (c == 'r')
		{
			std::cout << h.top () << "\n";
			h.pop ();
		}
		else // c = 'a'
		{
			int a;
			std::cin >> a;
			h.push (a);
		}
	}
	std::cout.flush ();
	return 0;
}
