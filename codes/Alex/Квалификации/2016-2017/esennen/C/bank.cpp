#include <iostream>
#include <queue>
#define int uint64_t

struct client
{
	int ind;
	int t;
	int a, b;
	client (int _ind = 0, int _a = 0, int _b = 0, int _t = 0) 
	{
		a = _a;
		b = _b;
		t = _t;
		ind = _ind;
	}
};

int n, m;

std::queue <client> not_arrived;
std::queue <client> waiting;
std::queue <client> level1;
std::queue <client> chef;
client chainer;

int ans [1<<17];
int done = 0;

bool is_chef_busy = false;

void optimize_level1 (int Time_plus)
{
	std::queue <client> remainers;
	while (not level1.empty ())
	{
		level1.front ().a -= Time_plus;

		if (level1.front ().a == 0)
			chef.push (level1.front ());
		else
			remainers.push (level1.front ());

		level1.pop ();
	}
	swap (remainers, level1);
}

void fill_empty_level1_slots ()
{
	while ((not waiting.empty ()) and (level1.size () < m))
	{
		level1.push (waiting.front ());
		waiting.pop ();
	}
}

void optimize_manager (int curr_Time, int Time_plus)
{
	if (is_chef_busy == true)
	{
		chainer.b -= Time_plus;
		if (chainer.b == 0)
		{
			ans [chainer.ind] = curr_Time;
			is_chef_busy = false;
			done ++;
		}
	}
}

void fill_empty_chef_slots ()
{
	if (is_chef_busy == false and (not chef.empty ()))
	{
		chainer = chef.front (); chef.pop ();

		is_chef_busy = true;
	}
}

int NEW_TIMEPLUS ()
{
	int minans = 1e18;

	if (is_chef_busy == true)
		minans = std::min (minans, chainer.b);

	if (not level1.empty ())
	{
		std::queue <client> rem;

		while (not level1.empty ())
		{
			minans = std::min (minans, level1.front ().a);
			rem.push (level1.front ()); level1.pop ();
		}

		swap (level1, rem);
	}

	if (minans == 1e18)
		return /*shift with */ 1;

	return minans;
}

void print_queue (std::queue<client> a)
{
	std::queue <client> rem;

	while (not a.empty ())
	{
		std::cout << "(ind = " << a.front ().ind << ","; 
		std::cout << " a   = " << a.front ().a   << ","; 
		std::cout << " b   = " << a.front ().b   << ","; 
		std::cout << " t   = " << a.front ().t   << ") "; 
		rem.push (a.front ()); a.pop ();
	}
	std::cout << "\n";
}

int32_t main ()
{
	//setup:
	{
		std::ios::sync_with_stdio (false);
		std::cin.tie (nullptr);
	}

	//input:
	{
		std::cin >> n >> m;

		for (int i = 0 ; i < n ;  i ++)
		{
			int a, b, t;
			std::cin >> t >> a >> b;

			not_arrived.push (client (i, a, b, t));
		}
	}
	
	//solve:
	{
		int Time_plus = 1;

		int curr_Time = not_arrived.front ().t; 
		while (done < n)
		{
			//std::cout << "not_arrived: ";
			//print_queue (not_arrived); 
			//std::cout << "waiting    : ";
			//print_queue (waiting); 
			//std::cout << "level1     : ";
			//print_queue (level1); 
			//std::cout << "chef       : ";
			//print_queue (chef); 
			//std::cout << "------------------------------\n";
			while (not not_arrived.empty () and not_arrived.front ().t <= curr_Time)
			{
				waiting.push (not_arrived.front ());
				not_arrived.pop ();
			}

			optimize_level1 (Time_plus);
			fill_empty_level1_slots ();

			optimize_manager (curr_Time, Time_plus);
			fill_empty_chef_slots ();

			Time_plus = NEW_TIMEPLUS ();

			if ((not not_arrived.empty ()) and
			    (not_arrived.front ().t - curr_Time < Time_plus)
			   )
				Time_plus = not_arrived.front ().t - curr_Time;

			curr_Time += Time_plus;
		}

	}

	//output:
	{
		for (int i = 0 ; i < n ; i ++)
			std::cout << ans [i] << "\n";
	}
}
