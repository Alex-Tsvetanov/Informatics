using System;
using System.Numerics;
using System.Collections.Generic;

namespace Project
{
	class Program
	{
		static Dictionary<string, int> digits = new Dictionary<string, int>
		{
			{"cad", 0},
			{"xoz", 1},
			{"nop", 2},
			{"cyk", 3},
			{"min", 4},
			{"mar", 5},
			{"kon", 6},
			{"iva", 7},
			{"ogi", 8},
			{"yan", 9},
		};

		static Dictionary<int, string> word = new Dictionary<int, string>
		{
			{0,"cad"},
			{1,"xoz"},
			{2,"nop"},
			{3,"cyk"},
			{4,"min"},
			{5,"mar"},
			{6,"kon"},
			{7,"iva"},
			{8,"ogi"},
			{9,"yan"},
		};

		static BigInteger Parser (string a)
		{
			BigInteger res = 0;
			for (int i = 0 ; i < a.Length ; i += 3)
			{
				res = res * 10 + digits [a.Substring (i, 3)];
			}
			return res;
		}

		static string Parser (BigInteger a)
		{
			string res = "";
			while (a > 0)
			{
				res = word [(int)(a % 10)] + res;
				a /= 10;
			}
			return res;
		}

		static void Main (string[] argv)
		{
			string a = Console.ReadLine ();
			char op = char.Parse (Console.ReadLine ());
			string b = Console.ReadLine ();

			BigInteger _a = Parser (a);
			BigInteger _b = Parser (b);
			BigInteger _c = _a + _b;
			if (op == '-')
				_c = _a - _b;
			//Console.WriteLine (_a);
			//Console.WriteLine (_b);
			//Console.WriteLine (_c);
			Console.WriteLine (Parser (_c));
		}
	}
}
