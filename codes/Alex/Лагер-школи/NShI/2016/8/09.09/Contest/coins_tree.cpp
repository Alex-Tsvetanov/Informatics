#include <iostream> 
#include <queue>
#include <utility>
#include <vector>

int arr [1000];

struct counter
{
	int cnt [1024];

	counter ()
	{
		for (int i = 0 ; i < 1024 ; i ++)
			cnt [i] = 0;
	}

	int& operator [] (size_t ind)
	{
		return cnt [ind];
	}
};

struct tree
{
	int curr;
	std::vector <tree*> children;
	counter left;

	tree (int a = 0, counter cnt = counter ())
	{
		curr = a;
		left = cnt;
	}

	tree* add (int a)
	{
		if (left [a] > 0)
		{
			children.push_back (new tree (curr + a, left));
			children.back () -> left [a] --;
			return children.back ();
		}
		return nullptr;
	}

	int level (int to_find) const
	{
		std::queue < std::pair <tree*, int> > q;
		for (auto& x : children)
			q.push (std::make_pair (x, 1));

		while (!q.empty ())
		{
			auto f = q.front (); q.pop ();
			if (f.first -> curr == to_find)
				return f.second;
			for (auto& x : f.first -> children)
				q.push ({x, f.second + 1});
		}
		return -1;
	}
};

int main ()
{
	std::cin.tie (nullptr);
	std::ios::sync_with_stdio (false);
	
	int C, m;
	std::cin >> C >> m;

	counter cnt;

	for (int i = 0 ; i < m ; i ++)
	{
		std::cin >> arr [i];
		std::cin >> cnt [arr [i]];
	}

	tree* root = new tree (0, cnt);
	std::queue <tree*> q;
	q.push (root);

	while (!q.empty ())
	{
		tree* f = q.front (); q.pop ();
		for (int i = 0 ; i < m ; i ++)
		{
			tree* New = f -> add (arr [i]);
			if (New != nullptr)
				q.push (New);
		}
	}

	int min = -1;
	for (int i = 0 ; i < C ; i ++)
	{
		int curr = root -> level (i + 1);
		//std::cout << curr << " " << i + 1 << "\n";
		if (curr == -1)
		{
			std::cout << "impossible\n";
			return 0;
		}
		else
			min = std::max (min, curr);
	}
	std::cout << min << "\n";
}
