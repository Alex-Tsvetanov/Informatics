using System;
using System.Collections.Generic;

namespace _02_Bridges_v2
{
    public class Program
    {
        private static int[] north;
        private static int[] south;
        private static int pathsCount;

        public static void Main()
        {
            north = ReadIntegerSequence();
            south = ReadIntegerSequence();
            pathsCount = 0;

            int indexN = north.Length - 1;
            int indexS = south.Length - 1;

            pathsCount = Mach(indexN, indexS);

            Console.WriteLine(pathsCount);
        }

        private static int Mach(int indexN, int indexS)
        {
            if (indexN == 0 && indexS == 0)
            {
                if (north[indexN] == south[indexS])
                {
                    return 1;
                }
                else
                {
                    return 0;
                }
            }
            else if (indexN == 0)
            {
                if (north[indexN] == south[indexS])
                {
                    return Mach(indexN, indexS - 1) + 1;
                }
                else
                {
                    return Mach(indexN, indexS - 1);
                }
            }
            else if (indexS == 0)
            {
                if (north[indexN] == south[indexS])
                {
                    return Mach(indexN - 1, indexS) + 1;
                }
                else
                {
                    return Mach(indexN - 1, indexS);
                }
            }
            else if (north[indexN] == south[indexS])
            {
                return Math.Max(
                    Mach(indexN - 1, indexS) + 1,
                    Mach(indexN, indexS - 1) + 1
                );
            }
            else
            {
                return Math.Max(
                    Mach(indexN - 1, indexS),
                    Mach(indexN, indexS - 1)
                );
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
