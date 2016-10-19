using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			double x = double.Parse (Console.ReadLine ());
			double y = double.Parse (Console.ReadLine ());
			Console.WriteLine ("{0:0.00} {1:0.00}", x * y, 2 * (x + y));
		}
	}
}
