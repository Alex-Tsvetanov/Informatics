using System;

public class MaxPlatform
{
    static void Main()
    {
        // Declare and initialize the matrix
		var line1 = Console.ReadLine ().Split (' ');
		int n = int.Parse (line1 [0]);
		int m = int.Parse (line1 [1]);
        int[,] matrix = new int [n, m];
        for (int row = 0 ; row < matrix.GetLength (0) ; row ++)
        {
			var line = Console.ReadLine ().Split (' ');
            for (int col = 0 ; col < matrix.GetLength (1) ; col ++)
            {
				matrix [row, col] = int.Parse (line [col]);
			}
		}

        // Find the maximal sum platform of size 2 x 2
        int bestSum = int.MinValue;
        for (int row = 0; row < matrix.GetLength(0) - 2; row++)
        {
            for (int col = 0; col < matrix.GetLength(1) - 2; col++)
            {
                int sum = matrix [row + 0, col] + matrix [row + 0, col + 1] + matrix [row + 0, col + 2] + 
                          matrix [row + 1, col] + matrix [row + 1, col + 1] + matrix [row + 1, col + 2] + 
                          matrix [row + 2, col] + matrix [row + 2, col + 1] + matrix [row + 2, col + 2] + 
					      0;
                if (sum > bestSum)
                {
                    bestSum = sum;
                }
            }
        }

        // Print the result
        Console.WriteLine ("{0}", bestSum);
    }
}
