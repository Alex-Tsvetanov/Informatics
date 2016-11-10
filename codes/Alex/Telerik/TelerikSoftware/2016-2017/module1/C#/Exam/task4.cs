using System;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int n = int.Parse (Console.ReadLine ());
			int prev = int.Parse (Console.ReadLine ());;
			int[] array_merge = new int [n - 1];
			int[] array_sum = new int [n - 1];
			for (int i = 1 ; i < n ; i ++)
			{
				int curr = int.Parse (Console.ReadLine ());
				array_merge [i - 1] = (prev % 10) * 10 + (curr / 10);
				array_sum [i - 1] = (prev) + (curr);
				prev = curr;
			}

			Console.WriteLine(String.Join(" ", array_merge));
			Console.WriteLine(String.Join(" ", array_sum));
		}
	}
}
