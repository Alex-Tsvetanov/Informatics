using System;
using System.Collections.Generic;
using System.Linq;
using System.Text;
using System.Threading.Tasks;

namespace _04_Line_Inverter
{
    public class Program
    {
        private static bool[,] board;
        private static int inversionsCount;

        public static void Main()
        {
            int dimension = int.Parse(Console.ReadLine());
            board = new bool[dimension, dimension];
            for (var i = 0; i < dimension; i++)
            {
                string line = Console.ReadLine();
                for (var ii = 0; ii < dimension; ii++)
                {
                    if (line[ii] == 'B')
                    {
                        board[i, ii] = true;
                    }
                }
            }
            inversionsCount = 0;

            int blackCellsInFirstRow = 0;
            int blackCellsInFirstCol = 0;
            for (var col = 0; col < dimension; col++)
            {
                if (board[0, col])
                {
                    blackCellsInFirstRow++;
                }
            }
            for (var row = 0; row < dimension; row++)
            {
                if (board[row, 0])
                {
                    blackCellsInFirstCol++;
                }
            }

            if (blackCellsInFirstRow > blackCellsInFirstCol)
            {
                // check rows for necessary inversions
                for (var col = 0; col < dimension; col++)
                {
                    if (board[0, col] == true)
                    {
                        continue;
                    }
                    else
                    {
                        InvertCol(board, col);
                    }
                }

                // check cols for necessary inversions
                for (var row = 0; row < dimension; row++)
                {
                    if (board[row, 0] == true)
                    {
                        continue;
                    }
                    else
                    {
                        InvertRow(board, row);
                    }
                }
            }
            else
            {
                // check rows for necessary inversions
                for (var row = 0; row < dimension; row++)
                {
                    if (board[row, 0] == true)
                    {
                        continue;
                    }
                    else
                    {
                        InvertRow(board, row);
                    }
                }

                // check cols for necessary inversions
                for (var col = 0; col < dimension; col++)
                {
                    if (board[0, col] == true)
                    {
                        continue;
                    }
                    else
                    {
                        InvertCol(board, col);
                    }
                }
            }

            // check if board is all black
            bool allBlack = true;
            for (var i = 0; i < dimension; i++)
            {
                for (var ii = 0; ii < dimension; ii++)
                {
                    if (!board[i, ii])
                    {
                        allBlack = false;
                        break;
                    }
                }
            }

            if (allBlack)
            {
                Console.WriteLine(inversionsCount);
            }
            else
            {
                Console.WriteLine("-1");
            }
        }

        private static void InvertRow(bool[,] board, int row)
        {
            for (var i = 0; i < board.GetLength(1); i++)
            {
                board[row, i] = !board[row, i];
            }
            inversionsCount++;
        }

        private static void InvertCol(bool[,] board, int col)
        {
            for (var i = 0; i < board.GetLength(0); i++)
            {
                board[i, col] = !board[i, col];
            }
            inversionsCount++;
        }
    }
}
