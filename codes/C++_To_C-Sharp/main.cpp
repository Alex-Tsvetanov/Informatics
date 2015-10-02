#include "System"
#include "cppformat/format.cc"

using namespace fmt;

int main ()
{
	Console.Write ("int: {1:d}\n", 10,12,131,141,414);
	cout << format ("int: {1:d}\n", 10,12,131,141,414);
	cout << format("{:+f}; {:+f}", 3.14, -3.14);
	cout << format("{: f}; {: f}", 3.14, -3.14);
	cout << format("{:-f}; {:-f}", 3.14, -3.14);
	cout << endl;
	print(stderr, "Don't {}!", "panic");
	return 0;
}
