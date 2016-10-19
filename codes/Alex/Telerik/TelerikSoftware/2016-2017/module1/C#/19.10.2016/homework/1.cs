using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int num = int.Parse (Console.ReadLine ());
			if (num % 2 == 0)
				Console.WriteLine ("even {0}", num);
			else if (num % 2 == 1)
				Console.WriteLine ("odd {0}", num);
			else
			{
				if ((-num) % 2 == 0)
					Console.WriteLine ("even {0}", num);
				else if ((-num) % 2 == 1)
					Console.WriteLine ("odd {0}", num);
			}
		}
	}
}
