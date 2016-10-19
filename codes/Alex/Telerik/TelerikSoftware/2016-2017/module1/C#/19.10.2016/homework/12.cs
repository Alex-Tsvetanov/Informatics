using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			Int64 x = Int64.Parse (Console.ReadLine ());
			byte p = byte.Parse (Console.ReadLine ());
			Console.WriteLine ("{0}", (((x & (1L << p)) == (1L << p))?1:0));
		}
	}
}
