using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			string digits = Console.ReadLine ();
			int a = digits [0] - '0';
			int b = digits [1] - '0';
			int c = digits [2] - '0';
			if (b % 2 == 0)
			{
				float s = (float)(a + b) * c;
				Console.WriteLine ("{0:0.00}", s);
			}
			else
			{
				float s = (float)(a * b) / c;
				Console.WriteLine ("{0:0.00}", s);
			}
		}
	}
}
