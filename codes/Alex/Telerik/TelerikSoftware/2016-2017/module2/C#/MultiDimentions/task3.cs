using System;

namespace MultiDimentions
{
	class SequenceInMatrix
	{
		static void Main()
		{
			string[] inputArr = Console.ReadLine().Split(' ');

			int n = int.Parse (inputArr[0]);
			int m = int.Parse (inputArr[1]);

			int[,] arr = new int [n, m];

			for (int i = 0; i < n; i++)
			{
				string[] strInput = Console.ReadLine().Split();
				for (int j = 0; j < m; j++)
				{
					arr[i, j] = int.Parse(strInput[j]);
				}

			}

			int horizontalMax = HorizontalMove(arr, n, m);
			int verticalMax = VerticalMove(arr, n, m);
			int diagonalMax = DiagonalMove(arr, n, m);

			Console.WriteLine(Math.Max(horizontalMax, Math.Max(verticalMax, diagonalMax)));
		}

		public static int HorizontalMove(int[,] arr, int n, int m)
		{
			int count = 1;
			int result = 0;

			for (int i = 0; i < n; i++)
			{
				for (int j = 0; j < m - 1; j++)
				{
					if (arr[i, j + 1] == arr[i, j])
					{
						count++;
					}
				}
				if (count > result)
				{
					result = count;
				}
				count = 1;
			}
			return result;
		}
		
		public static int VerticalMove(int[,] arr, int n, int m)
		{
			int count = 1;
			int result = 0;

			for (int i = 0; i < m; i++)
			{
				for (int j = 0; j < n - 1; j++)
				{
					if (arr[j + 1, i] == arr[j, i])
					{
						count++;
					}
				}
				if (count > result)
				{
					result = count;
				}
				count = 1;
			}
			return result;
		}

		public static int DiagonalMove(int[,] arr, int n, int m)
		{
			int count = 1;
			int result = 0;

			//BOOTOM LEFT
			int row = n - 2; //6-2 = 4
			int col = 0;

			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < i + 1 && j< m-1; j++)
				{
					if (arr[row + j, col + j] == arr[row + j + 1, col + j + 1])
					{
						count++;
					}
				}
				if (count > result)
				{
					result = count;
				}
				count = 1;
				row--;
			}
			//TOP RIGHT
			col = m - 2; //6-2 =4
			row = 0;
			for (int i = 0; i < m - 2; i++)
			{
				for (int j = 0; j < i + 1 && j<n-1; j++)
				{
					if (arr[row + j, col + j] == arr[row + j + 1, col + j + 1])
					{
						count++;
					}
				}
				if (count > result)
				{
					result = count;
				}
				count = 1;
				col--;
			}

			//BOTTOM RIGHT
			row = n - 2;
			col = m - 1;

			for (int i = 0; i < n - 1; i++)
			{
				for (int j = 0; j < i + 1 && j < m - 1; j++)
				{
					if (arr[row + j, col - j] == arr[row + j + 1, col - j - 1])
					{
						count++;
					}
				}
				if (count > result)
				{
					result = count;
				}
				count = 1;
				row--;
			}
			//TOP LEFT
			col = 1;
			row = 0;
			for (int i = 0; i < m - 2; i++)
			{
				for (int j = 0; j < i + 1 && j < n - 1; j++)
				{
					if (arr[row + j, col - j] == arr[row + j + 1, col - j - 1])
					{
						count++;
					}
				}
				if (count > result)
				{
					result = count;
				}
				count = 1;
				col++;
			}
			return result;
		}
	}
}
