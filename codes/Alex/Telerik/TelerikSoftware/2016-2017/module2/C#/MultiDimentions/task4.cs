using System;

class Depth_First_Search
{
    public static void Main(string[] args)
    {
		var line = Console.ReadLine ().Split (' ');
		int n = int.Parse (line [0]);
		int m = int.Parse (line [1]);

        int[,] array = new int [n, m];

		for (int i = 0; i < n; i++)
		{
			line = Console.ReadLine ().Split (' ');
			for (int j = 0; j < m; j++)
			{
				array [i, j] = int.Parse (line [j]);
			}
		}
        bool[,] calculated = new bool[array.GetLength(0), array.GetLength(1)];
        int bestCount = 0;
        for (int row = 0; row < array.GetLength(0); row++)
        {
            for (int col = 0; col < array.GetLength(1); col++)
            {
                if (!calculated[row, col])
                {
                    int count = DepthFirstSearch(array, row, col, calculated);
                    if (bestCount < count)
                    {
                        bestCount = count;
                    }
                }

            }
        }
        Console.WriteLine("{0}", bestCount);
    }

    static int DepthFirstSearch(int[,] array, int row, int col, bool[,] calc)
    {
        int result = 1;
        calc[row, col] = true;
        if ((row - 1 >= 0) && (array[row - 1, col] == array[row, col]) && !calc[row - 1, col])
        {
            result += DepthFirstSearch(array, row - 1, col, calc);
        }
        if ((row + 1 < array.GetLength(0)) && (array[row + 1, col] == array[row, col]) && !calc[row + 1, col])
        {
            result += DepthFirstSearch(array, row + 1, col, calc);
        }
        if ((col - 1 >= 0) && (array[row, col - 1] == array[row, col]) && !calc[row, col - 1])
        {
            result += DepthFirstSearch(array, row, col - 1, calc);
        }
        if ((col + 1 < array.GetLength(1)) && (array[row, col + 1] == array[row, col]) && !calc[row, col + 1])
        {
            result += DepthFirstSearch(array, row, col + 1, calc);
        }
        return result;
    }
}
