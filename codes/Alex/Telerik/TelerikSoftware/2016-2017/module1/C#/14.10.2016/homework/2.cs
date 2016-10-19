using System;

namespace Homework
{
	class MainProgram
	{
		public static void Main (string[] argvs)
		{
			double a = double.Parse(Console.ReadLine());
			double b = double.Parse(Console.ReadLine());
			double eps = 0.000001;
			if (Math.Abs (a - b) > eps)
				Console.WriteLine ("false");
			else 
				Console.WriteLine ("true");
		}
	}
}
