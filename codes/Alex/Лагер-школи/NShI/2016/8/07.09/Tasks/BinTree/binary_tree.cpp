#include <iostream>
#include "binary_tree.hpp"

using namespace tl;

int main ()
{
	tree <int>* a = new binary_search_tree <int> ();
	a -> add (5);
	a -> add (3);
	a -> add (4);
	a -> add (2);
	a -> add (1);
	a -> add (10);
	std::cout << (a -> find (1)) << "\n";
	std::cout << (a -> find (5)) << "\n";
	std::cout << (a -> find (4)) << "\n";
	std::cout << (a -> find (41)) << "\n";
	std::cout << "1. Preorder: \n";
	a -> print ("Rlr");
	std::cout << "------------------------\n";
	a -> remove (4);
	std::cout << "2. Preorder: \n";
	a -> print ("Rlr");
	std::cout << "------------------------\n";
	a -> remove (1);
	std::cout << "3. Preorder: \n";
	a -> print ("Rlr");
	std::cout << "------------------------\n";
////a -> remove (5);
////std::cout << "3.1. Preorder: \n";
////a -> print ("Rlr");
////std::cout << "------------------------\n";
	std::cout << (a -> find (4)) << "\n";
	std::cout << "4. Preorder: \n";
	a -> print ("Rlr");
	std::cout << "------------------------\n";
	std::cout << (a -> find (5)) << "\n";
	std::cout << "5. Preorder: \n";
	a -> print ("Rlr");
	std::cout << "------------------------\n";
	tree <int>* b = new binary_search_tree <int> ();
	b -> add (20);
	b -> add (10);
	b -> add (15);
	b -> add (30);
	b -> add ( 8);
	b -> add (40);
	b -> add (18);
	b -> add ( 6);
	b -> add ( 9);
	b -> add ( 4);
	b -> add ( 7);
	b -> add (13);
	b -> add (11);
	b -> add (19);
	b -> add (25);
	b -> remove ( 9);
	b -> remove (19);
	std::cout << "Root->left->right\n";
	std::cout << "Preorder: \n";
	b -> print ("Rlr");
	std::cout << "------------------------\n";
}
