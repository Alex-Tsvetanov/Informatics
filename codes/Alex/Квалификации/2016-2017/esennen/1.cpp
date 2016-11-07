#include <iostream>
#include <queue>
#define int uint64_t

using namespace std;

struct client
{
	int ind, t, a, b;
	client () 
	{
		t = -1;
		a = -1;
		b = -1;
	}
	client (int i, int _t, int _a, int _b)
	{
		ind = i;
		t = _t;
		a = _a;
		b = _b;
	}
};

struct queue_item
{
	int endtime;
	client c;

	queue_item (int e, client _c)
	{
		endtime = e;
		c = _c;
	}
};

client input [100000];
int ans [100000];

queue < queue_item > level1 [16];
queue < queue_item > chef;

int get_min (int m)
{
	int ans = -1;
	for (int i = 0 ; i < m ; i ++)
	{
		if (level1 [i].empty ())
			continue;

		if (ans == -1 or level1 [i].front ().endtime < level1 [ans].front ().endtime)
			ans = i;
		else if (
				level1 [i].front ().endtime == level1 [ans].front ().endtime and
				level1 [i].front ().c.ind < level1 [ans].front ().c.ind
				)
			ans = i;
	}
	return ans;
}

bool all_empty (int m)
{
	for (int i = 0 ; i < m ; i ++)
	{
		if (not level1 [i].empty ())
			return false;
	}
	return true;
}

int32_t main ()
{
	int n, m;
	cin >> n >> m;
	for (int i = 0 ; i < n ; i ++)
	{
		int t, a, b;
		cin >> t >> a >> b;
		input [i] = (client (i, t, a, b));
	}

	for (int i = 0 ; i < m ; i ++)
		level1 [i].push (queue_item (input [i].t + input [i].a, input [i]));

	for (int i = m ; /*not all_empty (m)*/ ; i ++)
	{
		int min_ind = get_min (m);
		
		if (min_ind == -1)
			break;

		int time = level1 [min_ind].front ().endtime;
		
		auto front = level1 [min_ind].front ();
		
		chef.push (queue_item (time, front.c));
		
		level1 [min_ind].pop ();
		
		if (i < n)
			level1 [min_ind].push (queue_item (time + input [i].a, input [i]));
		
////	for (int j = 0 ; j < m ; j ++)
////	{
////		auto A = level1 [j];
////		while (!A.empty())
////		{
////			std::cout << "(" << A.front ().endtime << ", " << A.front ().c.ind << ") ";
////			A.pop();
////		}
////		cout << '\n';
////	}
////	cout << "\n-------------------\n\n";
	}

	int start_time = 0;

	start_time = ans [chef.front ().c.ind] = chef.front ().endtime + chef.front ().c.b;
	chef.pop ();

	while (not chef.empty ())
	{
		int curr_start_time = chef.front ().endtime;
		if (start_time < curr_start_time)
			start_time = curr_start_time;
		start_time = ans [chef.front ().c.ind] = start_time + chef.front ().c.b;
		chef.pop ();
	}

	for (int i = 0 ; i < n ; i ++)
		cout << ans [i] << "\n";
}
