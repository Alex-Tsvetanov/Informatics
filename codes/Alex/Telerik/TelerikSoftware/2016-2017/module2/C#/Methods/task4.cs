using System;

namespace Methods
{
	class Count
	{
		static int find (string[] arr, string val)
		{
			int br = 0;
			foreach (var item in arr)
			{
				if (item == val)
				{
					br ++;
				}
			}
			return br;
		}
		static int Main (string[] args)
		{
			Console.ReadLine ();
			Console.WriteLine ("{0}", find (Console.ReadLine ().Split (' '), Console.ReadLine ()));
			return 0;
		}	
	}
}

