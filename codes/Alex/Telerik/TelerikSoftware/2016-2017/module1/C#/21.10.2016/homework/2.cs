using System;

namespace Project
{
	class Program
	{
		static void Main ()
		{
			string _1 = Console.ReadLine ();
			string _2 = Console.ReadLine ();
			string _3 = Console.ReadLine ();
			string _4 = Console.ReadLine ();
			string _5 = Console.ReadLine ();
			string _6 = Console.ReadLine ();
			string _7 = Console.ReadLine ();
			string _8 = Console.ReadLine ();
			string _9 = Console.ReadLine ();
			if (_4 == "") 
				_4 = "(no fax)";
			Console.WriteLine ("{0}\nAddress: {1}\nTel. {2}\nFax: {3}\nWeb site: {4}\nManager: {5} {6} (age: {7}, tel. {8})", _1, _2, _3, _4, _5, _6, _7, _8, _9);
		}
	}
}
