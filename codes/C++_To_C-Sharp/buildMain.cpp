#include "System.cpp"

namespace Project
{
	class Program
	{
		public static void Main (String args[])
		{
			ConsoleWrite ("{1}\n", 10,12,131,141,414);
			ConsoleWrite ("{:+.9}; {:+}\n", ((double)(3.1111114)), -3.14);
			ConsoleWrite ("{: }; {: }\n", 3.14, -3.14);
			ConsoleWrite ("{:-}; {:-}\n", 3.14, -3.14);
			ConsoleWrite (stderr, "Don't {}!", "panic");
			cout << std::flush;
		}
	};
}

run_main
