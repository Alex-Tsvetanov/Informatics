using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int num = int.Parse (Console.ReadLine ());
			if (num % 35 == 0)
				Console.WriteLine ("true {0}", num);
			else
				Console.WriteLine ("false {0}", num);
		}
	}
}
