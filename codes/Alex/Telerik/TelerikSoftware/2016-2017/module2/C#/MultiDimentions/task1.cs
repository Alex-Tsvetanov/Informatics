using System;

class Program
{
	public static int[,] table = new int [256,256];
	
	public static int Main (string[] args)
	{
		int n = int.Parse (Console.ReadLine ());
		char c = char.Parse (Console.ReadLine ());

		if (c == 'a')
		{
			int num = 1;
			for (int x = 0 ; x < n ; x ++)
			{
				for (int y = 0 ; y < n ; y ++)
				{
					table [y, x] = num ++;
				}
			}
		}
		if (c == 'b')
		{
			int num = 1;
			for (int x = 0 ; x < n ; x ++)
			{
				if (x % 2 == 0)
				for (int y = 0 ; y < n ; y ++)
				{
					table [y, x] = num ++;
				}
				if (x % 2 == 1)
				for (int y = n - 1 ; y >= 0 ; y --)
				{
					table [y, x] = num ++;
				}
			}
		}
		if (c == 'c')
		{
			int n2 = n * n;
			int x = 0;
			int y = 0;
			for (int i = 0 ; i < n2 ; i ++) 
			{
				table [x, y] = i + 1;
				if (y <= 0 || x + 1 >= n)
				{
					y = x + y + 1;
					if (y >= n) 
					{
						x = (y - n) + 1;
						y -= x;
					}
					else
					{
						x = 0;
					}
				}
				else
				{
					x ++;
					y --;
				}
			}

			for (x = n - 1 ; x >= 0 ; x --)
			{
				for (y = 0 ; y < n - 1 ; y ++)
				{
					Console.Write ("{0} ", table [y, x]);
				}
				Console.Write ("{0}", table [n - 1, x]);
				Console.WriteLine ();
			}
			return 0;
		}
		if (c == 'd')
		{
			int row = 0;
			int col = 0;
			string direction = "right";
			int maxRotations = n * n;

			for (int i = 1; i <= maxRotations; i++)
			{
				if (direction == "right" && (col > n - 1 || table[row, col] != 0))
				{
					direction = "down";
					col--;
					row++;
				}
				if (direction == "down" && (row > n - 1 || table[row, col] != 0))
				{
					direction = "left";
					row--;
					col--;
				}
				if (direction == "left" && (col < 0 || table[row, col] != 0))
				{
					direction = "up";
					col++;
					row--;
				}

				if (direction == "up" && row < 0 || table[row, col] != 0)
				{
					direction = "right";
					row++;
					col++;
				}

				table[row, col] = i;

				if (direction == "right")
				{
					col++;
				}
				if (direction == "down")
				{
					row++;
				}
				if (direction == "left")
				{
					col--;
				}
				if (direction == "up")
				{
					row--;
				}
			}

			for (int x = 0 ; x < n ; x ++)
			{
				for (int y = 0 ; y < n - 1 ; y ++)
				{
					Console.Write ("{0} ", table [y, x]);
				}
				Console.Write ("{0}", table [n - 1, x]);
				Console.WriteLine ();
			}
			return 0;
		}

		for (int x = 0 ; x < n ; x ++)
		{
			for (int y = 0 ; y < n - 1 ; y ++)
			{
				Console.Write ("{0} ", table [x, y]);
			}
			Console.Write ("{0}", table [x, n - 1]);
			Console.WriteLine ();
		}
		return 0;
	}
}
