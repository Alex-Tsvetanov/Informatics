using System;
using System.Collections.Generic;
 
class SequenceInMatrix
{
	static string[,] matrix;
	static int n, m;
    static void Main()
    {
		var line = Console.ReadLine ().Split (' ');
		n = int.Parse (line [0]);
		m = int.Parse (line [1]);

		matrix = new string [n, m];

		for (int i = 0; i < n; i++)
		{
			line = Console.ReadLine ().Split (' ');
			for (int j = 0; j < m; j++)
			{
				matrix [i, j] = (line [j]);
			}
		}
 
        int currentLength = 1;
        int bestLength = int.MinValue;
        for (int row = 0 ; row < n ; row ++)
        {
            for (int col = 0 ; col < m ; col ++)
            {
                currentLength = CheckVertical (row, col, matrix [row, col]);
				bestLength = Math.Max (currentLength, bestLength); 
                
				currentLength = CheckHorizontal(row, col, matrix[row, col]);
				bestLength = Math.Max (currentLength, bestLength); 

                currentLength = CheckDiagonal(row, col, matrix[row, col]);
				bestLength = Math.Max (currentLength, bestLength); 
            }
        }
 
        Console.WriteLine(bestLength);
    }
 
    private static int CheckDiagonal (int row, int col, string currentValue)
    {
        int currentLength = 1;
        for (int i = row, j = col ; i < n - 1 && j < m - 1 ; i ++, j ++)
        {
            if (matrix [i + 1, j + 1].Equals (currentValue))
            {
				currentLength ++;
            }
            else
            {
                break;
            }
        }
        return currentLength;
    }
 
    private static int CheckHorizontal (int row, int col, string currentValue)
    {
        int currentLength = 1;
        for (int i = col ; i < m - 1 ; i++)
        {
            if (matrix [row, i + 1].Equals (currentValue))
            {
                currentLength ++;
            }
            else
            {
                break;
            }
        }
        return currentLength;
    }
 
    private static int CheckVertical (int row, int col, string currentValue)
    {
        int currentLength = 1;
        for (int i = row; i < n - 1 ; i ++)
        {
            if (matrix [i + 1, col].Equals (currentValue))
            {
                currentLength ++;
            }
            else
            {
                break;
            }        
        }
        return currentLength;
    }
}
