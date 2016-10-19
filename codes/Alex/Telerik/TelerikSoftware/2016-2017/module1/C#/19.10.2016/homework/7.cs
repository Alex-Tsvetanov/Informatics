using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			double x = double.Parse (Console.ReadLine ());
			double y = double.Parse (Console.ReadLine ());
			double dist = x * x + y * y;
			if (dist <= 4)
				Console.WriteLine ("yes {0:0.00}", Math.Sqrt (dist));
			else 
				Console.WriteLine ("no {0:0.00}", Math.Sqrt (dist));
		}
	}
}
