using System;
using System.Numerics;

namespace Project
{
	class Program
	{
		public static decimal fact (int n)
		{
			return ((n <= 1) ? 1 : ((fact (n - 1)) * n));
		}

		public static void Main (string[] args)
		{
			int n, k, p;
			string inp = Console.ReadLine ();
			n = int.Parse (inp.Split (' ')[0]);
			k = int.Parse (inp.Split (' ')[1]);
			p = int.Parse (inp.Split (' ')[2]);
			Console.WriteLine ((fact (n) / (fact (k) * fact (n - k))) * (decimal)Math.Pow ((p / 100), k));
		}
	}
}
