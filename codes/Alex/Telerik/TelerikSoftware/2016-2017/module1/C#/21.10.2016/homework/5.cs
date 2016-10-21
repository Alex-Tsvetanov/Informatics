using System;

namespace Project
{
	class Program
	{
		static void Main ()
		{
			double a = double.Parse (Console.ReadLine ());
			double b = double.Parse (Console.ReadLine ());
			double c = double.Parse (Console.ReadLine ());
			double D = b * b - 4 * a * c;
			if (D < 0)
				Console.WriteLine ("no real roots");
			else if (Math.Abs (D) < 0.01)
				Console.WriteLine ("{0:0.00}", (-b)/2/a);
			else
				Console.WriteLine ("{0:0.00}\n{1:0.00}", ((-b) - Math.Sqrt (D))/2/a, ((-b) + Math.Sqrt (D))/2/a);
		}
	}
}
