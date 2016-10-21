using System;

namespace Project
{
	class Program
	{
		static void Main ()
		{
			double r = double.Parse (Console.ReadLine ());
			Console.WriteLine ("{0:0.00} {1:0.00}", 2 * r * Math.PI, r * r * Math.PI);
		}
	}
}
