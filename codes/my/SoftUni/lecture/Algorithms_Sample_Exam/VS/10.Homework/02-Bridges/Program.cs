using System;
using System.Collections.Generic;

namespace _02_Bridges
{
    public class Program
    {
        private static int[] north;
        private static int[] south;
        private static int[,] matrix;
        private static int pathsCount;

        public static void Main()
        {
            north = ReadIntegerSequence();
            south = ReadIntegerSequence();
            pathsCount = 0;

            ConstructLCSMatrix();

            pathsCount = matrix[south.Length, north.Length];
            Console.WriteLine(pathsCount);
        }

        private static void ConstructLCSMatrix()
        {
            matrix = new int[south.Length + 1, north.Length + 1];
            for (var row = 0; row < matrix.GetLength(0); row++)
            {
                for (var col = 0; col < matrix.GetLength(1); col++)
                {
                    if (row == 0 || col == 0)
                    {
                        matrix[row, col] = 0;
                    }
                    else if (north[col - 1].Equals(south[row - 1]))
                    {
                        int maxValue = Math.Max(matrix[row - 1, col], matrix[row, col - 1]);
                        matrix[row, col] = maxValue + 1;
                    }
                    else
                    {
                        matrix[row, col] = Math.Max(matrix[row - 1, col], matrix[row, col - 1]);
                    }
                }
            }
        }

        private static int[] ReadIntegerSequence()
        {
            string input = Console.ReadLine();
            string[] inputs = input.Split(' ');
            int[] sequence = new int[inputs.Length];
            for (var i = 0; i < sequence.Length; i++)
            {
                sequence[i] = int.Parse(inputs[i]);
            }
            return sequence;
        }
    }
}
