using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			double num = double.Parse (Console.ReadLine ());
			Console.WriteLine ("{0:0.000}", num * 17.0f / 100.0f);
		}
	}
}
