#include <stdlib.h>
#include <iostream>

using namespace std;

int main ()
{
	string asdf;
	cin >> asdf;
	string command = "echo $((" + asdf + "))";
	system (command.c_str ());
}
