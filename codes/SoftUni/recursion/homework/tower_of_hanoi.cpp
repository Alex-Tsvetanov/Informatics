#include <iostream>
#include <stack>
#include <vector>
#include <sstream>

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

void hanoi (stack <int> a, stack <int> b, stack <int> c, vector <string> operations)
{
	if (a.empty () and b.empty ())
	{
		for (auto& k : operations)
			cout << k << "\n";
		cout << "------------" << endl;
		return ;
	}
	if (operations.size () >= (1ull << (a.size () + b.size () + c.size ())))
		return;
	//cout << "A: "; printStack (a);
	//cout << "B: "; printStack (b);
	//cout << "C: "; printStack (c);
	//cout << "--------------------------------" << endl;
	string lastOpetation;
	char lastA = 'd';
	char lastB = 'd';
	if (!operations.empty ())
	{
		lastOpetation = operations.back ();
		lastA = lastOpetation [5];
		lastB = lastOpetation [lastOpetation.size () - 1];
	}

	IF(a, b, 'b', 'a')
	{
		moveElement (a, b);

		stringstream ss;
		ss << "From a (" << b.top () << ") to b";
		operations.push_back (ss.str ());
		
			hanoi (a, b, c, operations);

		operations.pop_back ();
		moveElement (b, a);
	}
	IF(a, c, 'c', 'a')
	{
		moveElement (a, c);

		stringstream ss;
		ss << "From a (" << c.top () << ") to c";
		operations.push_back (ss.str ());
		
			hanoi (a, b, c, operations);

		operations.pop_back ();
		moveElement (c, a);
	}
	IF(b, c, 'c', 'b')
	{
		moveElement (b, c);

		stringstream ss;
		ss << "From b (" << c.top () << ") to c";
		operations.push_back (ss.str ());
		
			hanoi (a, b, c, operations);

		operations.pop_back ();
		moveElement (c, b);
	}


	IF(b, a, 'a', 'b')
	{
		moveElement (b, a);

		stringstream ss;
		ss << "From b (" << a.top () << ") to a";
		operations.push_back (ss.str ());
		
			hanoi (a, b, c, operations);

		operations.pop_back ();
		moveElement (a, b);
	}
	IF(c, a, 'a', 'c')
	{
		moveElement (c, a);

		stringstream ss;
		ss << "From c (" << a.top () << ") to a";
		operations.push_back (ss.str ());
		
			hanoi (a, b, c, operations);

		operations.pop_back ();
		moveElement (a, c);
	}
	IF(c, b, 'b', 'c')
	{
		moveElement (c, b);

		stringstream ss;
		ss << "From c (" << b.top () << ") to b";
		operations.push_back (ss.str ());
		
			hanoi (a, b, c, operations);

		operations.pop_back ();
		moveElement (b, c);
	}
}

int main ()
{
	int n;
	cin >> n;
	stack <int> a, b, c;
	for (int i = n ; i > 0 ; i --)
		a.push (i);
	hanoi (a, b, c, vector <string> ());
}
