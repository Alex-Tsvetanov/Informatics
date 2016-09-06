#include <iostream>
#include <string>

using namespace std;

#include "binary_search_tree.hpp"

int main ()
{
	binary_search_tree <int> BST;
	cout << BST.add (10) << endl;
	cout << BST.add (6) << endl;
	cout << BST.add (4) << endl;
	cout << BST.add (7) << endl;
	cout << BST.add (3) << endl;
	cout << BST.add (5) << endl;
	cout << BST.add (11) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 10:\n" << flush;
	cout << BST.remove (10) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 6:\n" << flush;
	cout << BST.remove (6) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 4:\n" << flush;
	cout << BST.remove (4) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 7:\n" << flush;
	cout << BST.remove (7) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 3:\n" << flush;
	cout << BST.remove (3) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 5:\n" << flush;
	cout << BST.remove (5) << endl;
	BST.print ();
	cout << "-----------------------\nRemove 11:\n" << flush;
	cout << BST.remove (11) << endl;
	BST.print ();
	cout << "-----------------------\n" << flush;
}
