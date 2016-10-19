using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int x = int.Parse (Console.ReadLine ());
			Console.WriteLine ("{0}", (((x & (1 << 3)) == 8)?1:0));
		}
	}
}
