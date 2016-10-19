using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			double x = double.Parse (Console.ReadLine ());
			double y = double.Parse (Console.ReadLine ());
			double z = double.Parse (Console.ReadLine ());
			Console.WriteLine ("{0:0.0000000}", (x + y) * z / 2);
		}
	}
}
