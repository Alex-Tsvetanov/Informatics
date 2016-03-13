using System;
using System.Collections.Generic;

class LongestCommonSubsequence
{
	const int NOT_CALCULATED = -1;

	static string firstStr;
	static string secondStr;
	static int[,] lcs;

	static void Main()
	{
		string input = Console.ReadLine ();
		while (input.Split (new char[] {' ', '\t'}, 2).Length < 2) {
			input += Console.ReadLine ();
		}
		string[] inputStr = input.Split (new char[] {' ', '\t'}, 2);
		firstStr = inputStr [0];
		secondStr = inputStr [1];
		lcs = new int [firstStr.Length, secondStr.Length];
		init();
		calc(firstStr.Length - 1, secondStr.Length - 1);		
		print(firstStr.Length - 1, secondStr.Length - 1);
	}

	static void init()
	{
		for (int x = 0; x < firstStr.Length; x++)
		{
			for (int y = 0; y < secondStr.Length; y++)
			{
				lcs[x, y] = NOT_CALCULATED;
			}
		}
	}

	static int calc(int x, int y)
	{
		if (x < 0 || y < 0)
		{
			return 0;
		}

		if (lcs[x, y] == NOT_CALCULATED)
		{
			int lcsFirstMinusOne = calc(x - 1, y);
			int lcsSecondMinusOne = calc(x, y - 1);
			lcs[x, y] = Math.Max(lcsFirstMinusOne, lcsSecondMinusOne);
			if (firstStr[x] == secondStr[y])
			{
				int lcsBothMinusOne = 1 + calc(x - 1, y - 1);
				lcs[x, y] = Math.Max(lcs[x, y], lcsBothMinusOne);
			}
		}

		return lcs[x, y];
	}

	static void print(int x, int y)
	{
		Console.WriteLine("LCS = " + calc(x, y));

		List<char> lcsLetters = new List<char>();
		while (x >= 0 && y >= 0)
		{
			if ((firstStr[x] == secondStr[y]) &&
				(calc(x - 1, y - 1) + 1 == lcs[x, y]))
			{
				lcsLetters.Add(firstStr[x]);
				x--;
				y--;
			}
			else if (calc(x - 1, y) == lcs[x, y])
			{
				x--;
			}
			else
			{
				y--;
			}
		}
		lcsLetters.Reverse();
		string lcsStr = String.Join ("", lcsLetters);
		Console.WriteLine(lcsStr);
	}
}