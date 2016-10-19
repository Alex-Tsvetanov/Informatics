using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int y = int.Parse (Console.ReadLine ());
			y = y / 100 % 10;
			if (y == 7)
				Console.WriteLine ("true");
			else
				Console.WriteLine ("false {0}", y);
		}
	}
}
