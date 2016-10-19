using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			double x = double.Parse (Console.ReadLine ());
			double y = double.Parse (Console.ReadLine ());
			bool k = ((x - 1) * (x - 1) + (y - 1) * (y - 1)) <= 2.25f;
			bool r = (-1 <= x && x <= 5 && -1 <= y && y <= 1);
			string ks, rs;

			if (k) ks = "in";
			else   ks = "out";
			if (r) rs = "in";
			else   rs = "out";
			Console.WriteLine ("{0}side circle {1}side rectangle", ks, rs);
		}
	}
}
