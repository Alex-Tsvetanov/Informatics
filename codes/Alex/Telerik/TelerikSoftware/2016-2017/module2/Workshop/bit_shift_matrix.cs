using System;
using System.Numerics;

namespace Project
{
	class Program
	{
		static void Main (string[] args)
		{
			int r, c, coef;
			r = int.Parse (Console.ReadLine ());
			c = int.Parse (Console.ReadLine ());
			
			BigInteger[,] table = new BigInteger [r, c];
			BigInteger pow = 1;
			for (int i = 0 ; i < r + c ; i = i + 1, pow = pow * 2)
			{
				for (int x = 0 ; x <= i ; x ++)
				{
					int y = i - x;
					if (y < r && x < c && 0 <= y && 0 <= x)
						table [y, x] = pow;
				}
			}

			coef = Math.Max (r, c);
			
			Console.ReadLine ();
			var arr = Console.ReadLine ().Split (' ');

			int curr_row = 0, curr_col = 0;
			BigInteger sum = 0;
			foreach (var item in arr)
			{
				int cell = int.Parse (item);

				int y = r - 1 - cell / coef;
				int x = cell % coef;
				//Console.WriteLine ("ITEM: ({0}, {1})" , y, x);

				if (curr_col <= x)
				{
					for ( ; curr_col <= x ; curr_col ++)
					{
						sum += table [curr_row, curr_col];
						//Console.WriteLine ("({0}, {1}) = {2}", curr_row, curr_col, table [curr_row, curr_col]);
						table [curr_row, curr_col] = 0;
					}

					curr_col --;
				}
				else
				{
					for ( ; curr_col >= x ; curr_col --)
					{
						sum += table [curr_row, curr_col];
						//Console.WriteLine ("({0}, {1}) = {2}", curr_row, curr_col, table [curr_row, curr_col]);
						table [curr_row, curr_col] = 0;
					}

					curr_col ++;
				}


				if (curr_row <= y)
				{
					curr_row ++;

					for ( ; curr_row <= y ; curr_row ++)
					{
						sum += table [curr_row, curr_col];
						//Console.WriteLine ("({0}, {1}) = {2}", curr_row, curr_col, table [curr_row, curr_col]);
						table [curr_row, curr_col] = 0;
					}

					curr_row --;
				}
				else
				{
					curr_row --;

					for ( ; curr_row >= y ; curr_row --)
					{
						sum += table [curr_row, curr_col];
						//Console.WriteLine ("({0}, {1}) = {2}", curr_row, curr_col, table [curr_row, curr_col]);
						table [curr_row, curr_col] = 0;
					}

					curr_row ++;
				}
			}

			Console.WriteLine (sum);
		}
	}
}
