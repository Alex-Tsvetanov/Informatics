using System;

namespace Methods
{
	class LargerThan
	{
		static int Main (string[] args)
		{
			var arr1 = Console.ReadLine ().Split (' ');
			int min = int.MaxValue;
			int max = int.MinValue;
			int sum = 0;
			//BigInteger;
			int product = 1;

			for (int i = 0 ; i < arr1.Length ; i ++)
			{
				min = Math.Min (min, int.Parse (arr1 [i]));
				max = Math.Max (max, int.Parse (arr1 [i]));
				sum += (int.Parse (arr1 [i]));
				product *= (int.Parse (arr1 [i]));
			}
			Console.WriteLine ("{0}\n{1}\n{2:0.00}\n{3}\n{4}", min, max, (double)sum / arr1.Length, sum, product);
			return 0;
		}	
	}
}

