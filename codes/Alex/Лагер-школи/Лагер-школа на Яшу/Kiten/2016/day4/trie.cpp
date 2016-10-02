#include <iostream>
#include <string>

using namespace std;
#include "trie.hpp"

trie <char> t;

int main ()
{
	t.add ("asdf");
	cout << t.has ("asdf") << "\n";
	t.remove ("asdf");
	cout << t.has ("asdf") << "\n";
	cout.flush ();
}
