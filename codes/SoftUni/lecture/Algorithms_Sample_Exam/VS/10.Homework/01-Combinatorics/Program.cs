using System;
using System.Text;
using System.Collections.Generic;

namespace _01_Combinatorics
{
    public class Program
    {
        public static string letters;
        public static bool[] busy;
        public static char[] unique;
        public static Dictionary<char, int> letterCounter;
        public static int uniqueCount;

        public static void Main()
        {
            string input = Console.ReadLine();
            InitProgram(input);

            List<char> currentCombination = new List<char>(uniqueCount);
            GetAllCombinations(currentCombination);
        }

        public static void InitProgram(string input)
        {
            letters = input;
            letterCounter = new Dictionary<char, int>();
            HashSet<char> uniqueSet = new HashSet<char>();
            foreach (char letter in letters)
            {
                uniqueSet.Add(letter);
                if (!letterCounter.ContainsKey(letter))
                {
                    letterCounter.Add(letter, 0);
                }
                letterCounter[letter]++;
            }

            uniqueCount = uniqueSet.Count;
            unique = new char[uniqueCount];
            uniqueSet.CopyTo(unique);

            busy = new bool[uniqueCount];
        }

        public static void GetAllCombinations(List<char> currentCombination)
        {
            if (currentCombination.Count >= uniqueCount)
            {
                AddResult(currentCombination);
            }
            else
            {
                for (var i = 0; i < uniqueCount; i++)
                {
                    if (!busy[i])
                    {
                        busy[i] = true;
                        currentCombination.Add(unique[i]);
                        GetAllCombinations(currentCombination);
                        busy[i] = false;
                        currentCombination.RemoveAt(currentCombination.Count - 1);
                    }
                }
            }
        }

        private static void AddResult(List<char> currentCombination)
        {
            StringBuilder combination = new StringBuilder();
            for (var i = 0; i < currentCombination.Count; i++)
            {
                combination.Append(new string(currentCombination[i], letterCounter[currentCombination[i]]));
            }
            Console.WriteLine(combination.ToString());
        }
    }
}

