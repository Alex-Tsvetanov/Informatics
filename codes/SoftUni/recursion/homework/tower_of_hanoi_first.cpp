#include <iostream>
#include <stack>
#include <vector>
#include <sstream>
#include <stdlib.h>

#define IF(a, b, c, d) if (((!a.empty () and b.empty ()) or (!a.empty () and !b.empty () and a.top () < b.top ())) and (!(lastA == c and lastB == d)))

using namespace std;

void moveElement (stack <int>& A, stack <int>& B)
{
		B.push (A.top ()); A.pop ();
}

void printStack (stack <int> k)
{
	stack <int> a;
	while (!k.empty ())
	{
		a.push (k.top ()); k.pop ();
	}
	while (!a.empty ())
	{
		cout << a.top () << " "; a.pop ();
	}
	cout << endl;
}

int n;
vector <string> optimum;
vector <string> local;

void ssAdd (stringstream& ss, char a, char b, stack <int>& my_top)
{
	ss << "Преместете диск " << my_top.top () << " от " << a << " на " << b << ".";
}


void hanoi (stack <int> a, stack <int> b, stack <int> c)
{
	if (a.empty () and b.empty ())
	{
//		if (local.size () < optimum.size ())
//			optimum = local;
//		/*
		cout << local.size () << "\n";
		for (auto& k : local)
			cout << k << "\n";
//		cout << "------------" << endl;
//		*/
		exit (0);
		return ;
	}
	if (local.size () >= optimum.size ())
		return;
	//cout << "A: "; printStack (a);
	//cout << "B: "; printStack (b);
	//cout << "C: "; printStack (c);
	//cout << "--------------------------------" << endl;
	string lastOpetation;
	char lastA = 'd';
	char lastB = 'd';
	if (!local.empty ())
	{
		lastOpetation = local.back ();
		lastA = lastOpetation [5];
		lastB = lastOpetation [lastOpetation.size () - 1];
	}

	if (n % 2 == 0)
	{
		IF(a, b, 'b', 'a')
		{
			moveElement (a, b);

			stringstream ss;
			ssAdd (ss, 'a', 'b', b);
			local.push_back (ss.str ());
			
				hanoi (a, b, c);

			local.pop_back ();
			moveElement (b, a);
		}
		IF(a, c, 'c', 'a')
		{
			moveElement (a, c);

			stringstream ss;
			ssAdd (ss, 'a', 'c', c);
			local.push_back (ss.str ());
			
				hanoi (a, b, c);

			local.pop_back ();
			moveElement (c, a);
		}
	}
	else
	{
		IF(a, c, 'c', 'a')
		{
			moveElement (a, c);

			stringstream ss;
			ssAdd (ss, 'a', 'c', c);
			local.push_back (ss.str ());
			
				hanoi (a, b, c);

			local.pop_back ();
			moveElement (c, a);
		}
		IF(a, b, 'b', 'a')
		{
			moveElement (a, b);

			stringstream ss;
			ssAdd (ss, 'a', 'b', b);
			local.push_back (ss.str ());
			
				hanoi (a, b, c);

			local.pop_back ();
			moveElement (b, a);
		}

	}
	IF(b, c, 'c', 'b')
	{
		moveElement (b, c);

		stringstream ss;
		ssAdd (ss, 'b', 'c', c);
		local.push_back (ss.str ());
		
			hanoi (a, b, c);

		local.pop_back ();
		moveElement (c, b);
	}


	IF(b, a, 'a', 'b')
	{
		moveElement (b, a);

		stringstream ss;
		ssAdd (ss, 'b', 'a', a);
		local.push_back (ss.str ());
		
			hanoi (a, b, c);

		local.pop_back ();
		moveElement (a, b);
	}
	IF(c, a, 'a', 'c')
	{
		moveElement (c, a);

		stringstream ss;
		ssAdd (ss, 'c', 'a', a);
		local.push_back (ss.str ());
		
			hanoi (a, b, c);

		local.pop_back ();
		moveElement (a, c);
	}
	IF(c, b, 'b', 'c')
	{
		moveElement (c, b);

		stringstream ss;
		ssAdd (ss, 'c', 'b', b);
		local.push_back (ss.str ());
		
			hanoi (a, b, c);

		local.pop_back ();
		moveElement (b, c);
	}
}

int main ()
{
	cin >> n;
	optimum.resize (1<<n, "");
	stack <int> a, b, c;
	for (int i = n ; i > 0 ; i --)
		a.push (i);
	hanoi (a, b, c);
//	for (auto& x : optimum)
//		cout << x << endl;
//	cout << endl;
}
