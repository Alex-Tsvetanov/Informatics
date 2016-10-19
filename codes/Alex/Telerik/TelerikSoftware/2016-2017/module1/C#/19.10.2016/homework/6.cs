using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int y = int.Parse (Console.ReadLine ());
			int a = y / 1000 % 10;
			int b = y / 100 % 10;
			int c = y / 10 % 10;
			int d = y / 1 % 10;
			Console.WriteLine ("{0}", a + b + c + d);
			Console.WriteLine ("{0}{1}{2}{3}", d, c, b, a);
			Console.WriteLine ("{0}{1}{2}{3}", d, a, b, c);
			Console.WriteLine ("{0}{1}{2}{3}", a, c, b, d);
		}
	}
}
