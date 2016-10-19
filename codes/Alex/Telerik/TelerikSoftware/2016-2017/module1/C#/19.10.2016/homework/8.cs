using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int x = int.Parse (Console.ReadLine ());
			if (x < 2)
			{
				Console.WriteLine ("false");
				return;
			}
			for (int i = 2 ; i * i <= x ; i ++)
			{
				if (x % i == 0)
				{
					Console.WriteLine ("false");
					return;
				}
			}
			Console.WriteLine ("true");
			return;
		}
	}
}
